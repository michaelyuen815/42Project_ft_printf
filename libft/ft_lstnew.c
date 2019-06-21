/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 10:56:20 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/03 11:13:57 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**linked list function of creating a new node
**with assigning value (*content) and size (content_size)
**keep content_size 0 in node if content is NULL
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *ret;

	if (!(ret = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	ret->content = NULL;
	ret->content_size = 0;
	if (content)
	{
		if (!(ret->content = ft_memalloc((content_size))))
		{
			free(ret);
			return (NULL);
		}
		ft_memcpy(ret->content, (void*)content, content_size);
		ret->content_size = content_size;
	}
	ret->next = NULL;
	return (ret);
}
