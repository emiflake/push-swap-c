/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instruction_rotate.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 00:00:28 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/08 17:57:38 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "error.h"
#include "instruction.h"
#include "machine.h"

void			rotate_stack(t_stack **stack)
{
	int		temp;
	t_stack	*walker;
	t_stack *new_stack_elem;

	if (stack_is_empty(stack) || !(*stack)->tail)
		return ;
	temp = stack_pop(stack);
	walker = *stack;
	while (walker->tail)
		walker = walker->tail;
	new_stack_elem = (t_stack*)malloc(sizeof(t_stack));
	if (!new_stack_elem)
		error_out(1, "Failed to allocate memory while rotating stack");
	new_stack_elem->head = temp;
	new_stack_elem->tail = NULL;
	walker->tail = new_stack_elem;
}

void			rotate_a(t_machine *machine)
{
	rotate_stack(machine->a);
}

void			rotate_b(t_machine *machine)
{
	rotate_stack(machine->b);
}

void			rotate_both(t_machine *machine)
{
	rotate_a(machine);
	rotate_b(machine);
}
