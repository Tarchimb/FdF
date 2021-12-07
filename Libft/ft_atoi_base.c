/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 08:51:47 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/01 10:33:59 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_str(char *str, int *i)
{
	int	j;

	j = 0;
	while ((str[*i] >= 9 && str[*i] <= 13) || (str[*i] == 32))
		*i += 1;
	while (str[*i] >= '0'  && str[*i] <= '9')
		*i += 1;
	if (str[*i] == ',')
		*i += 1;
	if (str[*i] == '0' && str[*i + 1] == 'x')
		*i += 2;
	return (0);
}

int	ft_strstr(char *str, char to_find, int *j)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == to_find)
			return (1);
		*j += 1;
		i++;
	}
	return (0);
}

int	ft_check_base(char	*str)
{
	int	i;
	int	o;

	i = 0;
	while (str[i])
	{
		o = i + 1;
		while (str[o])
		{
			if (str[i] == str[o])
				 return (1);
			o++;
		}
		if (str[i] == '+' || str[i] == ' ' || str[i] == '\n'
			|| str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int	ft_after_base(char	*base, char	*str, int	*i)
{
	int	o;

	o = 0;
	while (base[o])
	{
		if (str[*i] == base[o])
		{
			return (1);
		}
		o++;
	}
	return (0);
}

int	ft_atoi_base(char	*str, char	*base)
{
	int	i;
	int	r;
	int	j;

	j = 0;
	i = 0;
	r = 0;
	ft_check_str(str, &i);
	if (ft_check_base(base) == 1)
		return (0);
	while (str[i] != '\0' && ft_after_base(base, str, &i) == 1)
	{
		while (base[j] != str[i])
			j++;
		r = r * ft_strlen(base) + j;
		i++;
		j = 0;
	}
	i = 0;
	if (ft_check_str(str, &i) == 1)
		return (r * -1);
	else
		return (r);
}
