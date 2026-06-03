/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicamp <danicamp@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 04:44:31 by gopiment          #+#    #+#             */
/*   Updated: 2026/06/03 15:14:39 by danicamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cost	get_cost(int pos_a, int	pos_b, int size_a, int size_b)
{
	int	cost[4];
	int	smaller;
	int	i;
	t_cost	node;
	
	i = 0;
	node.strategy = 1;
	printf("pos_a: %d  pos_b: %d\n", pos_a, pos_b);
	if (pos_a > pos_b)
		cost[0] = pos_a;
	else
		cost[0] = pos_b;
	if (size_a - pos_a > size_b - pos_b)
		cost[1] = size_a - pos_a;
	else
		cost[1] = size_b - pos_b;
	cost[2] = pos_a + (size_b - pos_b);
	cost[3] =  (size_a - pos_a) + pos_b;
	smaller = cost[0];
	printf("cost[%d]: %d\n", i, cost[i]);
	while (++i < 4)
	{
		printf("cost[%d]: %d\n", i, cost[i]);
		if (smaller > cost[i])
		{
			node.strategy = i + 1;
			smaller = cost[i];
		}
	}
	return (node.cost = cost[node.strategy - 1],printf("smaller cost: %d  strategy: %d\n\n", node.cost, node.strategy), node);
}

t_cost	rotation_cost(t_list *stack_a, t_list *stack_b, t_list *best_a, t_list *best_b)
{
	int	pos_a;
	int	pos_b;
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	pos_a = get_position(stack_a, best_a->content);
	pos_b = get_position(stack_b, best_b->content);
	return (get_cost(pos_a, pos_b, size_a, size_b));
}

void	rr_strategy(t_list **stack_a, t_list **stack_b, t_list *to_push, t_input *input)
{
	t_list	*fit;

	fit = best_fit((*stack_b), to_push);
	while ((*stack_a) != to_push && (*stack_b) != fit)
		rotate_rotate(stack_a, stack_b, &input);
	while ((*stack_a) != to_push)
		ra(stack_a, &input);
	while ((*stack_b) != fit)
		rb(stack_b, &input);
}

void	rrr_strategy(t_list **stack_a, t_list **stack_b, t_list *to_push, t_input *input)
{
	t_list	*fit;

	fit = best_fit((*stack_b), to_push);
	while ((*stack_a) != to_push && (*stack_b) != fit)
		rev_rotate_rotate(stack_a, stack_b, &input);
	while ((*stack_b) != fit)
		rrb(stack_b, &input);
	while ((*stack_a) != to_push)
		rra(stack_a, &input);
}

void	best_rotation(t_list **stack_a, t_list **stack_b, t_input *input)
{
	t_cost	node;
	t_list	*to_push;
	t_list	*fit;

	to_push = best_to_push((*stack_a), (*stack_b));
	fit = best_fit((*stack_b), to_push);
	node = rotation_cost((*stack_a), (*stack_b), to_push, fit);
	if (node.strategy == 1)
	{
		rr_strategy(stack_a, stack_b, to_push, input);
	}
	else if (node.strategy == 2)
	{
		rrr_strategy(stack_a, stack_b, to_push, input);
	}
	else
	{
		best_rotation_in_a(stack_a, to_push, input);
		best_rotation_in_b(stack_b, fit, input);
	}
}

void	simple(t_list **stack_a, t_list	**stack_b, t_input *input)
{
	push_b(stack_a, stack_b, &input);
	while ((*stack_a))
	{
		best_rotation(stack_a, stack_b, input);
		push_b(stack_a, stack_b, &input);
	}
	best_rotation_in_b(stack_b, find_max((*stack_b)), input);
	while ((*stack_b))
	{
		push_a(stack_a, stack_b, &input);
	}
}
