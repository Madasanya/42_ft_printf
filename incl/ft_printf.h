/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:51:27 by mamuller          #+#    #+#             */
/*   Updated: 2021/10/25 22:51:29 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/incl/libft.h"

int	ft_printf(const char *format, ...);
int	ft_addr(char *add_c, unsigned long addr);
int	ft_print_addr(unsigned long addr);
int	ft_print_base(long long int nbr, char *base, int base_len);
int	ft_put_nbrbase(long long int nbr, char *base);
int	ft_handler_start(va_list arg, const char *format);
int	ft_char_handler(char c, char format);
int	ft_string_handler(char *string_format);
int	ft_numbers_handler(long long int number_format, char format);
int	ft_hex_handler(long long int hex_format, char format);

#endif