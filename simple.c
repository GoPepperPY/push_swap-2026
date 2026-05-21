/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 04:44:31 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/22 00:31:19 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	simple(t_list **stack_a, t_list	**stack_b, t_input *input)
// {
// 	while(!is_sorted((*stack_a)))
// 	{
// 		while(ft_lstsize((*stack_a)) > 0)
// 		{
// 			if(ft_lstsize((*stack_a)) > 0)
// 				push_b(stack_a, stack_b, &input);
// 			if (ft_lstsize((*stack_a)) >= 2 && ((*stack_a)->content > (*stack_a)->next->content))
// 				sa(stack_a, &input);
// 			if (ft_lstsize((*stack_b)) >= 2 && ((*stack_b)->content < (*stack_b)->next->content))
// 				sb(stack_b, &input);
// 		}	
// 		while(ft_lstsize((*stack_b)) > 0)
// 		{
// 			if(ft_lstsize((*stack_b)) > 0)
// 				push_a(stack_a, stack_b, &input);
// 			if (ft_lstsize((*stack_b)) >= 2 && ((*stack_b)->content < (*stack_b)->next->content))
// 				sb(stack_b, &input);
// 			if (ft_lstsize((*stack_a)) >= 2 && ((*stack_a)->content > (*stack_a)->next->content))
// 				sa(stack_a, &input);
// 		}
// 	}
// }

int    best_rotation(t_list *stack_b, int value)
{
    t_list  *current;
    int     pos;
    int     size;

    current = stack_b;
    pos = 0;
    size = ft_lstsize(stack_b);
    while (current)
    {
        if (current->content < value)
            break ;
        pos++;
        current = current->next;
    }
    if (pos <= size / 2)
        return (pos);
    else
        return (-(size - pos));
}

int    find_max(t_list *stack)
{
    t_list  *current;
    int		max;

    current = stack;
    while (current)
    {
        if (current->content > max)
            max = current->content;
        current = current->next;
    }
    return (max);
}

void	simple(t_list **stack_a, t_list	**stack_b, t_input *input)
{
	int	counter;

	push_b(stack_a, stack_b, &input);
	push_b(stack_a, stack_b, &input);
	if((*stack_b)->content < (*stack_b)->next->content)
		rb(stack_b, &input);
	while(ft_lstsize((*stack_a)))
	{
		counter = -1;
		if (best_rotation((*stack_b), (*stack_a)->content) > 0)
		{
			while((*stack_a)->content < (*stack_b)->content && ++counter < ft_lstsize((*stack_b)))
				rb(stack_b, &input);
		}
		else if (best_rotation((*stack_b), (*stack_a)->content) < 0)
		{
			while((*stack_a)->content < (*stack_b)->content && ++counter < ft_lstsize((*stack_b)))
				rrb(stack_b, &input);
		}
		// if ((*stack_b)->content < ft_lstlast((*stack_b))->content && (*stack_b)->content > (*stack_b)->next->content)
			push_b(stack_a, stack_b, &input);
		if(best_rotation((*stack_b), find_max((*stack_b))) > 0)
		{
			while ((*stack_b)->content < ft_lstlast((*stack_b))->content)
				rrb(stack_b, &input);
		}
		else if (best_rotation((*stack_b), find_max((*stack_b))) < 0)
		{
			while((*stack_b)->content < ft_lstlast((*stack_b))->content)
				rb(stack_b, &input);
		}
	}
	// while(ft_lstsize((*stack_b)))
	// 	push_a(stack_a, stack_b, &input);
}
