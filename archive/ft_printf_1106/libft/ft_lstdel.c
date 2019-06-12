/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 11:25:50 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/03 11:44:41 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**linked list function of deleting a linked list (pointer of *alst)
**given del pointer function (del)
**delete every single node with function ft_lstdelone
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *pre;

	if (!*alst)
		return ;
	tmp = *alst;
	while (tmp->next)
	{
		pre = tmp;
		tmp = tmp->next;
		ft_lstdelone(&pre, del);
	}
	ft_lstdelone(&tmp, del);
	*alst = NULL;
}
