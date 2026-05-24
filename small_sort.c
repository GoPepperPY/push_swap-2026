/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 04:44:10 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/24 08:18:02 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_numbers(t_list **stack_a, t_input **input)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stack_a)->index;
	mid = (*stack_a)->next->index;
	bot = (*stack_a)->next->next->index;
	if (top > mid && top < bot)
		sa(stack_a, input);
	else if (top > mid && mid > bot)
	{
		sa(stack_a, input);
		rra(stack_a, input);
	}
	else if (top > mid && bot < top)
		ra(stack_a, input);
	else if (top < mid && bot < mid && bot > top)
	{
		sa(stack_a, input);
		ra(stack_a, input);
	}
	else if (top < mid && mid > bot && bot < top)
		rra(stack_a, input);
}

void	check_small(t_list **stack_a, t_input *input)
{
	if (input->size == 2)
	{
		if ((*stack_a)->next->content < (*stack_a)->content)
			sa(stack_a, &input);
	}
	if (input->size == 3)
		sort_three_numbers(stack_a, &input);
}
