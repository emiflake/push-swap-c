/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   history.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 20:58:23 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/01 21:28:38 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "printf_poly.h"
#include "error.h"
#include "history.h"
#include "instruction.h"
#include "machine.h"
#include "history.h"

static t_history	*history_reverse_c(t_history *walker, t_history **ret)
{
	if (!walker)
		return (NULL);
	if (!walker->next)
	{
		*ret = walker;
		return (walker);
	}
	history_reverse_c(walker->next, ret)->next = walker;
	walker->next = NULL;
	return (walker);
}

void				history_reverse(t_history **history)
{
	history_reverse_c(*history, history);
}

void				history_save(t_history **history, t_instruction instruction)
{
	t_history	*new_head;

	if (!history)
		error_out(1, "NULL passed to history_save");
	new_head = (t_history*)malloc(sizeof(t_stack));
	if (!new_head)
		error_out(1, "Failed to allocate memory.");
	new_head->inst = instruction;
	new_head->next = *history;
	*history = new_head;
}


void				history_print(t_history **history)
{
	t_history *walker;

	walker = *history;
	while (walker)
	{
		ft_printf("%s\n", stringify_instruction(walker->inst));
		walker = walker->next;
	}
}


size_t				history_length(t_history **history)
{
	t_history	*walker;
	size_t		count;

	count = 0;
	walker = *history;
	while (walker)
	{
		walker = walker->next;
		count++;
	}
	return (count);
}