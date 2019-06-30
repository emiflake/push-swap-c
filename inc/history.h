/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   history.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/30 22:00:06 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/30 22:04:56 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include "instruction.h"

typedef struct	s_history
{
	t_instruction		inst;
	struct s_history	*next;    
}				t_history;
    

#endif