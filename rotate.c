/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicamp <danicamp@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 22:58:41 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/16 08:45:42 by danicamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rotate(t_list	**stack)
{
	t_list	*temp;
	t_list	*current;

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
