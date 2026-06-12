/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicamp <danicamp@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:11:17 by gopiment          #+#    #+#             */
/*   Updated: 2026/06/09 18:56:34 by danicamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bit_count(t_list *stack_a)
{
	int	stack_size;
	int	bit;

	bit = 0;
	stack_size = ft_lstsize(stack_a) - 1;
	while (stack_size > 0)
	{
		stack_size /= 2;
		bit++;
	}
	return (bit);
}

void	complex(t_list **stack_a, t_list	**stack_b, t_input *input)
{
	int	lst_size;
	int	i;
	int	j;
	int	bits;

	i = 0;
	j = 0;
	lst_size = ft_lstsize((*stack_a));
	bits = bit_count((*stack_a));
	while (j < bits)
	{
		while (i < lst_size)
		{
			if ((((*stack_a)->index >> j) & 1) == 0)
				push_b(stack_a, stack_b, &input);
			else
				ra(stack_a, &input);
			i++;
		}
		while ((*stack_b))
			push_a(stack_a, stack_b, &input);
		j++;
		i = 0;
	}
}
