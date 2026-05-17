/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 22:58:43 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/17 05:48:10 by gopiment         ###   ########.fr       */
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
	ft_printf("sa\n");
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
	ft_printf("sb\n");
	if ((*input)->flags.bench)
		(*input)->flags.sb++;
}

void	swap_swap(t_list **stack_a, t_list **stack_b, t_input **input)
{
	sa(stack_a, input);
	sb(stack_b, input);
	ft_printf("ss\n");
	if ((*input)->flags.bench)
		(*input)->flags.ss++;
}
