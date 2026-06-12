/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicamp <danicamp@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:55:07 by gopiment          #+#    #+#             */
/*   Updated: 2026/06/09 18:29:29 by danicamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atoi(const char *nptr)
{
	long	counter;
	long	saver;
	long	rest;

	rest = 0;
	saver = 1;
	counter = 0;
	while (nptr[counter] == 32 || (nptr[counter] >= 9 && nptr[counter] <= 13))
		counter++;
	if ((nptr[counter] == '-' || nptr[counter] == '+') && ft_strlen(nptr) > 1)
	{
		if (nptr[counter] == '-')
			saver = -1;
		counter++;
	}
	while (nptr[counter] >= '0' && nptr[counter] <= '9')
	{
		rest = (nptr[counter] - 48) + (rest * 10);
		counter++;
	}
	if (nptr[counter] != '\0')
		error();
	return (rest * saver);
}
