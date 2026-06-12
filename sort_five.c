/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 12:25:22 by gopiment          #+#    #+#             */
/*   Updated: 2026/06/12 12:48:45 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	highest(t_list *stack_a)
{
	int	number;

	number = stack_a->index;
	while (stack_a)
	{
		if (number < stack_a->index)
			number = stack_a->index;
		stack_a = stack_a->next;
	}
	return (number);
}

int	lowest(t_list *stack_a)
{
	int	number;

	number = stack_a->index;
	while (stack_a)
	{
		if (number > stack_a->index)
			number = stack_a->index;
		stack_a = stack_a->next;
	}
	return (number);
}

void	passing_b(t_list **stack_a, t_list **stack_b, t_input **input, int a, int b)
{
	int	counter;

	counter = 0;
	while (1)
	{
		if ((*stack_a)->index == a || (*stack_a)->index == b)
		{
			push_b(stack_a, stack_b, input);
			counter++;
			if (counter == 2)
				break ;
		}
		else
			ra(stack_a, input);
	}
	if ((*stack_b)->index < (*stack_b)->next->index)
		rb(stack_b, input);
}

void	sort_five_numbers(t_list **stack_a, t_list **stack_b, t_input **input)
{
	int	l;
	int	h;

	l = 1;
	h = (*input)->size;
	passing_b(stack_a, stack_b, input, l, h);
	sort_three_numbers(stack_a, input);
	push_a(stack_a, stack_b, input);
	ra(stack_a, input);
	push_a(stack_a, stack_b, input);
}