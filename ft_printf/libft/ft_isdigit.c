/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:14:22 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/01 15:17:38 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**check single char is number
**if yes, return 1. otherwise, return 0
**number characters are between 48 and 57
*/

int	ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}
