/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicamp <danicamp@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 16:37:44 by danicamp          #+#    #+#             */
/*   Updated: 2026/06/05 16:51:45 by danicamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_list	*to_push(t_list *stack_a, t_list *stack_b)
{
	t_list	*head;
	
	head = stack_a;
	while (stack_a->next)
	{
		if (stack_b->content > stack_a->content && stack_b->content < stack_a->next->content)
			return (stack_a->next);
		stack_a = stack_a->next;
	}
	return (head);
}

void	simple(t_list **stack_a, t_list **stack_b, t_input *input)
{
	t_list	*prev;
	t_list	*min;

	min = find_min((*stack_a));
	prev = min;
	best_rotation_in_a(stack_a, prev, input);
	ra(stack_a, &input);
	while (*stack_a != min)
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
		best_rotation_in_a(stack_a, to_push(*stack_a, *stack_b), input);
		push_a(stack_a, stack_b, &input);
	}
	best_rotation_in_a(stack_a, find_min(*stack_a), input);
}
