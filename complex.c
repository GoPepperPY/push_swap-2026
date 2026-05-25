/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:11:17 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/26 00:24:46 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	complex(t_list **stack_a, t_list	**stack_b, t_input *input)
{
	int	bit;
	int	counter;
	int	total_bits;
	int	max;

	max = input->size - 1;
	total_bits = 0;
	while ((1 << total_bits) <= max)
		total_bits++;
	bit = 0;
	while (bit < total_bits)
	{
		counter = ft_lstsize(*stack_a);
		while (counter--)
		{
			if (((*stack_a)->content >> bit) & 1)
				ra(stack_a, &input);
			else
				push_b(stack_a, stack_b, &input);
		}
		while (*stack_b)
			push_a(stack_a, stack_b, &input);
		bit++;
	}
}