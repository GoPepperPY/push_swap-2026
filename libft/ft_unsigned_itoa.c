/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicamp <danicamp@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:06:04 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/15 08:57:29 by danicamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	absolute_value(unsigned int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static unsigned int	ft_digit_count(unsigned int nbr)
{
	int	counter;

	counter = 0;
	if (nbr <= 0)
		counter++;
	while (nbr != 0)
	{
		counter++;
		nbr /= 10;
	}
	return (counter);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*string;
	int		counter;

	counter = ft_digit_count(n);
	string = malloc(sizeof(char) * (counter + 1));
	if (!string)
		return (NULL);
	string[counter--] = '\0';
	if (n < 0)
		string[0] = '-';
	else if (n == 0)
		string[0] = '0';
	while (n != 0)
	{
		string[counter--] = absolute_value(n % 10) + '0';
		n /= 10;
	}
	return (string);
}
