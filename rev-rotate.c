/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev-rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicamp <danicamp@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 22:58:38 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/16 09:15:24 by danicamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rev_rotate(t_list	**stack)
{
	t_list	*current;
	t_list	*last;
	t_list	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return;
	temp = *stack;
	current = *stack;
	while (current->next->next)
	{
		current = current->next;
	}
	last = ft_lstlast(*stack);
	*stack = last;
	(*stack)->next = temp;
	current->next = NULL;
}

void	rev_rotate_rotate(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
}
