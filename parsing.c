/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 23:39:52 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/10 05:02:41 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_flags_check(char **args, t_input **input)
{
	int	counter;

	counter = 0;
	(*input)->flags.bench = 0;
	(*input)->flags.strategy = 0;
	while(args[++counter])
	{
		if(!ft_strncmp(args[counter], "--bench", ft_strlen("--bench")) \
	&& !(*input)->flags.bench)
			(*input)->flags.bench = 1;
		else if(!ft_strncmp(args[counter], "--simple", ft_strlen("--simple")) \
	&& !(*input)->flags.strategy)
			(*input)->flags.strategy = 1;
		else if(!ft_strncmp(args[counter], "--medium", ft_strlen("--medium")) \
	&& !(*input)->flags.strategy)
			(*input)->flags.strategy = 2;
		else if(!ft_strncmp(args[counter], "--complex", ft_strlen("--complex")) \
	&& !(*input)->flags.strategy)
			(*input)->flags.strategy = 3;
		else if(!ft_strncmp(args[counter], "--adaptive", ft_strlen("--adaptive")) \
	&& !(*input)->flags.strategy)
			(*input)->flags.strategy = 4;
		else
			break;
	}
	return (1);
}

void	parsing(char **args, t_input *input)
{
	int	counter;

	counter = 0;
	input_flags_check(args, &input);
	if(input->flags.strategy != 0)
		counter++;
	if(input->flags.bench != 0)
		counter++;
	while(args[++counter])
		validate_number(args[counter]);
}