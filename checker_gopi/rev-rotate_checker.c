/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev-rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 22:58:38 by gopiment          #+#    #+#             */
/*   Updated: 2026/06/05 19:28:29 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_checker(t_list	**stack)
{
	t_list	*current;
	t_list	*last;
	t_list	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = *stack;
	current = *stack;
	while (current->next->next)
		current = current->next;
	last = ft_lstlast(*stack);
	*stack = last;
	(*stack)->next = temp;
	current->next = NULL;
}

void	rra_checker(t_list	**stack)
{
	rev_rotate_checker(stack);
}

void	rrb_checker(t_list	**stack)
{
	rev_rotate_checker(stack);
}

void	rev_rotate_rotate_checker(t_list **stack_a, t_list **stack_b)
{
	rev_rotate_checker(stack_a);
	rev_rotate_checker(stack_b);
}
