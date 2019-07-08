/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instruction.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/30 21:53:32 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/08 17:57:22 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "instruction.h"
#include "machine.h"

const char	*g_instruction_strings[] = {
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

const t_instruction_function g_instruction_functions[] = {
	swap_a,
	swap_b,
	swap_both,
	push_a,
	push_b,
	rotate_a,
	rotate_b,
	rotate_both,
	reverse_rotate_a,
	reverse_rotate_b,
	reverse_rotate_both,
};

t_instruction	parse_instruction(char *instruction_string)
{
	size_t i;

	i = 0;
	while (i < sizeof(g_instruction_strings) / sizeof(char*))
	{
		if (ft_strequ(g_instruction_strings[i], instruction_string))
			return ((t_instruction)i);
		i++;
	}
	return (INVALID_INSTRUCTION);
}

const char		*stringify_instruction(t_instruction instruction)
{
	return (g_instruction_strings[instruction]);
}

void			perform_instruction(
	t_machine *machine,
	t_instruction instruction)
{
	g_instruction_functions[instruction](machine);
}
