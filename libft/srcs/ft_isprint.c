/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:44:00 by mamuller          #+#    #+#             */
/*   Updated: 2021/05/12 01:44:00 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	isprint() checks for any printable character including space.
RETURN VALUE
	The values returned are nonzero if the character c falls into the
	tested class, and zero if not.
*/

int	ft_isprint(int c)
{
	return (c > 31 && c < 127);
}
