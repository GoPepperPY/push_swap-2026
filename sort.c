/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicamp <danicamp@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 02:22:44 by gopiment          #+#    #+#             */
/*   Updated: 2026/06/12 12:11:29 by danicamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position_simple(t_list	*stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->content == value)
			break ;
		pos++;
		stack = stack->next;
	}
	return (pos);
}

int	is_sorted(t_list *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	init(t_input *input)
{
	input->flags.sa = 0;
	input->flags.sb = 0;
	input->flags.ra = 0;
	input->flags.rb = 0;
	input->flags.rr = 0;
	input->flags.rra = 0;
	input->flags.rrb = 0;
	input->flags.pa = 0;
	input->flags.pb = 0;
	input->flags.rrr = 0;
	input->flags.ss = 0;
}

void	adaptative(t_list **stack_a, t_list **stack_b, t_input *input)
{
	if (ft_lstsize((*stack_a)) <= 3)
		check_small(stack_a, input);
	else if (input->flags.disorder < 0.2)
		medium(stack_a, stack_b, input);
	else if ((input->flags.disorder < 0.5))
		medium(stack_a, stack_b, input);
	else
		complex(stack_a, stack_b, input);
}

void	sort(t_list **stack_a, t_list **stack_b, t_input *input)
{
	input->flags.disorder = compute_disorder((*stack_a));
	if (input->flags.bench)
		init(input);
	if (input->flags.bench)
		bench(input);
	if (is_sorted((*stack_a)) || input->size == 1)
		return ;
	if (input->flags.strategy == 0 || input->flags.strategy == 4)
		adaptative(stack_a, stack_b, input);
	else
	{
		if (ft_lstsize((*stack_a)) <= 3)
			check_small(stack_a, input);
		else if (input->flags.strategy == 1)
			simple(stack_a, stack_b, input);
		else if (input->flags.strategy == 2)
			medium(stack_a, stack_b, input);
		else if (input->flags.strategy == 3)
			complex(stack_a, stack_b, input);
	}
}
