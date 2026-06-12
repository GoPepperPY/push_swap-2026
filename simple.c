/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicamp <danicamp@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 16:37:44 by danicamp          #+#    #+#             */
/*   Updated: 2026/06/09 16:40:22 by danicamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*to_push(t_list *stack_a, t_list *stack_b)
{
	t_list	*head;

	head = stack_a;
	while (stack_a)
	{
		if (stack_b->index < stack_a->index)
			return (stack_a);
		stack_a = stack_a->next;
	}
	return (head);
}

void	simple(t_list **stack_a, t_list **stack_b, t_input *input)
{
	t_list	*prev;
	t_list	*first;

	first = *stack_a;
	prev = first;
	ra(stack_a, &input);
	while (*stack_a != first)
	{
		if ((*stack_a)->content < prev->content)
			push_b(stack_a, stack_b, &input);
		else
		{
			prev = *stack_a;
			ra(stack_a, &input);
		}
	}
	while (*stack_b)
	{
		best_rotation_in_b(stack_b, find_min(*stack_b), input);
		best_rotation_in_a(stack_a, to_push(*stack_a, find_min(*stack_b)), input);
		push_a(stack_a, stack_b, &input);
		if (*stack_a == find_max(*stack_a))
			ra(stack_a, &input);
	}
	best_rotation_in_a(stack_a, find_min(*stack_a), input);
}
