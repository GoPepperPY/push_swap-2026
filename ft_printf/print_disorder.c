/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_disorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 04:05:06 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/19 12:01:15 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_disorder(double disorder)
{
	int	integer_part;
	int	decimal_part;

	disorder *= 100;
	integer_part = (int)disorder;
	decimal_part = (int)((disorder - integer_part) * 100);
	ft_printf("[bench] disorder: %d.", integer_part);
	if (decimal_part < 10)
		ft_printf("0");
	ft_printf("%d%%\n", decimal_part);
}
