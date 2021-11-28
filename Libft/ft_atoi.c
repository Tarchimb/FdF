/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:36:40 by tarchimb          #+#    #+#             */
/*   Updated: 2021/11/04 08:16:25 by tarchimb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str, int *i)
{
	int	negative;
	int	r;

	negative = 0;
	r = 0;
	while (str[*i] == '\t' || str[*i] == '\n' || str[*i] == '\v'
		|| str[*i] == '\f' || str[*i] == '\r' || str[*i] == ' ')
		*i += 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			negative++;
		*i += 1;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		r = r * 10 + str[*i] - '0';
		*i += 1;
	}
	if (negative == 1)
		return (r * -1);
	return (r);
}
