/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev-rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 22:58:38 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/17 05:49:15 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list	**stack, t_input **input)
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
	ft_printf("rra\n");
	if ((*input)->flags.bench)
		(*input)->flags.rra++;
}

void	rrb(t_list	**stack, t_input **input)
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
	ft_printf("rrb\n");
	if ((*input)->flags.bench)
		(*input)->flags.rrb++;
}

void	rev_rotate_rotate(t_list **stack_a, t_list **stack_b, t_input **input)
{
	rra(stack_a, input);
	rrb(stack_b, input);
	ft_printf("rrr\n");
	if ((*input)->flags.bench)
		(*input)->flags.rrr++;
}
