/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/30 22:16:10 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/10 21:29:05 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_printf.h>
#include <libft.h>

#include "stack.h"
#include "error.h"

void			stack_push(t_stack **stack, int value)
{
	t_stack *new_head;

	if (!stack)
		error_out(1, "NULL passed to stack_push");
	new_head = (t_stack*)malloc(sizeof(t_stack));
	if (!new_head)
		error_out(1, "Failed to allocate memory.");
	new_head->head = value;
	new_head->tail = *stack;
	*stack = new_head;
}

int				stack_peek(t_stack **stack)
{
	if (!stack)
		error_out(1, "NULL passed to stack_peek");
	if (stack_is_empty(stack))
		error_out(1, "Peeked on an empty stack");
	return ((*stack)->head);
}

int				stack_pop(t_stack **stack)
{
	int		ret;
	t_stack	*old;

	if (!stack)
		error_out(1, "NULL passed to stack_pop");
	if (stack_is_empty(stack))
		error_out(1, "Popped on an empty stack");
	ret = (*stack)->head;
	old = (*stack);
	*stack = (*stack)->tail;
	free(old);
	return (ret);
}

int				stack_is_empty(t_stack **stack)
{
	if (!stack)
		error_out(1, "NULL passed to stack_is_empty");
	return (!*stack);
}

void			stack_print(t_stack **stack)
{
	t_stack	*walker;

	walker = *stack;
	if (!stack)
		error_out(1, "NULL passed to stack_print");
	if (stack_is_empty(stack))
		ft_dprintf(2, "[]");
	else
	{
		ft_dprintf(2, "[");
		while (walker)
		{
			ft_dprintf(2, "%d", walker->head);
			if (walker->tail)
				ft_dprintf(2, ", ");
			walker = walker->tail;
		}
		ft_dprintf(2, "]");
	}
}
