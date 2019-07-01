/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dsl.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 20:54:21 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/01 21:09:41 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dsl.h"
#include "machine.h"
#include "instruction.h"

void	do_inst(t_machine *machine, t_history **history, t_instruction instruction)
{
	perform_instruction(machine, instruction);
	history_save(history, instruction);
}