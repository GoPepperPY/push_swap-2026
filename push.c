/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 22:58:45 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/25 19:08:32 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **stack_a, t_list **stack_b, t_input **input)
{
	t_list	*current;

	current = *stack_b;
	*stack_b = current->next;
	ft_lstadd_front(stack_a, current);
	write(1, "pa\n", 3);
	if ((*input)->flags.bench)
		(*input)->flags.pa++;
}

void	push_b(t_list **stack_a, t_list **stack_b, t_input **input)
{
	t_list	*current;

	current = *stack_a;
	*stack_a = current->next;
	ft_lstadd_front(stack_b, current);
	write(1, "pb\n", 3);
	if ((*input)->flags.bench)
		(*input)->flags.pb++;
}
