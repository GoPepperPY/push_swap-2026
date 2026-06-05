/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 22:58:41 by gopiment          #+#    #+#             */
/*   Updated: 2026/06/05 19:28:44 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_checker(t_list	**stack)
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

void	ra_checker(t_list	**stack)
{
	rotate_checker(stack);
}

void	rb_checker(t_list	**stack)
{
	rotate_checker(stack);
}

void	rotate_rotate_checker(t_list **stack_a, t_list **stack_b)
{
	rotate_checker(stack_a);
	rotate_checker(stack_b);
}
