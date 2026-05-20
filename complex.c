/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:11:17 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/20 12:09:11 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	complex(t_list **stack_a, t_list	**stack_b, t_input *input)
{
	double mid;

	mid = ft_lstsize((*stack_a)) / 2;
	while(!is_sorted((*stack_a)))
	{
		while(ft_lstsize((*stack_a)) >= 0)
		{
			push_b(stack_a, stack_b, &input);
			if(ft_lstsize((*stack_b)) > 1 && ((*stack_b)->index > mid))
				rb(stack_b, &input);
		}
		while (ft_lstsize((*stack_b)) >= 0)
		{
			if (((*stack_b)->index > (*stack_b)->next->index) && ((*stack_b)->index > (ft_lstlast(*stack_b))->index))
				push_a(stack_a, stack_b, &input);
			if (((*stack_b)->index < (*stack_b)->next->index) && ((*stack_b)->index > (ft_lstlast(*stack_b))->index))
			{
				sb(stack_b, &input);
				push_a(stack_a, stack_b, &input);
			}
			if (((*stack_b)->index > (*stack_b)->next->index) && ((*stack_b)->index < (ft_lstlast(*stack_b))->index))
			{
				rb(stack_b, &input);
				push_a(stack_a, stack_b, &input);
			}
			else
				push_a(stack_a, stack_b, &input);
		}
	}
}
