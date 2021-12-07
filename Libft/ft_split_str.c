/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:01:58 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/01 14:28:15 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_base(char	str, char	*charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (str == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strddup(char *src, char *charset, int *i)
{
	char	*tab;
	int		j;
	int		size;

	j = 0;
	while (ft_check_base(src[*i], charset) == 1)
		*i += 1;
	size = *i;
	while (ft_check_base(src[size], charset) == 0 && src[size] != '\0')
		size++;
	size -= *i;
	tab = malloc(sizeof(char) * (size + 1));
	if (tab == 0)
		return (0);
	while (ft_check_base(src[*i], charset) == 0 && src[*i] != '\0')
	{
		tab[j] = src[*i];
		*i += 1;
		j++;
	}
	tab[j] = '\0';
	return (tab);
}

static int	ft_count_malloc(char *charset, const char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (ft_check_base(s[i], charset) == 1)
		{
			i++;
			if (ft_check_base(s[i], charset) == 0)
			{
				j++;
			}
		}
		if (s[i])
			i++;
	}
	if (j == 0)
		return (2);
	return (j + 1);
}

static char	**ft_fonction_if(char *str)
{
	int		i;
	char	**tab;

	i = 0;
	while (str[i])
		i++;
	tab = malloc (sizeof(char *) * 2);
	if (tab == 0)
		return (0);
	tab[0] = malloc(sizeof(char) * (i + 1));
	if (tab[0] == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		tab[0][i] = str[i];
		i++;
	}
	tab[0][i] = '\0';
	tab[1] = 0;
	return (tab);
}

char	**ft_split_str(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (charset[i] == '\0')
		return (ft_fonction_if(str));
	tab = malloc (sizeof (char *) * ft_count_malloc(str, charset));
	if (tab == 0)
		return (0);
	while (j < ft_count_malloc(str, charset) - 1)
	{
		tab[j] = ft_strddup(str, charset, &i);
		if (!tab[j])
		{
			j = 0;
			while (tab[j++])
				free(tab[j]);
			return (NULL);
		}
		j++;
	}
	tab[j] = 0;
	return (tab);
}