/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/30 21:44:20 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/01 22:19:38 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "error.h"
#include "instruction.h"
#include "machine.h"
#include "history.h"
#include "stack.h"
#include "algo.h"

void	push_swap(char *stack_str)
{
	t_machine	machine;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_history	*result_history;

	stack_a = NULL;
	stack_b = NULL;
	stack_parse(&stack_a, stack_str);
	machine.a = &stack_a;
	machine.b = &stack_b;
	result_history = NULL;
	run_algorithm(&machine, &result_history);
	history_reverse(&result_history);
	history_print(&result_history);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		error_out(2, "Error\n");
	push_swap(argv[1]);
    return (0);
}