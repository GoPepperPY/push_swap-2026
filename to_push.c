/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicamp <danicamp@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:58:10 by danicamp          #+#    #+#             */
/*   Updated: 2026/06/03 15:14:29 by danicamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*best_to_push(t_list *stack_a, t_list *stack_b)
{
	t_list	*best;
	t_list	*temp;
	t_cost	current;
	int		smaller;

	best = NULL;
	smaller = INT_MAX;
	temp = stack_a;
	while (temp)
	{
		current = rotation_cost(stack_a, stack_b, temp,
				best_fit(stack_b, stack_a));
		if (current.cost < smaller)
		{
			best = temp;
			smaller = current.cost;
		}
		temp = temp->next;
	}
	printf("best_cost: %d\n\n", smaller);
	if (!best)
		return (stack_a);
	return (best);
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
