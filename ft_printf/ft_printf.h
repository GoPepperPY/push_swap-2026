/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 13:51:01 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/09 18:57:41 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"

int	ft_printf(const char *input, ...);
int	check_flags(va_list args, int c);
int	print_string(char *c);
int	print_int(long c);
int	print_uint(unsigned int c);
int	print_hex(unsigned int c, int type);
int	countdigit(int number, int base);
int	countdigithex(unsigned int number, unsigned int base);
int	print_pointer(unsigned long pointer);
int	pointer_length(unsigned long pointer);

#endif