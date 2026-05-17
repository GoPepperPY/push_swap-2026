/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 22:58:41 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/17 06:03:41 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list	**stack, t_input **input)
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
	ft_printf("ra\n");
	if ((*input)->flags.bench)
		(*input)->flags.ra++;
}

void	rb(t_list	**stack, t_input **input)
{
	t_list	*temp;
	t_list	*current;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	current = *stack;
	while (current->next)
	{
		current = current->next;
	}
	current->next = temp;
	current->next->next = NULL;
	ft_printf("rb\n");
	if ((*input)->flags.bench)
		(*input)->flags.rb++;
}

void	rotate_rotate(t_list **stack_a, t_list **stack_b, t_input **input)
{
	ra(stack_a, input);
	rb(stack_b, input);
	ft_printf("rr\n");
	if ((*input)->flags.bench)
		(*input)->flags.rr++;
}
