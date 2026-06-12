/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicamp <danicamp@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:46:54 by gopiment          #+#    #+#             */
/*   Updated: 2026/06/09 17:14:32 by danicamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*input_index(t_list **stack_a, t_input *input)
{
	t_list	*current;
	t_list	*tmp;
	int		counter;

	current = *stack_a;
	while (current)
	{
		tmp = *stack_a;
		counter = 0;
		while (tmp)
		{
			if (tmp->content > current->content)
				counter++;
			tmp = tmp->next;
		}
		current->index = input->size - counter;
		current = current->next;
	}
	current = *stack_a;
	return (current);
}

void	fill_my_stack(char **args, t_list **stack_a, t_input input)
{
	int		counter;
	int		counter1;
	char	**split;

	counter = 0;
	if (input.flags.strategy != 0)
		counter++;
	if (input.flags.bench != 0)
		counter++;
	while (args[++counter])
	{
		if (ft_strchr(args[counter], ' '))
		{
			split = ft_split(args[counter], ' ');
			if (!split)
				error();
			counter1 = -1;
			while (split[++counter1])
				ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(split[counter1])));
			free_split(split);
		}
		else
			ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(args[counter])));
	}
	avoid_clones(stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_input	input;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	(void) argc;
	parsing(argv, &input);
	fill_my_stack(argv, &stack_a, input);
	input.size = ft_lstsize(stack_a);
	stack_a = input_index(&stack_a, &input);
	sort(&stack_a, &stack_b, &input);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
