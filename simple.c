/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicamp <danicamp@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 04:44:31 by gopiment          #+#    #+#             */
/*   Updated: 2026/06/01 16:49:59 by danicamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cost	rotation_cost(t_list *stack_a, t_list *stack_b, t_list *best_a, t_list *best_b)
{
	int	cost[4];
	t_cost	node;
	int	pos_a;
	int	pos_b;
	int	i;
	int	smaller;

	node.strategy = 1;
	i = 0;
	pos_a = get_position(stack_a, best_a->content);
	pos_b = get_position(stack_b, best_b->content);
	if (pos_a > pos_b)
		cost[0] = pos_a;
	else
		cost[0] = pos_b;
	if (ft_lstsize(stack_a) - pos_a > ft_lstsize(stack_b) - pos_b)
		cost[1] = ft_lstsize(stack_a) - pos_a;
	else
		cost[1] = ft_lstsize(stack_b) - pos_b;
	cost[2] = pos_a + ft_lstsize(stack_b) - pos_b;
	cost[3] =  ft_lstsize(stack_a) - pos_a + pos_b;
	smaller = cost[0];
	while (i < 4)
	{
		if (smaller > cost[i])
		{
			smaller = cost[i];
			node.strategy = i + 1;
		}
		i++;
	}
	node.cost = cost[node.strategy - 1];
	return (node);
}

void	best_rotation(t_list **stack_a, t_list **stack_b, t_list *to_push, t_list *best_fit, t_input *input)
{
	t_cost	node;

	node = rotation_cost((*stack_a), (*stack_b), to_push, best_fit);
	if (node.strategy == 1)
	{
		while ((*stack_a) != to_push && (*stack_b) != best_fit)
			rotate_rotate(stack_a, stack_b, &input);
		while ((*stack_a) != to_push)
			ra(stack_a, &input);
		while ((*stack_b) != best_fit)
			rb(stack_b, &input);
	}
	else if (node.strategy == 2)
	{
		while ((*stack_a) != to_push && (*stack_b) != best_fit)
			rev_rotate_rotate(stack_a, stack_b, &input);
		while ((*stack_b) != best_fit)
			rrb(stack_b, &input);
		while ((*stack_a) != to_push)
			rra(stack_a, &input);
	}
	else
	{
		best_rotation_in_a(stack_a, to_push, input);
		best_rotation_in_b(stack_b, best_fit, input);
	}
}

t_list	*best_fit(t_list *stack_b, t_list *to_fit)
{
	t_list	*best;
	t_list	*temp;
	int		current;

	best = NULL;
	temp = stack_b;
	current = INT_MIN;
	while (temp)
	{
		if (temp->content < to_fit->content && temp->content > current)
		{
			best = temp;
			current = temp->content;
		}
		temp = temp->next;
	}
	if (!best)
		return (find_max(stack_b));
	return (best);
}

t_list	*best_to_push(t_list *stack_a, t_list *stack_b)
{
	t_list	*best;
	t_list	*head;
	t_cost	current;
	int		smaller;

	best = NULL;
	smaller = INT_MAX;
	head = stack_a;
	while (stack_a)
	{
		current = rotation_cost(stack_a, stack_b, stack_a, best_fit(stack_b, stack_a));
		if (current.cost < smaller)
		{
			best = stack_a;
			smaller = current.cost;
		}
		stack_a = stack_a->next;
	}
	if (!best)
		return (head);
	return (best);
}

void	simple(t_list **stack_a, t_list	**stack_b, t_input *input)
{
	t_list	*best;

	best_rotation_in_a(stack_a,find_max((*stack_a)), input);
	push_b(stack_a, stack_b, &input);
	while ((*stack_a))
	{
		best = best_to_push((*stack_a), (*stack_b));
		best_rotation(stack_a, stack_b, best, best_fit((*stack_b), best), input);
		push_b(stack_a, stack_b, &input);
	}
	best_rotation_in_b(stack_b, find_max((*stack_b)), input);
	while ((*stack_b))
	{
		push_a(stack_a, stack_b, &input);
	}
}
