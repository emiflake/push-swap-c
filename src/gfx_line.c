/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_line.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 14:15:58 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/09 22:17:22 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "viz.h"
#include <math.h>

static void	gfx_blit_pixel(SDL_Surface *trgt, int x, int y, int color)
{
	int *pixels_as_i32;

	pixels_as_i32 = trgt->pixels;
	if (x < 0 || x > trgt->w
		|| y < 0 || y > trgt->h)
		return ;
	pixels_as_i32[x + y * trgt->w] = color;
}

static void	gfx_line_bresenham_octant_low(
	SDL_Surface *trgt,
	t_point a,
	t_point b,
	int color)
{
	t_point	delta;
	t_point	p;
	int		derror;
	int		yi;

	delta.x = b.x - a.x;
	delta.y = b.y - a.y;
	yi = delta.y < 0 ? -1 : 1;
	delta.y = delta.y * yi;
	derror = 2 * delta.y - delta.x;
	p = (t_point){.x = a.x, .y = a.y};
	while (p.x < b.x)
	{
		gfx_blit_pixel(trgt, p.x, p.y, color);
		if (derror > 0)
		{
			p.y += yi;
			derror -= 2 * delta.x;
		}
		derror += 2 * delta.y;
		p.x++;
	}
}

static void	gfx_line_bresenham_octant_high(
	SDL_Surface *trgt,
	t_point a,
	t_point b,
	int color)
{
	t_point	delta;
	t_point	p;
	int		derror;
	int		xi;

	delta.x = b.x - a.x;
	delta.y = b.y - a.y;
	xi = delta.x < 0 ? -1 : 1;
	delta.x = delta.x * xi;
	derror = 2 * delta.x - delta.y;
	p = (t_point){.x = a.x, .y = a.y};
	while (p.y < b.y)
	{
		gfx_blit_pixel(trgt, p.x, p.y, color);
		if (derror > 0)
		{
			p.x += xi;
			derror -= 2 * delta.y;
		}
		derror += 2 * delta.x;
		p.y++;
	}
}

void		gfx_line(
	SDL_Surface *trgt,
	t_point a,
	t_point b,
	int color)
{
	if (abs(b.y - a.y) < abs(b.x - a.x))
	{
		if (a.x > b.x)
			gfx_line_bresenham_octant_low(trgt, b, a, color);
		else
			gfx_line_bresenham_octant_low(trgt, a, b, color);
	}
	else
	{
		if (a.y > b.y)
			gfx_line_bresenham_octant_high(trgt, b, a, color);
		else
			gfx_line_bresenham_octant_high(trgt, a, b, color);
	}
}

void		gfx_rectangle(t_state *this, t_point a, t_point b, int color)
{
	t_point c;

	c = a;
	while (c.y < b.y + a.y)
	{
		c.x = a.x;
		while (c.x < b.x + a.x)
		{
			gfx_blit_pixel(this->screen_surface, c.x, c.y, color);
			c.x++;
		}
		c.y++;
	}
}