/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_map_to_iso.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 08:09:55 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/07 08:36:09 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/fdf.h"

void	ft_convert_map_to_iso(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map_tab[i])
	{
		while (j < map->x_size)
		{
			map->map_tab[i][j].world.x = map->map_tab[i][j].local.x
				+ map->map_tab[i][j].local.y;
			map->map_tab[i][j].world.y = (map->map_tab[i][j].local.y
					- map->map_tab[i][j].local.x) / 2;
			j++;
		}
		j = 0;
		i++;
	}
}