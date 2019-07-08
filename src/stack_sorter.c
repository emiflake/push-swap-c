/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_sorter.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/30 22:32:33 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/08 17:56:25 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"
#include "stack.h"
#include "error.h"

int	stack_is_sorted(t_stack **stack)
{
	t_stack	*walker;

	if (!stack)
		error_out(1, "NULL passed to stack_is_sorted");
	if (stack_is_empty(stack))
		return (1);
	walker = *stack;
	while (walker->tail)
	{
		if (walker->head > walker->tail->head)
			return (0);
		walker = walker->tail;
	}
	return (1);
}
