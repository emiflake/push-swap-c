/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_reverse.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/30 23:21:15 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/30 23:33:30 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "stack.h"

static t_stack	*stack_reverse_c(t_stack *walker, t_stack **ret)
{
	if (!walker)
		return (NULL);
	if (!walker->tail)
	{
		*ret = walker;
		return (walker);
	}
	stack_reverse_c(walker->tail, ret)->tail = walker;
	walker->tail = NULL;
	return (walker);
}

void			stack_reverse(t_stack **stack)
{
	stack_reverse_c(*stack, stack);
}