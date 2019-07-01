/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insertion_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 21:18:53 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/01 22:18:54 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "algo.h"
#include "machine.h"
#include "history.h"
#include "instruction.h"
#include "dsl.h"
#include "printf_poly.h"

static int	stack_minimum_index(t_stack **stack)
{
	int		minimum;
	size_t	minimum_index;
	size_t	index;
	t_stack *walker;

	walker = *stack;
	index = 0;
	minimum_index = 0;
	minimum = walker->head;
	while (walker)
	{
		if (walker->head < minimum)
		{
			minimum = walker->head;
			minimum_index = index;
		}
		index++;
		walker = walker->tail;
	}
	return (minimum_index);
}

void		algo_insertion_sort(t_machine *machine, t_history **result_history)
{
	size_t	c;
	size_t	len;
	size_t	min_index;

	c = 0;
	len = stack_length(machine->a);
	while (c < len)
	{
		min_index = stack_minimum_index(machine->a);
		algo_rotate_to_index_a(machine, result_history, min_index);
		do_inst(machine, result_history, PUSH_B);
		c++;
	}
	c = 0;
	len = stack_length(machine->b);
	while (c < len)
	{
		do_inst(machine, result_history, PUSH_A);
		c++;
	}
}