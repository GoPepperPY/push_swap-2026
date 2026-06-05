/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 02:19:43 by gopiment          #+#    #+#             */
/*   Updated: 2026/06/05 18:23:50 by gopiment         ###   ########.fr       */
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

void	check_strat(int flag)
{
	if (!flag)
		ft_putstr_fd("[bench] strategy: Adaptive\n", 2);
	if (flag == 1)
		ft_putstr_fd("[bench] strategy: Simple\n", 2);
	if (flag == 2)
		ft_putstr_fd("[bench] strategy: Medium\n", 2);
	if (flag == 3)
		ft_putstr_fd("[bench] strategy: Complex\n", 2);
}

void	bench(t_input *input)
{
	print_disorder(input->flags.disorder);
	check_strat(input->flags.strategy);
	ft_printf("[bench] total_ops: %d\n", input->flags.pa + input->flags.pb + \
input->flags.ra + input->flags.rb + input->flags.rr + \
input->flags.rra + input->flags.rrb + input->flags.rrr + input->flags.sa \
+ input->flags.sb + input->flags.ss);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		input->flags.sa, input->flags.sb, input->flags.ss,
		input->flags.pa, input->flags.pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		input->flags.ra, input->flags.rb, input->flags.rr,
		input->flags.rra, input->flags.rrb, input->flags.rrr);
}
