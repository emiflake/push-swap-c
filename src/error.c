/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/30 22:25:46 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/08 17:53:52 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

#include "error.h"

/*
** Error with an exit number and a string
*/

void	error_out(int exit_no, const char *error_string)
{
	ft_putstr_fd(error_string, 2);
	exit(exit_no);
}
