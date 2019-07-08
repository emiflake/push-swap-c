/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/30 21:43:59 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/08 17:53:21 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <get_next_line.h>
#include <stdio.h>

#include "printf_poly.h"
#include "stack.h"
#include "error.h"
#include "stack.h"
#include "machine.h"
#include "instruction.h"

#define BUFFER_

void	checker_perform_instructions(t_machine *machine)
{
	size_t			count;
	char			*line;
	t_instruction	inst;

	count = 0;
	line = NULL;
	while (ft_get_next_line(0, &line))
	{
		inst = parse_instruction(line);
		if (inst == INVALID_INSTRUCTION)
			error_out(2, "Error: Invalid instruction\n");
		perform_instruction(machine, inst);
		count++;
	}
	ft_printf("[%lu Instructions Ran]\n", count);
	stack_print(machine->a);
	stack_print(machine->b);
	ft_printf("\n");
}

void	checker_check(t_machine *machine)
{
	checker_perform_instructions(machine);
	if (machine_is_finished(machine))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
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
		error_out(2, "Error\n");
	checker(argv[1]);
	return (0);
}
