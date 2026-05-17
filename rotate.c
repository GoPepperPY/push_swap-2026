/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 22:58:41 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/16 22:55:47 by gopiment         ###   ########.fr       */
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
	{
		current = current->next;
	}
	current->next = temp;
	current->next->next = NULL;
}

void	rotate_rotate(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
