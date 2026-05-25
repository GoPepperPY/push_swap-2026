/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 22:58:43 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/25 19:09:21 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack, t_input **input)
{
	t_list	*temp;
	t_list	*temp_next;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = *stack;
	temp_next = (*stack)->next->next;
	*stack = (*stack)->next;
	(*stack)->next = temp;
	(*stack)->next->next = temp_next;
	write(1, "sa\n", 3);
	if ((*input)->flags.bench)
		(*input)->flags.sa++;
}

void	sb(t_list **stack, t_input **input)
{
	t_list	*temp;
	t_list	*temp_next;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = *stack;
	temp_next = (*stack)->next->next;
	*stack = (*stack)->next;
	(*stack)->next = temp;
	(*stack)->next->next = temp_next;
	write(1, "sb\n", 3);
	if ((*input)->flags.bench)
		(*input)->flags.sb++;
}

void	swap_swap(t_list **stack_a, t_list **stack_b, t_input **input)
{
	sa(stack_a, input);
	sb(stack_b, input);
	write(1, "ss\n", 3);
	if ((*input)->flags.bench)
		(*input)->flags.ss++;
}
