/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicamp <danicamp@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 04:44:31 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/22 16:29:36 by danicamp         ###   ########.fr       */
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

int	get_position(t_list	*stack, int	value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->content == value)
			break;
		pos++;
		stack = stack->next;
	}
	return (pos);
}

int    best_rotation(t_list *stack_a, t_list *stack_b)
{
    t_list  *current;
    int     pos;

    current = stack_b;
    pos = 0;
    while (current)
    {
        if (stack_a->content < current->content && stack_a->content > current->next->content)
            break ;
        pos++;
        current = current->next;
    }
    return (pos);
}

t_list    *find_max(t_list *stack)
{
    t_list  *current;
    t_list	*max;

    current = stack;
	max = stack;
    while (current)
    {
        if (current->content > max->content)
            max = current;
        current = current->next;
    }
    return (max);
}

t_list    *find_min(t_list *stack)
{
	t_list  *current;
    t_list	*min;

    current = stack;
	min = stack;
    while (current)
    {
        if (current->content < min->content)
            min = current;
        current = current->next;
    }
    return (min);
}
// ➜ ./push_swap 3 1 2 5 4

// void	simple(t_list **stack_a, t_list	**stack_b, t_input *input)
// {
// 	push_b(stack_a, stack_b, &input);
// 	push_b(stack_a, stack_b, &input);
// 	while(ft_lstsize((*stack_a)))
// 	{
// 		if ((*stack_a)->content < (*stack_b)->content && (*stack_a)->content > (*stack_b)->next->content/*  && ft_lstlast((*stack_b))->content < (*stack_a)->content */)
// 		{
// 			rb(stack_b, &input);void	simple(t_list **stack_a, t_list	**stack_b, t_input *input)
// 			push_b(stack_a, stack_b, &input);
// 		}
// 		else if ((*stack_a)->content < (*stack_b)->content && ft_lstlast((*stack_b))->content < (*stack_b)->content && ft_lstlast((*stack_b))->content > (*stack_a)->content)	
// 			push_b(stack_a, stack_b, &input);
// 		else if ((*stack_a)->content > (*stack_b)->content && ft_lstlast((*stack_b))->content < (*stack_b)->content && ft_lstlast((*stack_b))->content < (*stack_a)->content)
// 			push_b(stack_a, stack_b, &input);
// 		else
// 			rb(stack_b, &input);
// 	}
// 	if (find_max((*stack_b)) != (*stack_b))
// 	{
// 		if (best_rotation((*stack_b), (*stack_b)->content))
// 		{
// 			while(find_max((*stack_b)) != (*stack_b))
// 				rb(stack_b, &input);
// 		}
// 		else
// 		{
// 			while(find_max((*stack_b)) != (*stack_b))
// 				rrb(stack_b, &input);
// 		}
// 	}
// 	while(ft_lstsize((*stack_b)))
// 		push_a(stack_a, stack_b, &input);
// }

void	simple(t_list **stack_a, t_list	**stack_b, t_input *input)
{
	if (get_position((*stack_a) ,find_min((*stack_a))->content) < ft_lstsize((*stack_a)) / 2)
	{
		while (*stack_a != find_min((*stack_a)))
			ra(stack_a, &input);
		push_b(stack_a, stack_b, &input);
	}
	else
	{
		while (*stack_a != find_min((*stack_a)))
			rra(stack_a, &input);
		push_b(stack_a, stack_b, &input);
	}
	if (get_position((*stack_a) ,find_max((*stack_a))->content) < ft_lstsize((*stack_a)) / 2)
	{
		while (*stack_a != find_max((*stack_a)))
			ra(stack_a, &input);
		push_b(stack_a, stack_b, &input);
	}
	else
	{
		while (*stack_a != find_max((*stack_a)))
			rra(stack_a, &input);
		push_b(stack_a, stack_b, &input);
	}
}