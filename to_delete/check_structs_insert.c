/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_structs_insert.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 02:37:18 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/19 11:54:34 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_list(t_list *stack_a, t_list *stack_b)
{
	t_list *current = stack_a;
	t_list *current2 = stack_b;

	ft_printf("\n\n<-----!PRINT STACKS!----->\n\n");
	ft_printf("STACK A: \n");
	while (current != NULL)
	{
		ft_printf("%d | indice-> %d\n", current->content, current->index);
		current = current->next;
	}
	ft_printf("\n\nSTACK b: \n");
	while (current2 != NULL)
	{
		ft_printf("%d\n", current2->content);
		current2 = current2->next;
	}
	ft_printf("\n\n");
}

void	print_inputflags(t_input *input)
{
	ft_printf("\n\n<-----!PRINT FLAGS!----->\n\n");
	ft_printf("FLAG:\n");
	ft_printf("\t[1] --simple\n");
	ft_printf("\t[2] --medium\n");
	ft_printf("\t[3] --complex\n");
	ft_printf("\t[4] --adaptive\n\n\n");
	ft_printf("BENCH [%d]\n", input->flags.bench);
	ft_printf("FLAGS [%d]\n", input->flags.strategy);
	ft_printf("NUMBERS ON STACK [%d]\n", input->size);
}

void 	print_parsing(t_input *input, t_list *stack_a, t_list *stack_b)
{
	ft_printf("\n\n<-----!PRINT PARSING DISTRIBUTION!----->\n\n");
	print_inputflags(input);
	print_list(stack_a, stack_b);
}