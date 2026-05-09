/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:46:54 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/09 21:10:22 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	fill_my_stack(char **arguments, t_list **stack_a)
{
	int	counter;

	counter = -1;
	while(arguments[++counter])
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(arguments[counter])));
}

void	print_list(t_list *list)
{
	t_list *current = list;

	while (current != NULL)
	{
		ft_printf("Value: %d\n", current->content);
		current = current->next;
	}
}

int main(int argc, char **argv)
{
    t_list  *stack_a;
    t_list  *stack_b;

    (void)argc;
    stack_a = NULL;
    stack_b = NULL;
    fill_my_stack(++argv, &stack_a);
    print_list(stack_a);
    return (0);
}
