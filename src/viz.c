/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   viz.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/08 19:05:50 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/09 18:49:30 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <get_next_line.h>
#include <unistd.h>
#include <stdlib.h>
#include <libft.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_pixels.h>

#include "machine.h"
#include "stack.h"
#include "instruction.h"
#include "viz.h"

void		state_init(t_state *this)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		ft_printf("Unable to initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}
	ft_printf("Successfully initalized SDL with Video\n");
	this->window = SDL_CreateWindow("- Push Swap -",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		this->width, this->height,
		SDL_WINDOW_SHOWN);
	if (!this->window)
	{
		ft_printf("Unable to create SDL window: %s\n", SDL_GetError());
		exit(1);
	}
	this->screen_surface = SDL_GetWindowSurface(this->window);
	if (!this->screen_surface)
	{
		ft_printf("Unable to get screen surface: %s\n", SDL_GetError());
		exit(1);
	}
	if (TTF_Init())
	{
		ft_printf("Unable to initialize TTF: %s\n", TTF_GetError());
		exit(1);
	}
	this->renderer = SDL_CreateRenderer(this->window, -1, 0);
	this->running = 1;
	this->font = TTF_OpenFont("ShareTechMono-Regular.ttf", 20);
	if (!this->font)
	{
		ft_printf("Failed to load font: %s\n", SDL_GetError());
		exit(1);
	}
}

void	machine_init(t_machine *machine, char *stack_str)
{
	stack_parse(machine->a, stack_str);
}

void		gfx_frame(t_state *this, int pad)
{
	gfx_line(this->screen_surface, (t_point){pad, pad},
		(t_point){this->width - pad, pad}, 0xFFFFFF);
	gfx_line(this->screen_surface, (t_point){pad, this->height - pad},
		(t_point){this->width - pad, this->height - pad}, 0xFFFFFF);
	gfx_line(this->screen_surface, (t_point){pad, pad},
		(t_point){pad, this->height - pad}, 0xFFFFFF);
	gfx_line(this->screen_surface, (t_point){this->width - pad, pad},
		(t_point){this->width - pad, this->height - pad}, 0xFFFFFF);
	gfx_line(this->screen_surface, (t_point){this->width / 2, pad},
		(t_point){this->width / 2, this->height - pad}, 0xFFFFFF);
}

void		gfx_show_stack(t_state *this, t_stack **stack, int offset)
{
	t_stack	*walker;
	int		i;
	char	buf[100];

	i = 0;
	walker = *stack;
	while (walker)
	{
		ft_bzero(buf, 100);
		ft_snprintf(buf, 100, "<%d>", walker->head);
		gfx_text(this, this->screen_surface, (t_point){offset, offset + 20 * i}, buf);
		walker = walker->tail;
		i++;
	}
}

void		state_update(t_state *this)
{
	char			*line;
	t_instruction	inst;

	ft_get_next_line(0, &line);
	if (line == NULL)
		return ;
	inst = parse_instruction(line);
	if (inst == INVALID_INSTRUCTION)
	{
		ft_printf("Error: Invalid instruction\n");
		exit(2);
	}
	perform_instruction(this->machine, inst);
}

void		state_run(t_state *this)
{
	const int	padding = 50;
	ft_memset(this->screen_surface->pixels, 0,
		this->screen_surface->w * this->screen_surface->h * 4);
	gfx_text(this, this->screen_surface, (t_point){10, 10}, "Push Swap!");
	gfx_frame(this, padding);
	gfx_show_stack(this, this->machine->a, 50);
	gfx_show_stack(this, this->machine->b, this->width / 2 + 20);
	SDL_UpdateWindowSurface(this->window);
}

void		state_loop(t_state *this)
{
	SDL_Event		evt;
	static long		last_tick;

	while (this->running)
	{
		while (SDL_PollEvent(&evt))
		{
			if (evt.type == SDL_QUIT)
				this->running = 0;
			if (evt.type == SDL_KEYDOWN)
			{
				if (evt.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					this->running = 0;
			}
		}
		state_run(this);
		if (last_tick + 100 < gfx_get_current_epoch())
		{
			last_tick = gfx_get_current_epoch();
			state_update(this);
		}
	}
}

int			main(int argc, char **argv)
{
	t_state		st;
	t_machine	machine;
	t_stack		*a;
	t_stack		*b;

	if (argc != 2)
	{
		ft_printf("Usage: %s <list of numbers>\n", argv[0]);
		exit(1);
	}
	a = NULL;
	b = NULL;
	machine.a = &a;
	machine.b = &b;
	machine_init(&machine, argv[1]);
	st.width = 1280;
	st.height = 720;
	st.machine = &machine;
	state_init(&st);
	state_loop(&st);
	return (0);
}
