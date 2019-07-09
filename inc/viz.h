/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   viz.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 14:08:55 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/09 22:53:37 by nmartins      ########   odam.nl         */
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

	int				length;
	int				inst_count;
	TTF_Font		*font;
}				t_state;

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_rgb
{
	int r;
	int g;
	int b;
}				t_rgb;

typedef struct	s_hsl
{
	double	h;
	double	s;
	double	l;
}				t_hsl;

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
void		gfx_rectangle(t_state *this, t_point a, t_point b, int color);
t_rgb		gfx_hsl2rgb(t_hsl hsl);
int			gfx_color_from_rgb(t_rgb rgb);

#endif
