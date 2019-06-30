/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/30 21:43:59 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/01 00:32:42 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <get_next_line.h>

#include "stack.h"
#include "error.h"
#include "stack.h"
#include "machine.h"
#include "instruction.h"

void	checker_perform_instructions(t_machine *machine)
{
	char			*line;
	t_instruction	inst;

	line = NULL;
	while (ft_get_next_line(0, &line))
	{
		inst = parse_instruction(line);
		if (inst == INVALID_INSTRUCTION)
			error_out(2, "Error: Invalid instruction\n");
		ft_putstr("Performed instruction: ");
		ft_putendl(stringify_instruction(inst));
		perform_instruction(machine, inst);
		stack_print(machine->a);
	}
}

void	checker_check(t_machine *machine)
{
	stack_print(machine->a);

	checker_perform_instructions(machine);
	if (machine_is_finished(machine))
		ft_putendl("OK");
	else
		ft_putendl("KO");
}

void	checker(char *stack_str)
{
	t_machine	machine;
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_parse(&stack_a, stack_str);
	machine.a = &stack_a;
	machine.b = &stack_b;
	checker_check(&machine);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		error_out(2, "Error\n");
		return (1);
	}
	checker(argv[1]);
    return (0);
}