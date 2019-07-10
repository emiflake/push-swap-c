/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   history_optimize.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/11 00:19:04 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/11 00:32:28 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

t_history	*history_join(t_instruction a, t_instruction b)
{
	t_history	*new_hist;

	new_hist = (t_history*)malloc(sizeof(t_history));
	if (a == ROTATE_A && b == ROTATE_B)
	{
		new_hist->inst = ROTATE_BOTH;
	}
	else
	{
		return (NULL);
	}
	return (new_hist);
}
