/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 18:52:29 by gopiment          #+#    #+#             */
/*   Updated: 2026/06/05 19:47:14 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*read_line(int fd)
{
	char	*line;
	char	buf[2];
	int		i;
	int		ret;

	line = malloc(256);
	if (!line)
		return (NULL);
	i = 0;
	while ((ret = read(fd, buf, 1)) > 0)
	{
		line[i++] = buf[0];
		if (buf[0] == '\n')
			break ;
	}
	if (ret == 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}

void	fill_my_stack_checker(char **args, t_list **stack_a, t_input input)
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

void	execute_op(char *line, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(line, "ra\n", 3) == 0)
		ra_checker(stack_a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb_checker(stack_b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rotate_rotate_checker(stack_a, stack_b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra_checker(stack_a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb_checker(stack_b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rev_rotate_rotate_checker(stack_a, stack_b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		push_a_checker(stack_a, stack_b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push_b_checker(stack_a, stack_b);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		sa_checker(stack_a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb_checker(stack_b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		swap_swap_checker(stack_a, stack_b);
	else
		exit(1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_input	input;
	char	*line;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	parsing(argv, &input);
	fill_my_stack_checker(argv, &stack_a, input);
	if (!stack_a)
		return (0);
	line = read_line(0);
	while (line)
	{
		execute_op(line, &stack_a, &stack_b);
		free(line);
		line = read_line(0);
	}
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}