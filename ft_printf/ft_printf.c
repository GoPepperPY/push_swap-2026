/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 13:50:49 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/25 19:13:49 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flags(va_list args, int c)
{
	if (c == 'c')
	{
		c = va_arg(args, int);
		return (write(2, &c, 1));
	}
	else if (c == 's')
		return (print_string(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (print_int(va_arg(args, int)));
	else if (c == 'u')
		return (print_uint(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (print_hex(va_arg(args, unsigned int), c));
	else if (c == 'p')
		return (print_pointer(va_arg(args, unsigned long)));
	else if (c == '%')
		return (write(2, "%", 1));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		counter;

	counter = 0;
	va_start(args, input);
	while (input[0])
	{
		if (input[0] == '%')
		{
			input++;
			counter += check_flags(args, input[0]);
		}
		else
			counter += write(2, &input[0], 1);
		input++;
	}
	va_end(args);
	return (counter);
}

int	countdigit(int number, int base)
{
	int	length;

	if (number == INT_MIN)
		return (11);
	if (number == 0)
		return (1);
	length = 0;
	if (number < 0)
	{
		length++;
		number *= -1;
	}
	while (number > 0)
	{
		number /= base;
		length++;
	}
	return (length);
}

int	countdigithex(unsigned int number, unsigned int base)
{
	int	length;

	if (number == 0)
		return (1);
	length = 0;
	while (number > 0)
	{
		number /= base;
		length++;
	}
	return (length);
}

int	pointer_length(unsigned long pointer)
{
	int	length;

	length = 0;
	while (pointer != 0)
	{
		length++;
		pointer = pointer / 16;
	}
	return (length);
}
