/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:35:45 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/03 17:35:46 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	pt2(long tmp, char *tmp_str, char *base)
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

void	ft_putnbr_base(unsigned int nbr, char *base)
{
	long	tmp;
	char	tmp_str[32];

	if (nbr == 0)
	{
		write(1, "0", 1);
		return ;
	}
	tmp = nbr;
	if (tmp < 0)
	{
		tmp = -tmp;
		write(1, "-", 1);
	}
	pt2(tmp, tmp_str, base);
}
