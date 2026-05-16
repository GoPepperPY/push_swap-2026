/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicamp <danicamp@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:07:48 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/16 09:18:08 by danicamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "ft_printf/ft_printf.h"


typedef struct s_flags
{
	int     strategy;
    int     bench;
}   t_flags;

typedef struct s_input
{
	t_flags flags;
    int     size;
}   t_input;

/*********************|> TO_DELETE <|*********************/
void 	print_parsing(t_input *input, t_list *stack_a, t_list *stack_b);
void	print_inputflags(t_input *input);
void	print_list(t_list *stack_a, t_list *stack_b);
void	fill_my_stack(char **args, t_list **stack_a, int argc, t_input input);

/*********************|>  PARSING  <|*********************/
void	parsing(char **args, t_input *input);
int		input_flags_check(char **args, t_input **input);

// push functions
void	push_b(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
// swap functions
void	swap(t_list **stack);
void	swap_swap(t_list **stack_a, t_list **stack_b); 
// rotate functions
void	rotate(t_list	**stack);
void	rotate_rotate(t_list **stack_a, t_list **stack_b);
// rev rotatate funtions
void	rev_rotate(t_list	**stack);
void	rev_rotate_rotate(t_list **stack_a, t_list **stack_b);





/**********************|>  ERROR  <|**********************/
void	error(void);
void    validate_number(char *argument);
void	avoid_clones(t_list **stack);

#endif