/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_text.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 14:59:46 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/09 23:05:01 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include "viz.h"

void		gfx_text(
	t_state *st,
	SDL_Surface *trgt,
	t_point pos,
	char *text)
{
	SDL_Surface	*surf;
	SDL_Rect	render_quad;
	SDL_Rect	src_quad;
	t_point		dimensions;

	surf = TTF_RenderText_Solid(st->font, text,
		(SDL_Color){255, 255, 255, 255});
	if (!surf)
	{
		ft_printf("Failed to render text!\n");
		exit(0);
	}
	dimensions.x = surf->w;
	dimensions.y = surf->h;
	src_quad = (SDL_Rect){0, 0, dimensions.x, dimensions.y};
	render_quad = (SDL_Rect){pos.x, pos.y, dimensions.x, dimensions.y};
	SDL_BlitSurface(surf,
		NULL,
		trgt,
		&render_quad);
	SDL_FreeSurface(surf);
}
