/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicamp <danicamp@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:07:48 by gopiment          #+#    #+#             */
/*   Updated: 2026/06/04 20:38:26 by danicamp         ###   ########.fr       */
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

typedef struct s_cost
{
	t_flags	flags;
	int		cost;
	int		strategy;
}	t_cost;

/*********************|> TO_DELETE <|*********************/
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
void	bench(t_input *input);
void	init(t_input *input);

/**********************|>  SMALL_SORT.c  <|**********************/
void	sort_three_numbers(t_list **stack_a, t_input **input);
void	check_small(t_list **stack_a, t_input *input);

// /**********************|>  SIMPLE.c  <|**********************/
int		bit_count(t_list *stack_a);
void	simple(t_list **stack_a, t_list	**stack_b, t_input *input);

/**********************|>  SORT_UTILS.c  <|**********************/
int		get_position(t_list	*stack, int value);
t_list	*find_max(t_list *stack);
t_list	*find_min(t_list *stack);
void	best_rotation_in_a(t_list **stack_find, t_list *to_push, t_input *input);
void	best_rotation_in_b(t_list **stack_find, t_list *to_push, t_input *input);


/**********************|>  COMPLEX.c  <|**********************/
void	complex(t_list **stack_a, t_list	**stack_b, t_input *input);

/**********************|>  MEDIUM.c  <|**********************/
void	medium(t_list **stack_a, t_list **stack_b, t_input *input);
void	best_rotation_a(t_list **stack_find, t_list **stack_push, \
t_input *input);


#endif
