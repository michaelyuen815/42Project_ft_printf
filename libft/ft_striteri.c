/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:27:39 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/02 20:52:46 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**String functions of applying function *f for each of pointer *s with index i
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;

	if (!s || !f)
		return ;
	i = -1;
	while (s[++i])
		f(i, s + i);
}
