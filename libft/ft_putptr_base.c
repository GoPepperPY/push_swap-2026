/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 17:54:58 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/08 17:37:20 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	pt2(unsigned long tmp, char *tmp_str, char *base)
{
	int	size;
	int	counter;

	counter = 0;
	size = ft_strlen(base);
	while (tmp > 0)
	{
		tmp_str[counter] = base[tmp % size];
		tmp = tmp / size;
		counter++;
	}
	while (--counter >= 0)
		write(1, &tmp_str[counter], 1);
}

void	ft_putpointer(unsigned long pointer)
{
	long	tmp;
	char	tmp_str[32];

	tmp = pointer;
	pt2(tmp, tmp_str, "0123456789abcdef");
}
