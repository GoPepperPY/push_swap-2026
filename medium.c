/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 04:44:49 by gopiment          #+#    #+#             */
/*   Updated: 2026/06/05 18:27:00 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	long	counter;

	counter = 0;
	if (nb <= 0)
		return (0);
	while (counter * counter < nb)
		counter++;
	return (counter);
}

t_list	*find_ideal_chunk(t_list *stack, int chunk, t_input *input)
{
	t_list	*current;
	t_list	*min_1;
	t_list	*min_2;
	int		counter_1;
	int		counter_2;
	int		pos;

	counter_1 = 0;
	counter_2 = 0;
	pos = 0;
	current = stack;
	min_1 = NULL;
	min_2 = NULL;
	while (current)
	{
		if (current->index <= chunk * ft_sqrt(input->size))
		{
			min_1 = current;
			break ;
		}
		current = (counter_1++, current->next);
	}
	current = stack;
	while (current && counter_2 <= ft_lstsize(stack) / 2)
		current = (counter_2++, current->next);
	while (current)
	{
		if (current->index <= chunk * ft_sqrt(input->size))
		{
			min_2 = current;
			pos = counter_2;
		}
		current = (counter_2++, current->next);
	}
	pos = ft_lstsize(stack) - pos;
	if (pos < counter_1)
		return (min_2);
	return (min_1);
}

void	best_rotation_chunk(t_list **stack_find, t_list **stack_push, \
t_input *input, int chunks)
{
	if (!find_ideal_chunk((*stack_find), chunks, input))
		return ;
	if (get_position((*stack_find), find_ideal_chunk((*stack_find), \
chunks, input)->index) <= ft_lstsize((*stack_find)) / 2)
	{
		while ((*stack_find) != find_ideal_chunk((*stack_find), chunks, input))
			ra(stack_find, &input);
		push_b(stack_find, stack_push, &input);
	}
	else
	{
		while ((*stack_find) != find_ideal_chunk((*stack_find), chunks, input))
			rra(stack_find, &input);
		push_b(stack_find, stack_push, &input);
	}
}

void	best_rotation_a(t_list **stack_find, t_list **stack_push,\
	t_input *input)
{
	if (get_position((*stack_find), find_max((*stack_find))->index) \
<= ft_lstsize((*stack_find)) / 2)
	{
		while (*stack_find != find_max((*stack_find)))
			rb(stack_find, &input);
		push_a(stack_push, stack_find, &input);
	}
	else
	{
		while (*stack_find != find_max((*stack_find)))
			rrb(stack_find, &input);
		push_a(stack_push, stack_find, &input);
	}
}

void	medium(t_list **stack_a, t_list **stack_b, t_input *input)
{
	int	chunks;
	int	chunk;

	chunk = 1;
	chunks = ft_sqrt(input->size);
	while (chunk <= chunks)
	{
		while (find_ideal_chunk(*stack_a, chunk, input))
			best_rotation_chunk(stack_a, stack_b, input, chunk);
		chunk++;
	}
	while (ft_lstsize((*stack_b)) > 0)
		best_rotation_a(stack_b, stack_a, input);
}
