/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:41:03 by mamuller          #+#    #+#             */
/*   Updated: 2021/10/25 18:41:03 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

int	ft_hex_handler(long long int hex_format, char format)
{
	if (hex_format < 0)
		hex_format = 4294967296 + hex_format;
	if (format == 'x')
		return (ft_put_nbrbase(hex_format, "0123456789abcdef"));
	else
		return (ft_put_nbrbase(hex_format, "0123456789ABCDEF"));
}

int	ft_numbers_handler(long long int number_format, char format)
{
	char	*string_format;
	int		c_counter;

	if (format == 'u')
	{
		if (number_format < 0)
			number_format = 4294967296 + number_format;
	}
	string_format = ft_itoa(number_format);
	ft_putstr_fd(string_format, 1);
	c_counter = ft_strlen(string_format);
	free(string_format);
	return (c_counter);
}

int	ft_string_handler(char *string_format)
{
	if (string_format == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	else
		ft_putstr_fd(string_format, 1);
	return (ft_strlen(string_format));
}

int	ft_char_handler(char c, char format)
{
	if (format == '%')
		ft_putchar_fd('%', 1);
	else
		ft_putchar_fd(c, 1);
	return (1);
}

int	ft_handler_start(va_list arg, const char *format)
{
	int	c_counter;

	c_counter = 0;
	if (*format == '%')
		c_counter = c_counter + ft_char_handler('%', *format);
	else if (*format == 'c')
		c_counter += ft_char_handler((char)va_arg(arg, int), *format);
	else if (*format == 's')
		c_counter += ft_string_handler(va_arg(arg, char *));
	else if (*format == 'i' || *format == 'd' || *format == 'u')
		c_counter += ft_numbers_handler(va_arg(arg, int), *format);
	else if (*format == 'x' || *format == 'X')
		c_counter += ft_hex_handler((long long int)va_arg(arg, int), *format);
	else if (*format == 'p')
		c_counter += ft_print_addr((unsigned long)va_arg(arg, void *));
	return (c_counter);
}
