/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 02:19:43 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/17 04:10:31 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_list *stack)
{
	t_list	*current;
	t_list	*runner;
	int		mistakes;
	int		total;

	mistakes = 0;
	total = 0;
	current = stack;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			total++;
			if (current->index > runner->index)
				mistakes++;
			runner = runner->next;
		}
		current = current->next;
	}
	return ((double)mistakes / total);
}

// void bench(t_list **stack_a, )