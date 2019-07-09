/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_time.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 18:32:38 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/09 18:33:06 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

#include "viz.h"

long	gfx_get_current_epoch(void)
{
	long			ns;
	time_t			s;
	struct timespec	spec;

	clock_gettime(CLOCK_REALTIME, &spec);
	s = spec.tv_sec;
	ns = spec.tv_nsec;
	return (s * 1000 + ns / 1000000);
}
