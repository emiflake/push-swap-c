/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo_helper_rotation.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 21:32:08 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/10 14:22:49 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include "algo.h"
#include "dsl.h"

void	algo_rotate_a(
	t_machine *machine,
	t_history **result_history,
	int offset)
{
	if (offset < 0)
	{
		while (offset < 0)
		{
			do_inst(machine, result_history, REVERSE_ROTATE_A);
			offset++;
		}
	}
	else
	{
		while (offset > 0)
		{
			do_inst(machine, result_history, ROTATE_A);
			offset--;
		}
	}
}

void	algo_rotate_to_index_a(
	t_machine *machine,
	t_history **result_history,
	int index)
{
	int	length;

	length = stack_length(machine->a);
	if (index > length / 2)
		algo_rotate_a(machine, result_history, (int)index - (int)length);
	else
		algo_rotate_a(machine, result_history, (int)index);
}

void	algo_rotate_b(
	t_machine *machine,
	t_history **result_history,
	int offset)
{
	if (offset < 0)
	{
		while (offset < 0)
		{
			do_inst(machine, result_history, REVERSE_ROTATE_B);
			offset++;
		}
	}
	else
	{
		while (offset > 0)
		{
			do_inst(machine, result_history, ROTATE_B);
			offset--;
		}
	}
}

void	algo_rotate_to_index_b(
	t_machine *machine,
	t_history **result_history,
	int index)
{
	int	length;

	length = stack_length(machine->b);
	if (index > length / 2)
		algo_rotate_b(machine, result_history, (int)index - (int)length);
	else
		algo_rotate_b(machine, result_history, (int)index);
}
