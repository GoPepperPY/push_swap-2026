/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicamp <danicamp@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 22:58:41 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/16 08:23:23 by danicamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_stack(t_list **stack)
{
	t_list	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	rotate(t_list	**stack)
{
	t_list	*stack_rev;
	t_list	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	ft_lstadd_front(&stack_rev, ft_lstnew((*stack)->content));
	stack_rev->next = NULL;
	temp = (*stack)->next;
	while (temp)
	{
		ft_lstadd_front(&stack_rev, ft_lstnew(temp->content));
		temp = temp->next;
	}
	temp = *stack;
	*stack = stack_rev;
	free_stack(&temp);
}

void	rotate_rotate(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
