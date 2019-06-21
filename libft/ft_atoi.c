/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:49:05 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/01 15:44:23 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**rewrite string function atoi in lib <string.h>,
**which returns integer found at the beginning of 1st parameter (*str)
**here's the behavior:
**Case 1: "123"		>> 123
**Case 2: "123.12"	>> 123 (return int)
**Case 3: "123abc"	>> 123 (ignore char)
**Case 4: "-123ab"	>> -123 (concern "+/-" sign)
**Case 5: " 123ab"	>> 123 (allow space/tab before num)
**Case 6: "ab123"	>> 0 (num must be at the beginning)
**Case 7: "- 123ab"	>> 0 (no space allowed between signed and number)
*/

int		ft_atoi(const char *str)
{
	int ret;
	int neg;

	ret = 0;
	neg = 1;
	while (*str && BL_SP(*str))
		str++;
	if (*str == '-' || *str == '+')
		neg = (*(str++) == '-' ? -1 : 1);
	while (ft_isdigit(*str))
		ret = ret * 10 + *(str++) - '0';
	return (ret * neg);
}
