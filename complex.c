/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:11:17 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/19 16:36:35 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	complex(t_list **stack_a, t_list	**stack_b, t_input *input)
{
	double mid;

	mid = ft_lstsize((*stack_a)) / 2;
	while(!is_sorted((*stack_a)))
	{
		while(ft_lstsize((*stack_a)) > 0)
		{
			push_b(stack_a, stack_b, &input);
			if(ft_lstsize((*stack_b)) > 1 && ((*stack_b)->index < mid))
				rb(stack_b, &input);
		}
	}
}
