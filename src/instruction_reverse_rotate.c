/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instruction_reverse_rotate.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 18:30:05 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/01 18:36:04 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <libft.h>

#include "error.h"
#include "instruction.h"
#include "machine.h"

void			reverse_rotate_stack(t_stack **stack)
{
	int		temp;
	t_stack	*walker;

	if (stack_is_empty(stack) || !(*stack)->tail)
		return ;
	walker = *stack;
	while (walker->tail->tail)
		walker = walker->tail;
	temp = walker->tail->head;
	ft_memdel((void*)&walker->tail);
	stack_push(stack, temp);
}

void			reverse_rotate_a(t_machine *machine)
{
	reverse_rotate_stack(machine->a);
}

void			reverse_rotate_b(t_machine *machine)
{
	reverse_rotate_stack(machine->b);
}

void			reverse_rotate_both(t_machine *machine)
{
	reverse_rotate_a(machine);
	reverse_rotate_b(machine);
}
