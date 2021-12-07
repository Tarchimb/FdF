/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:56:01 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/07 08:30:38 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/fdf.h"

int	ft_malloc_map(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!map)
		return (0);
	map->map_tab = malloc(sizeof(t_vertex *) * map->y_size + 1);
	if (!map->map_tab)
		return (0);
	while (i < map->y_size)
	{
		map->map_tab[i] = malloc(sizeof(t_vertex) * map->x_size);
		if (!map->map_tab[i])
		{
			ft_free_all((void **)map->map_tab);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_fill_map(t_map *map, char **line, int i)
{
	int	j;
	int	k;

	k = 0;
	j = 0;
	if (!line)		
		return ((int)ft_free_all((void **)map->map_tab));
	while (j < map->x_size)
	{
		map->map_tab[i][j].local.x = j;
		map->map_tab[i][j].local.y = i;
		map->map_tab[i][j].local.z = ft_atoi(line[j]);
		map->map_tab[i][j].local.color = ft_atoi_base(line[j], BASE_HEXA);
		j++;
		k = 0;
	}
	return (1);
}

int	ft_parsing_map(char *argv, t_map *map)
{
	char	**file;
	char	**line;
	int		i;
	int		tmp;

	tmp = 0;
	i = 0;
	if (!ft_count_line(argv, map) || !ft_malloc_map(map))
		return (0);
	file = ft_get_file(argv, map->y_size, map);
	if (!file)
		return (0);
	line = ft_split(file[i], ' ');
	while (file[i])
	{
		if (!ft_fill_map(map, line, i))
			return ((int)ft_free_all((void **)file));
		i++;
		ft_free_all((void**)line);
		line = ft_split(file[i], ' ');
	}
	map->map_tab[i] = NULL;
	ft_free_all((void**)file);
	return (1);
}
