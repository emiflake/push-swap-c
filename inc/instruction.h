/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instruction.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/30 21:48:22 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/01 00:26:45 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# include "machine.h"

typedef enum	e_instruction
{
	SWAP_A,
	SWAP_B,
	SWAP_BOTH,
	PUSH_A,
	PUSH_B,
	ROTATE_A,
	ROTATE_B,
	ROTATE_BOTH,
	REVERSE_A,
	REVERSE_B,
	REVERSE_BOTH,
	REVERSE_REVERSE_A,
	REVERSE_REVERSE_B,
	REVERSE_REVERSE_BOTH,

	INVALID_INSTRUCTION,
}				t_instruction;

t_instruction	parse_instruction(char *instruction_string);
const char		*stringify_instruction(t_instruction instruction);
void			perform_instruction(t_machine *machine, t_instruction instruction);

typedef			void(*t_instruction_function)(t_machine *machine);

void			swap_a(t_machine *machine);
void			swap_b(t_machine *machine);
void			swap_both(t_machine *machine);
void			push_a(t_machine *machine);
void			push_b(t_machine *machine);
void			rotate_a(t_machine *machine);
void			rotate_b(t_machine *machine);
void			rotate_both(t_machine *machine);
void			reverse_rotate_a(t_machine *machine);
void			reverse_rotate_b(t_machine *machine);
void			reverse_rotate_both(t_machine *machine);

#endif