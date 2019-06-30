/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instruction_swap.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/30 23:47:45 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/01 00:11:23 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "instruction.h"
#include "machine.h"

static void		swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void		swap_stack(t_stack **stack)
{
	if (stack_is_empty(stack) || (*stack)->tail == NULL)
		return ;
	swap_int(&(*stack)->head, &(*stack)->tail->head); 
}

void			swap_a(t_machine *machine)
{
	swap_stack(machine->a);
}

void			swap_b(t_machine *machine)
{
	swap_stack(machine->b);
}

void			swap_both(t_machine *machine)
{
	swap_a(machine);
	swap_b(machine);
}