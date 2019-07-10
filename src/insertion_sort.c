/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insertion_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 21:18:53 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/10 18:29:43 by nmartins      ########   odam.nl         */
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
	return (minimum_index);
}

static int	stack_maximum_index(t_stack **stack)
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
	return (maximum_index);
}

int			index_of(t_stack **stack, int val)
{
	size_t	index;
	t_stack *walker;

	walker = *stack;
	if (!walker)
		return (0);
	index = 0;
	while (walker)
	{
		if (walker->head > val)
		{
			index++;
		}
		walker = walker->tail;
	}
	return (index);
}

void		algo_smart_insert(t_machine *machine, t_history **result_history)
{
	int	val;
	int	ind;

	if (*(machine->a) == NULL)
		return ;
	ind = 0;
	if (*(machine->b) != NULL)
	{
		val = (*machine->a)->head;
		ind = index_of(machine->b, val);
		ft_printf("%d (%d) into ", val, ind);
		stack_print(machine->b);
		ft_printf(".\n");
		algo_rotate_to_index_b(machine, result_history, ind);
	}
	do_inst(machine, result_history, PUSH_B);
	if (ind > 0)
		do_inst(machine, result_history, ROTATE_B);
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
}
