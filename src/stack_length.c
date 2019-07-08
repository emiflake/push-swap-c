/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_length.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 21:42:34 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/08 17:56:05 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "stack.h"

size_t	stack_length(t_stack **stack)
{
	t_stack	*walker;
	size_t	counter;

	counter = 0;
	walker = *stack;
	while (walker)
	{
		walker = walker->tail;
		counter++;
	}
	return (counter);
}
