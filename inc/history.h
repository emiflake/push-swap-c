/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   history.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/30 22:00:06 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/11 00:19:32 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include <stddef.h>

# include "instruction.h"

typedef struct	s_history
{
	t_instruction		inst;
	struct s_history	*next;
}				t_history;

void			history_save(t_history **history, t_instruction instruction);

void			history_reverse(t_history **history);
void			history_print(t_history **history);
size_t			history_length(t_history **history);
void			history_optimize(t_history **history);

#endif
