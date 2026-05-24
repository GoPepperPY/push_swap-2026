/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 02:19:43 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/24 07:40:33 by gopiment         ###   ########.fr       */
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

void check_strat(int flag)
{
	if(!flag)
		ft_putstr_fd("Adaptive\n", 2);
	if(flag == 1)
		ft_putstr_fd("Simple\n", 2);
	if(flag == 2)
		ft_putstr_fd("Medium\n", 2);
	if(flag == 3)
		ft_putstr_fd("Complex\n", 2);
}

void bench(t_input *input)
{
	write(2, "[bench] disorder: ", ft_strlen("[bench] disorder: "));
	ft_putnbr_fd((int)input->flags.disorder, 2);
	write(2, ".", 1);
	if ((int)((input->flags.disorder - (int)input->flags.disorder) * 100) < 10)
		write(2, "0", 1);
	ft_putnbr_fd((int)((input->flags.disorder - (int)input->flags.disorder) * 100), 2);
	write(2, "%%", 1);
	write(2, "\n", 1);
	write(2, "[bench] strategy: ", ft_strlen("[bench] strategy: "));
	check_strat(input->flags.strategy);
	write(2, "[bench] total_ops: ", ft_strlen("[bench] total_ops: "));
	ft_putnbr_fd(input->flags.sa + input->flags.sb + input->flags.ra + \
		input->flags.rb + input->flags.rr + input->flags.rra + \
		input->flags.rrb + input->flags.pa + input->flags.pb + \
		input->flags.rrr + input->flags.ss, 2);
	write(2, "\n[bench]", ft_strlen("\n[bench]"));
	write(2, " sa : ", 6);
	ft_putnbr_fd(input->flags.sa, 2);
	write(2, " sb :", 6);
	ft_putnbr_fd(input->flags.sb, 2);
	write(2, " ra : ", 6);
	ft_putnbr_fd(input->flags.ra, 2);
	write(2, " rb : ", 6);
	ft_putnbr_fd(input->flags.rb, 2);
	write(2, " rr : ", 6);
	ft_putnbr_fd(input->flags.rr, 2);
	write(2, "\n[bench]", ft_strlen("\n[bench]"));
	write(2, " rra : ", 7);
	ft_putnbr_fd(input->flags.rra, 2);
	write(2, " rrb :", 7);
	ft_putnbr_fd(input->flags.rrb, 2);
	write(2, " pa : ", 6);
	ft_putnbr_fd(input->flags.pa, 2);
	write(2, " pb :", 6);
	ft_putnbr_fd(input->flags.pb, 2);
	write(2, " rrr : ", 7);
	ft_putnbr_fd(input->flags.rrr, 2);
	write(2, " ss :", 6);
	ft_putnbr_fd(input->flags.ss, 2);
}