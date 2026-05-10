/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:46:54 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/10 05:35:25 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_my_stack(char **args, t_list **stack_a, int argc, t_input input)
{
	int	counter;

	(void) argc;
	// if(argc == 2)
	// 	args = ft_split(args[0], ' ');
	counter = 0;
	if(input.flags.strategy != 0)
		counter++;
	if(input.flags.bench != 0)
		counter++;
	while(args[++counter])
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(args[counter])));
	avoid_clones(stack_a);
}

int main(int argc, char **argv)
{
    t_list  *stack_a;
    t_list  *stack_b;
	t_input	input;

    stack_a = NULL;
    stack_b = NULL;

	parsing(argv, &input);
    fill_my_stack(argv, &stack_a, argc, input);
	input.size = ft_lstsize(stack_a);

	// CHECK PARSING
	print_parsing(&input, stack_a, stack_b);
    return (0);
}
