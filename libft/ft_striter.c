/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:26:12 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/02 19:27:10 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**String functions of applying pointer function *f for each of pointer *s
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (!s || !f)
		return ;
	while (*s)
		f(s++);
}
