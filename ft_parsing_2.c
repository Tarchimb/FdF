/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:57:41 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/02 13:34:49 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/fdf.h"

void	*ft_free_all(void **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

int	ft_count_int(const char *str, char charset)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i] && str[i] == charset)
		i++;
	if (str[i] != 0)
		count++;
	while (str[i])
	{
		if (str[i] == charset
			&& (str[i + 1] != charset && str[i + 1] != 0 && str[i + 1] != '\n'))
			count++;
		i++;
	}
	return (count);
}

int	ft_count_line(char *str, t_map *map)
{
	int		fd;
	char	*dest;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
	dest = get_next_line(fd);
	if (!dest)
		return (0);
	map->x_size = ft_count_int(dest, ' ');
	while (dest)
	{
		if (ft_count_int(dest, ' ') != map->x_size)
		{
			free(dest);
			return (0);
		}
		free(dest);
		dest = get_next_line(fd);
		map->y_size++;
	}
	free(dest);
	close (fd);
	return (map->y_size);
}

char	**ft_get_file(char *argv, int count_line, t_map *map)
{
	char	**file;
	int		i;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	file = malloc(sizeof(char *) * (count_line + 1));
	if (!file)
		return (ft_free_all((void **)map));
	while (i < count_line)
	{
		file[i] = get_next_line(fd);
		if (!file[i])
		{
			ft_free_all((void **)map);
			return (ft_free_all((void **)file));
		}
		i++;
	}
	file[i] = 0;
	close (fd);
	return (file);
}
