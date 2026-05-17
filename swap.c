/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 22:58:43 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/16 23:23:22 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
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

void	swap_swap(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
