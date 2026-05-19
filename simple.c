/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 04:44:31 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/19 16:09:24 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple(t_list **stack_a, t_list	**stack_b, t_input *input)
{
	while(!is_sorted((*stack_a)))
	{
		while(ft_lstsize((*stack_a)) > 0)
		{
			if(ft_lstsize((*stack_a)) > 0)
				push_b(stack_a, stack_b, &input);
			if (ft_lstsize((*stack_a)) >= 2 && ((*stack_a)->content > (*stack_a)->next->content))
				sa(stack_a, &input);
			if (ft_lstsize((*stack_b)) >= 2 && ((*stack_b)->content < (*stack_b)->next->content))
				sb(stack_b, &input);
		}	
		while(ft_lstsize((*stack_b)) > 0)
		{
			if(ft_lstsize((*stack_b)) > 0)
				push_a(stack_a, stack_b, &input);
			if (ft_lstsize((*stack_b)) >= 2 && ((*stack_b)->content < (*stack_b)->next->content))
				sb(stack_b, &input);
			if (ft_lstsize((*stack_a)) >= 2 && ((*stack_a)->content > (*stack_a)->next->content))
				sa(stack_a, &input);
		}
	}
}
