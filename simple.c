/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicamp <danicamp@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 04:44:31 by gopiment          #+#    #+#             */
/*   Updated: 2026/06/01 11:54:06 by danicamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
