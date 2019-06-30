/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instruction.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/30 21:53:32 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/01 00:32:11 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "instruction.h"
#include "machine.h"


const char      *instruction_strings[] = {
	"sa",
	"sb",
	"ss",
	"pa",
	"pb",
	"ra",
	"rb",
	"rr",
	"rra",
	"rrb",
	"rrr",
	"invinst",
};

const t_instruction_function instruction_functions[] = {
	swap_a,
	swap_b,
	swap_both,
	push_a,
	push_b,
	rotate_a,
	rotate_b,
	rotate_both,
	// reverse_rotate_a,
	// reverse_rotate_b,
	// reverse_rotate_both,
};

t_instruction   parse_instruction(char *instruction_string)
{
	size_t i;

	i = 0;
	while (i < sizeof(instruction_strings) / sizeof(char*))
	{
		if (ft_strequ(instruction_strings[i], instruction_string))
			return ((t_instruction)i);
		i++;
	}
	return (INVALID_INSTRUCTION);
}

const char      *stringify_instruction(t_instruction instruction)
{
	return (instruction_strings[instruction]);
}

void			perform_instruction(t_machine *machine, t_instruction instruction)
{
	instruction_functions[instruction](machine);
}
