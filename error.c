/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 02:33:40 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/10 05:33:35 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("mamada parafuso!\n\n", 2);
	exit (1);
}

void	avoid_clones(t_list **stack)
{
	t_list	*current;
	t_list	*runner;

	current = *stack;
	while(current)
	{
		runner = *stack;
		while(runner)
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

void    validate_number(char *argument)
{
    int     counter;
    long    number;

    counter = 0;
    if (argument[counter] == '+' || argument[counter] == '-')
        counter++;
    if (!argument[counter])
        error();
    while (argument[counter])
    {
        if (!ft_isdigit(argument[counter]))
            error();
        counter++;
    }
    number = ft_atoi(argument);
    if (number > INT_MAX || number < INT_MIN)
        error();
}
