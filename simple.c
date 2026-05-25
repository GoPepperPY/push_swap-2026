/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicamp <danicamp@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 04:44:31 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/25 17:21:54 by danicamp         ###   ########.fr       */
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

t_list	*best_fit(t_list *stack_b, t_list *to_fit)
{
	t_list *head;

	head =  stack_b;
	while (stack_b->next)
	{
		if (stack_b->content > to_fit->content && to_fit->content > stack_b->next->content)
			return (stack_b->next);
		stack_b = stack_b->next;
	}
	if (stack_b->content > to_fit->content && to_fit->content > head->content)
		return (head);
	return (NULL);
}

void	simple(t_list **stack_a, t_list	**stack_b, t_input *input)
{
	best_rotation_in_a(stack_a,find_min((*stack_a)), input);
	push_b(stack_a, stack_b, &input);
	best_rotation_in_a(stack_a,find_max((*stack_a)), input);
	push_b(stack_a, stack_b, &input);
	while ((*stack_a))
	{
		best_rotation_in_b(stack_b, best_fit((*stack_b), (*stack_a)), input);
		push_b(stack_a, stack_b, &input);
	}
	best_rotation_in_b(stack_b, find_max((*stack_b)), input);
	while ((*stack_b))
	{
		push_a(stack_a, stack_b, &input);
	}
}
