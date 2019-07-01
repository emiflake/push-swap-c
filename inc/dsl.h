/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dsl.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 20:54:33 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/01 21:05:56 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DSL_H
# define DSL_H

# include "instruction.h"
# include "machine.h"
# include "history.h"

void	do_inst(t_machine *machine, t_history **history, t_instruction instruction);

#endif