/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_parser.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/30 22:44:45 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/30 23:34:32 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <libft.h>

#include "error.h"
#include "stack.h"

void			stack_parse(t_stack **stack, char *buffer)
{
	size_t	i;
	int		n;

	if (!buffer)
		error_out(1, "NULL passed to stack_parse as buffer");
	i = 0;
	while (ft_iswhite(buffer[i]))
		i++;
	while (ft_isdigit(buffer[i]))
	{
		n = ft_atoi(&buffer[i]);
		stack_push(stack, n);
		while (ft_isdigit(buffer[i]))
			i++;
		while (ft_iswhite(buffer[i]))
			i++;
	}
	if (buffer[i] != '\0')
		error_out(2, "Error, failed to parse");
	stack_reverse(stack);
}