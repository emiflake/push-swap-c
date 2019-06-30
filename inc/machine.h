/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   machine.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/30 21:47:12 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/30 21:49:04 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACHINE_H
# define MACHINE_H

typedef s_machine
{
    t_stack *a;
    t_stack *b;
}       t_machine;

#endif MACHINE_H