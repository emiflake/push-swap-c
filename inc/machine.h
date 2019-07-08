/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   machine.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/30 21:47:12 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/08 18:01:25 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACHINE_H
# define MACHINE_H

# include "stack.h"

typedef struct	s_machine
{
	t_stack	**a;
	t_stack	**b;
}				t_machine;

int				machine_is_finished(t_machine *machine);

#endif
