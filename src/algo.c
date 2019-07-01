/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 21:16:22 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/01 21:35:09 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	run_algorithm(t_machine *machine, t_history **result_history)
{
	algo_insertion_sort(machine, result_history);
}
