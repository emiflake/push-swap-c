/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo_helper_rotation.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 21:32:08 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/01 21:59:36 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
#include "dsl.h"


void	algo_rotate_to_index_a(t_machine *machine, t_history **result_history, size_t index)
{
	size_t	length;

	length = stack_length(machine->a);
	(void)length;
	while (index > 0)
	{
		do_inst(machine, result_history, ROTATE_A);
		index--;
	}
}