/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicamp <danicamp@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 22:58:43 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/30 16:24:21 by danicamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, t_input **input)
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
}

void	sa(t_list **stack, t_input **input)
{
	swap(stack, input);
	write(1, "sa\n", 3);
	if ((*input)->flags.bench)
		(*input)->flags.sa++;
}

void	sb(t_list **stack, t_input **input)
{
	swap(stack, input);
	write(1, "sb\n", 3);
	if ((*input)->flags.bench)
		(*input)->flags.sb++;
}

void	swap_swap(t_list **stack_a, t_list **stack_b, t_input **input)
{
	swap(stack_a, input);
	swap(stack_b, input);
	write(1, "ss\n", 3);
	if ((*input)->flags.bench)
		(*input)->flags.ss++;
}
