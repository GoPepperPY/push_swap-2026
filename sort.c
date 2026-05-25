/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicamp <danicamp@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 02:22:44 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/25 17:14:42 by danicamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack_a)
{
	while(stack_a->next)
	{
		if(stack_a->content > stack_a->next->content)
			return(0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	init(t_input *input)
{
	input->flags.sa = 0;
	input->flags.sb = 0;
	input->flags.ra = 0;
	input->flags.rb = 0;
	input->flags.rr = 0;
	input->flags.rra = 0;
	input->flags.rrb = 0;
	input->flags.pa = 0;
	input->flags.pb = 0;
	input->flags.rrr = 0;
	input->flags.ss = 0;
}

void	sort(t_list **stack_a, t_list **stack_b, t_input *input)
{
	if (input->flags.bench)
		init(input);
	if (is_sorted((*stack_a)) || input->size == 1)
		return ;
	// input->flags.disorder = compute_disorder((*stack_a));
	// if (ft_lstsize((*stack_a)) <= 3)
	// 	check_small(stack_a, input);
	// else if (input->flags.strategy == 1 || input->flags.disorder < 0.2)
	simple(stack_a, stack_b, input);
	// else if (input->flags.strategy == 2 || (input->flags.disorder >= 0.2 && 
	// 	input->flags.disorder < 0.5))
	// 	medium(stack_a, stack_b, input);
	// else if (input->flags.strategy == 3 || input->flags.disorder >= 0.5)
	// 	medium(stack_a, stack_b, input);
	if (input->flags.bench)
		bench(input);
}
