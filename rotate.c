/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicamp <danicamp@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 22:58:41 by gopiment          #+#    #+#             */
/*   Updated: 2026/06/01 16:21:21 by danicamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list	**stack)
{
	t_list	*temp;
	t_list	*current;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = temp;
	current->next->next = NULL;
}

void	ra(t_list	**stack, t_input **input)
{
	rotate(stack);
	write(1, "ra\n", 3);
	if ((*input)->flags.bench)
		(*input)->flags.ra++;
}

void	rb(t_list	**stack, t_input **input)
{
	rotate(stack);
	write(1, "rb\n", 3);
	if ((*input)->flags.bench)
		(*input)->flags.rb++;
}

void	rotate_rotate(t_list **stack_a, t_list **stack_b, t_input **input)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	if ((*input)->flags.bench)
		(*input)->flags.rr++;
}
