/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   viz.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/08 19:05:50 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/10 12:57:16 by nmartins      ########   odam.nl         */
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
	SDL_SetSurfaceBlendMode(this->screen_surface, SDL_BLENDMODE_BLEND);
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

int			find_index(int i, t_stack **a, t_stack **b)
{
	int		index;
	t_stack	*walker;

	index = 0;
	walker = *a;
	while (walker)
	{
		if (walker->head < i)
			index++;
		walker = walker->tail;
	}	
	walker = *b;
	while (walker)
	{
		if (walker->head < i)
			index++;
		walker = walker->tail;
	}	
	return (index);
}

void		gfx_show_stack(t_state *this, t_stack **stack, int offset, int padding)
{
	t_stack	*walker;
	int		i;
	double	perc;
	double	step;
	int		color;

	step = (double)(this->height - padding * 2) / (double)this->length;
	i = 0;
	walker = *stack;
	while (walker)
	{
		perc = (find_index(walker->head, this->machine->a, this->machine->b) + 1) / (double)this->length;
		color = gfx_color_from_rgb(gfx_hsl2rgb((t_hsl){
			.h = perc * 360.0,
			.s = 0.5,
			.l = 0.5
		}));
		gfx_rectangle(this, (t_point){offset, padding + step * i},
			(t_point){perc * (this->width - padding * 2) / 2, step + 1}, color);
		walker = walker->tail;
		i++;
	}
}

void		state_update(t_state *this)
{
	char			*line;
	t_instruction	inst;
	size_t			times;

	if (this->speed < 0)
		times = -this->speed;
	else
		times = 1;
	while (times)
	{
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
		this->inst_count++;
		times--;
	}
}

void		state_run(t_state *this)
{
	const int	padding = 50;
	ft_memset(this->screen_surface->pixels, 0,
		this->screen_surface->w * this->screen_surface->h * 4);
	gfx_frame(this, padding);
	gfx_show_stack(this, this->machine->a, padding, padding);
	gfx_show_stack(this, this->machine->b, this->width / 2, padding);
	SDL_UpdateWindowSurface(this->window);
}

void		state_loop(t_state *this)
{
	SDL_Event		evt;
	static long		last_tick;
	int				sp;

	sp = this->speed > 0 ? this->speed : 1;
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
		if (last_tick == 0)
			sleep(1);
		if (last_tick + sp < gfx_get_current_epoch())
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

	if (argc != 3)
	{
		ft_printf("Usage: %s <list of numbers> <speed>\n", argv[0]);
		exit(1);
	}
	a = NULL;
	b = NULL;
	machine.a = &a;
	machine.b = &b;
	machine_init(&machine, argv[1]);
	st.width = 1280;
	st.inst_count = 0;
	st.length = stack_length(machine.a);
	st.speed = ft_atoi(argv[2]);
	st.height = 720;
	st.machine = &machine;
	state_init(&st);
	state_loop(&st);
	return (0);
}
