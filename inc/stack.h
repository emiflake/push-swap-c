/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/30 22:09:45 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/08 18:01:32 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stddef.h>

typedef struct	s_stack
{
	int				head;
	struct s_stack	*tail;
}				t_stack;

/*
** stack.c
*/
void			stack_push(t_stack **stack, int value);
int				stack_peek(t_stack **stack);
int				stack_pop(t_stack **stack);
int				stack_is_empty(t_stack **stack);
void			stack_print(t_stack **stack);

/*
** stack_parser.c
** ------
** Parse a stack from a number string.
** e.g.:
** "15 52 23 9 1"
*/
void			stack_parse(t_stack **stack, char *buffer);

/*
** stack_sorter.c
** ------
** Checks if a stack is sorted
*/
int				stack_is_sorted(t_stack **stack);

/*
** stack_reverse.c
** ------
** Reverses a stack.
*/
void			stack_reverse(t_stack **stack);

/*
** stack_length.c
** ------
** Get the length of a stack
*/
size_t			stack_length(t_stack **stack);
#endif
