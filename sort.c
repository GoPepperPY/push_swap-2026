/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 02:22:44 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/17 07:04:13 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **stack_a, t_list **stack_b, t_input *input)
{
	(void) stack_b;
	if (input->flags.bench)
		input->flags.disorder = compute_disorder((*stack_a));
	if (input->size <= 3)
		check_small(stack_a, input);
	// if (input->flags.strategy == 2)
	// 	medium(stack_a, stack_b, input);
}
