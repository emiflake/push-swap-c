/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   machine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/30 23:36:13 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/30 23:41:45 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"
#include "stack.h"

int	machine_is_finished(t_machine *machine)
{
	if (!stack_is_sorted(machine->a))
		return (0);
	if (!stack_is_empty(machine->b))
		return (0);
	return (1);
}