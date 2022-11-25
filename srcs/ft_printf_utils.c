/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:41:12 by mamuller          #+#    #+#             */
/*   Updated: 2021/10/25 18:41:12 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

int	ft_addr(char *addr_c, unsigned long addr)
{
	int	i;

	i = 0;
	while (addr > 0)
	{
		addr_c[i] = addr % 16;
		if (addr_c[i] < 10)
			addr_c[i] += '0';
		else
			addr_c[i] += 87;
		addr = addr / 16;
		i++;
	}
	addr_c[i] = 'x';
	addr_c[i + 1] = '0';
	i++;
	return (i);
}

int	ft_print_addr(unsigned long addr)
{
	char	addr_c[20];
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	if (addr == 0)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	i = ft_addr(&addr_c[0], addr);
	while (i >= 0)
	{
		ft_putchar_fd(addr_c[i], 1);
		counter++;
		i--;
	}
	return (counter);
}

int	ft_print_base(long long int nbr, char *base, int base_len)
{
	int	counter;

	counter = 1;
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		counter++;
		nbr = nbr * (-1);
	}
	if (nbr / base_len > 0)
		counter = counter + ft_print_base(nbr / base_len, base, base_len);
	ft_putchar_fd(base[nbr % base_len], 1);
	return (counter);
}

int	ft_put_nbrbase(long long int nbr, char *base)
{
	int	counter;
	int	base_len;

	counter = 0;
	base_len = ft_strlen(base);
	counter = ft_print_base(nbr, base, base_len);
	return (counter);
}
