/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insertion_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 21:18:53 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/11 00:17:37 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
#include "machine.h"
#include "history.h"
#include "instruction.h"
#include "dsl.h"
#include "printf_poly.h"

static int	stack_minimum_index(t_stack **stack, int *out_min)
{
	int		minimum;
	size_t	minimum_index;
	size_t	index;
	t_stack *walker;

	walker = *stack;
	if (!walker)
		return (0);
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
	if (out_min)
		*out_min = minimum;
	return (minimum_index);
}

static int	stack_maximum_index(t_stack **stack, int *out_max)
{
	int		maximum;
	size_t	maximum_index;
	size_t	index;
	t_stack *walker;

	walker = *stack;
	if (!walker)
		return (0);
	index = 0;
	maximum_index = 0;
	maximum = walker->head;
	while (walker)
	{
		if (walker->head > maximum)
		{
			maximum = walker->head;
			maximum_index = index;
		}
		index++;
		walker = walker->tail;
	}
	if (out_max)
		*out_max = maximum;
	return (maximum_index);
}

int			index_of(t_stack **stack, int val)
{
	size_t	index;
	t_stack *walker;
	int		max;
	int		min;
	int		min_index;
	int		max_index;

	min_index = stack_minimum_index(stack, &min);
	max_index = stack_maximum_index(stack, &max);
	walker = *stack;
	if (!walker)
		return (0);
	index = 0;
	while (walker && walker->tail)
	{
		if (walker->head > val && walker->tail->head <= val)
			return (index + 1);
		index++;
		walker = walker->tail;
	}
	if (val > max)
		return (max_index);
	else if (val < min)
		return (min_index + 1);
	else
		return (index + 1);
}

void		algo_smart_insert(t_machine *machine, t_history **result_history)
{
	int		val;
	int		ind;
	size_t	len;

	if (*(machine->a) == NULL)
		return ;
	ind = 0;
	len = stack_length(machine->b);
	if (*(machine->b) != NULL)
	{
		val = (*machine->a)->head;
		ind = index_of(machine->b, val);
		algo_rotate_to_index_b(machine, result_history, ind);
	}
	do_inst(machine, result_history, PUSH_B);
}

void		algo_insertion_sort(t_machine *machine, t_history **result_history)
{
	size_t	c;
	size_t	len;

	(void)stack_minimum_index;
	(void)stack_maximum_index;
	c = 0;
	len = stack_length(machine->a);
	do_inst(machine, result_history, PUSH_B);
	while (c < len)
	{
		algo_smart_insert(machine, result_history);
		c++;
	}
	c = 0;
	len = stack_length(machine->b);
	while (c < len)
	{
		do_inst(machine, result_history, PUSH_A);
		c++;
	}
	algo_rotate_to_index_a(machine, result_history, stack_minimum_index(machine->a, NULL));
}
