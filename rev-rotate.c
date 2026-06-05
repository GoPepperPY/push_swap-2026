/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev-rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 22:58:38 by gopiment          #+#    #+#             */
/*   Updated: 2026/06/05 18:24:08 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_list	**stack)
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

void	rra(t_list	**stack, t_input **input)
{
	rev_rotate(stack);
	write(1, "rra\n", 4);
	if ((*input)->flags.bench)
		(*input)->flags.rra++;
}

void	rrb(t_list	**stack, t_input **input)
{
	rev_rotate(stack);
	write(1, "rrb\n", 4);
	if ((*input)->flags.bench)
		(*input)->flags.rrb++;
}

void	rev_rotate_rotate(t_list **stack_a, t_list **stack_b, t_input **input)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
	if ((*input)->flags.bench)
		(*input)->flags.rrr++;
}
