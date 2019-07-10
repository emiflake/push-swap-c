/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 21:16:30 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/10 14:31:22 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "machine.h"
# include "history.h"
# include "instruction.h"

/*
** algo.c
** ------
** Run the algorithm
*/

void	run_algorithm(
	t_machine *machine,
	t_history **result_history);
/*
** insertion_sort.c
** ------
** insertion sort algorithm
*/

void	algo_insertion_sort(
	t_machine *machine,
	t_history **result_history);

/*
** algo_helper_rotation.c
** ------
** Rotation helpers
*/
void	algo_rotate_to_index_a(
	t_machine *machine,
	t_history **result_history,
	int index);

void	algo_rotate_to_index_b(
	t_machine *machine,
	t_history **result_history,
	int index);

int		ft_abs(int x);

#endif
