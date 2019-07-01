/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_poly.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 18:41:42 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/01 18:47:03 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_POLY_H
# define PRINTF_POLY_H

# include <stdio.h>
# include <stdlib.h>

# define ft_printf(...) do { \
	printf(__VA_ARGS__); \
	fflush(NULL); \
} while (0)

#endif
