/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_map_to_iso.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 08:09:55 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/09 12:51:04 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/fdf.h"

void	ft_convert(t_map *map, int *i, int *j)
{
	map->map_tab[*i][*j].world.x = ((map->map_tab[*i][*j].local.x
				+ map->map_tab[*i][*j].local.y) * map->distance) + map->midx;
	if (map->map_tab[*i][*j].local.z != 0)
		map->map_tab[*i][*j].world.z = (map->map_tab[*i][*j].local.z
				* 0.82 * (map->distance / 3) / 2);
	map->map_tab[*i][*j].world.y = (((map->map_tab[*i][*j].local.y
					- map->map_tab[*i][*j].local.x) / 2)
			* map->distance) + map->midy - map->map_tab[*i][*j].world.z;
	if (map->map_tab[*i][*j].local.color != 0)
		map->map_tab[*i][*j].world.color = map->map_tab[*i][*j].local.color;
	else
		map->map_tab[*i][*j].world.color = 15658734;
}

void	ft_convert_map_to_iso(t_map *map)
{
	int		i;
	int		j;

	if (map->y_size < 8)
		map->distance = 1;
	else
		map->distance = (((LARGEUR / map->x_size)
					+ (HAUTEUR / map->y_size)) / 2) / 2;
	map->midx = LARGEUR / 3;
	map->midy = HAUTEUR / 2;
	i = 0;
	j = 0;
	while (map->map_tab[i])
	{
		while (j < map->x_size)
		{
			ft_convert(map, &i, &j);
			j++;
		}
		j = 0;
		i++;
	}
}
