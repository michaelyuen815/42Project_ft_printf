/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 11:14:30 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/03 11:40:20 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**linked list function of deleting a node (pointer of *alst)
**given del pointer function (del)
**Step 1: run del pointer function for clearing content
**Step 2: free memory of node
**Step 3: set value of node to NULL
*/

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (!*alst)
		return ;
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
