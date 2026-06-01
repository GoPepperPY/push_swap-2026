/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicamp <danicamp@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 11:53:06 by danicamp          #+#    #+#             */
/*   Updated: 2026/06/01 11:54:15 by danicamp         ###   ########.fr       */
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

void	best_rotation_in_a(t_list **stack_find, t_list *to_push, t_input *input)
{
	if (get_position((*stack_find), to_push->content)
		<= ft_lstsize((*stack_find)) / 2)
	{
		while (*stack_find != to_push)
			ra(stack_find, &input);
	}
	else
	{
		while (*stack_find != to_push)
			rra(stack_find, &input);
	}
}

void	best_rotation_in_b(t_list **stack_find, t_list *to_push, t_input *input)
{
	if (!to_push)
		return ;
	if (get_position((*stack_find), to_push->content)
		<= ft_lstsize((*stack_find)) / 2)
	{
		while (*stack_find != to_push)
			rb(stack_find, &input);
	}
	else
	{
		while (*stack_find != to_push)
			rrb(stack_find, &input);
	}
}
