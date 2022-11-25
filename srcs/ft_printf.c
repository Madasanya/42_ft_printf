/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:44:27 by mamuller          #+#    #+#             */
/*   Updated: 2021/10/25 10:44:27 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

//gcc -Wall -Wextra -Werror ft_printf.c ../libft/libft.a && ./a.out

int	ft_printf(const char *format, ...)
{
	int				c_counter;
	va_list			arg;

	va_start(arg, format);
	c_counter = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			c_counter += ft_handler_start(arg, format);
		}
		else
			c_counter += ft_char_handler(*format, 'c');
		format++;
	}
	va_end(arg);
	return (c_counter);
}
