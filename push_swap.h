/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:07:48 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/21 23:58:25 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"

typedef struct s_flags
{
	int		strategy;
	int		bench;
	double	disorder;
	int		sa;
	int		sb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		pa;
	int		pb;
	int		rrr;
	int		ss;
}	t_flags;

typedef struct s_input
{
	t_flags	flags;
	int		size;
}	t_input;

/*********************|> TO_DELETE <|*********************/
void	print_parsing(t_input *input, t_list *stack_a, t_list *stack_b);
void	print_inputflags(t_input *input);
void	print_list(t_list *stack_a, t_list *stack_b);
void	fill_my_stack(char **args, t_list **stack_a, t_input input);

/*********************|>  PARSING  <|*********************/
void	parsing(char **args, t_input *input);
int		input_flags_check(char **args, t_input **input);

/*********************|>    <|*********************/
// push functions
void	push_b(t_list **stack_a, t_list **stack_b, t_input **input);
void	push_a(t_list **stack_a, t_list **stack_b, t_input **input);

// swap functions
void	sa(t_list **stack, t_input **input);
void	sb(t_list **stack, t_input **input);
void	swap_swap(t_list **stack_a, t_list **stack_b, t_input **input);

// rotate functions
void	rb(t_list	**stack, t_input **input);
void	ra(t_list	**stack, t_input **input);
void	rotate_rotate(t_list **stack_a, t_list **stack_b, t_input **input);

// rev rotatate funtions
void	rra(t_list	**stack, t_input **input);
void	rrb(t_list	**stack, t_input **input);
void	rev_rotate_rotate(t_list **stack_a, t_list **stack_b, t_input **input);

/**********************|>  ERROR.c  <|**********************/
void	error(void);
int		validate_number(char *argument);
void	avoid_clones(t_list **stack);
void	free_split(char **split);

/**********************|>  SORT.c  <|**********************/
void	sort(t_list **stack_a, t_list **stack_b, t_input *input);
int		is_sorted(t_list *stack_a);

/**********************|>  BENCH.c  <|**********************/
double	compute_disorder(t_list *stack);

/**********************|>  SMALL_SORT.c  <|**********************/
void	sort_three_numbers(t_list **stack_a, t_input **input);
void	check_small(t_list **stack_a, t_input *input);

/**********************|>  SIMPLE.c  <|**********************/
void	simple(t_list **stack_a, t_list	**stack_b, t_input *input);
int		best_rotation(t_list *stack_b, int value);

/**********************|>  COMPLEX.c  <|**********************/
void	complex(t_list **stack_a, t_list	**stack_b, t_input *input);

#endif
