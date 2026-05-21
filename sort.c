/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 02:22:44 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/21 22:47:28 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack_a)
{
	while(stack_a->next->content)
	{
		if(stack_a->content > stack_a->next->content)
			return(0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	sort(t_list **stack_a, t_list **stack_b, t_input *input)
{
	input->flags.disorder = compute_disorder((*stack_a));
	if (input->size <= 3)
		check_small(stack_a, input);
	// else if (input->flags.strategy == 1 || input->flags.disorder < 0.2)
	simple(stack_a, stack_b, input);
	// else if (input->flags.strategy == 2 || input->flags.disorder >= 0.2 && \
	// 	input->flags.disorder < 0.5)
	// 	medium();
	// else if (input->flags.strategy == 3 || input->flags.disorder >= 0.5)
	// complex(stack_a, stack_b, input);
}
