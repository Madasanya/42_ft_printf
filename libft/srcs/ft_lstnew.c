/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:48:31 by mamuller          #+#    #+#             */
/*   Updated: 2021/05/23 13:48:31 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	Allocates (with malloc(3)) and returns a new element. The variable
	’content’ is initialized with the value of the parameter ’content’.
	The variable ’next’ is initialized to NULL.
RETURN VALUE
	The new element.
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}
