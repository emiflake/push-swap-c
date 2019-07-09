/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   viz.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 14:08:55 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/09 18:33:21 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIZ_H
# define VIZ_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>
# include "machine.h"

typedef struct	s_state
{
	SDL_Window		*window;
	SDL_Surface		*screen_surface;
	SDL_Renderer	*renderer;

	int				running;

	int				width;
	int				height;

	t_machine		*machine;

	TTF_Font		*font;
}				t_state;

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

void		gfx_line(
	SDL_Surface *trgt,
	t_point a,
	t_point b,
	int color);

void		gfx_text(
	t_state *st,
	SDL_Surface *trgt,
	t_point pos,
	char *text);

long		gfx_get_current_epoch(void);

#endif
