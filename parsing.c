/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 23:39:52 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/17 01:43:54 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_flags_check(char **args, t_input **input)
{
	int	counter;

	counter = 0;
	(*input)->flags.bench = 0;
	(*input)->flags.strategy = 0;
	while (args[++counter])
	{
		if (!ft_strncmp(args[counter], "--bench", ft_strlen("--bench")) \
&& !(*input)->flags.bench)
			(*input)->flags.bench = 1;
		else if (!ft_strncmp(args[counter], "--simple", ft_strlen("--simple")) \
&& !(*input)->flags.strategy)
			(*input)->flags.strategy = 1;
		else if (!ft_strncmp(args[counter], "--medium", ft_strlen("--medium")) \
&& !(*input)->flags.strategy)
			(*input)->flags.strategy = 2;
		else if (!ft_strncmp(args[counter], "--complex", ft_strlen("--complex")) \
&& !(*input)->flags.strategy)
			(*input)->flags.strategy = 3;
		else if (!ft_strncmp(args[counter], "--adaptive", \
ft_strlen("--adaptive")) && !(*input)->flags.strategy)
			(*input)->flags.strategy = 4;
		else
			break ;
	}
	return (1);
}

static void	parse_arg(char *arg)
{
	char	**split;
	int		counter;

	if (!ft_strchr(arg, ' '))
	{
		validate_number(arg);
		return ;
	}
	split = ft_split(arg, ' ');
	if (!split)
		error();
	counter = -1;
	while (split[++counter])
		validate_number(split[counter]);
	free_split(split);
}

void	parsing(char **args, t_input *input)
{
	int	counter;

	counter = input_flags_check(args, &input);
	while (args[counter])
	{
		parse_arg(args[counter]);
		counter++;
	}
}
