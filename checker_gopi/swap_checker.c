/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 22:58:43 by gopiment          #+#    #+#             */
/*   Updated: 2026/06/05 19:31:56 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_checker(t_list **stack)
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

void	sa_checker(t_list **stack)
{
	swap_checker(stack);
}

void	sb_checker(t_list **stack)
{
	swap_checker(stack);
}

void	swap_swap_checker(t_list **stack_a, t_list **stack_b)
{
	swap_checker(stack_a);
	swap_checker(stack_b);
}
