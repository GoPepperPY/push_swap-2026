/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 04:44:31 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/24 04:01:12 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_list	*stack, int value)
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

t_list	*find_min(t_list *stack)
{
	t_list	*current;
	t_list	*min;

	current = stack;
	min = stack;
	while (current)
	{
		if (current->content < min->content)
			min = current;
		current = current->next;
	}
	return (min);
}

void	best_rotation(t_list **stack_find, t_list **stack_push, t_input *input)
{
	if (get_position((*stack_find), find_min((*stack_find))->content)
		<= ft_lstsize((*stack_find)) / 2)
	{
		while (*stack_find != find_min((*stack_find)))
			ra(stack_find, &input);
		push_b(stack_find, stack_push, &input);
	}
	else
	{
		while (*stack_find != find_min((*stack_find)))
			rra(stack_find, &input);
		push_b(stack_find, stack_push, &input);
	}
}

t_list	*find_max(t_list *stack)
{
	t_list	*current;
	t_list	*max;

	current = stack;
	max = stack;
	while (current)
	{
		if (current->content > max->content)
			max = current;
		current = current->next;
	}
	return (max);
}

void	simple(t_list **stack_a, t_list	**stack_b, t_input *input)
{
	while (ft_lstsize((*stack_a)) > 0)
		best_rotation(stack_a, stack_b, input);
	while (ft_lstsize((*stack_b)) > 0)
	{
		push_a(stack_a, stack_b, &input);
	}
}
