/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicamp <danicamp@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 02:33:40 by gopiment          #+#    #+#             */
/*   Updated: 2026/06/09 18:43:15 by danicamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

void	avoid_clones(t_list **stack)
{
	t_list	*current;
	t_list	*runner;

	current = *stack;
	while (current)
	{
		runner = *stack;
		while (runner)
		{
			if (runner->content == current->content && runner != current)
			{
				ft_lstclear(stack);
				error();
			}
			runner = runner->next;
		}
		current = current->next;
	}
}

void	free_split(char **split)
{
	int	counter;

	counter = -1;
	while (split[++counter])
		free(split[counter]);
	free(split);
}

int	validate_number(char *argument)
{
	int		counter;
	long	number;

	counter = 0;
	if (argument[counter] == '+' || argument[counter] == '-')
		counter++;
	if (!argument[counter])
		error();
	while (argument[counter])
	{
		if (!ft_isdigit(argument[counter]))
			return (0);
		counter++;
	}
	number = ft_atoi(argument);
	if (number > INT_MAX || number < INT_MIN)
		error();
	return (1);
}
