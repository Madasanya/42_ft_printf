/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:29:05 by mamuller          #+#    #+#             */
/*   Updated: 2021/05/12 01:29:05 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	isdigit() checks for a digit (0 through 9).
RETURN VALUE
	The values returned are nonzero if the character c falls into the
	tested class, and zero if not.
*/

int	ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}
