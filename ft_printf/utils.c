/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:23:29 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/03 17:36:59 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *c)
{
	if (!c)
		return (write(1, "(null)", 6));
	return (write(1, c, ft_strlen(c)));
}

int	print_int(long c)
{
	ft_putnbr_fd(c, 1);
	return (countdigit(c, 10));
}

int	print_uint(unsigned int c)
{
	ft_putnbr_fd(c, 1);
	return (countdigithex(c, 10));
}

int	print_hex(unsigned int c, int type)
{
	if (type == 'x')
		ft_putnbr_base(c, "0123456789abcdef");
	if (type == 'X')
		ft_putnbr_base(c, "0123456789ABCDEF");
	return (countdigithex(c, 16));
}

int	print_pointer(unsigned long pointer)
{
	int	length;

	length = 0;
	if (pointer == 0)
		length = length + write(1, "(nil)", 5);
	else
	{
		length += write(1, "0x", 2);
		ft_putpointer(pointer);
		length += pointer_length(pointer);
	}
	return (length);
}
