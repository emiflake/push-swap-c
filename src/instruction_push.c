/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instruction_push.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/30 23:55:10 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/08 17:56:54 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "machine.h"
#include "error.h"

static void		push_from_to(t_stack **src, t_stack **dest)
{
	int	temp;

	if (stack_is_empty(src))
		return ;
	temp = stack_pop(src);
	stack_push(dest, temp);
}

void			push_a(t_machine *machine)
{
	push_from_to(machine->b, machine->a);
}

void			push_b(t_machine *machine)
{
	push_from_to(machine->a, machine->b);
}
