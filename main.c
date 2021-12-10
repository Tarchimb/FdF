/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:51:57 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/10 18:00:17 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"
#include "Includes/fdf.h"

void	print_tab(t_map map, int i)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < map.y_size)
	{
		x = 0;
		while (x < map.x_size)
		{
			if (i == 1)
				printf("%f, %f, %f, %d\n", map.map_tab[y][x].world.x, map.map_tab[y][x].world.y, map.map_tab[y][x].world.z, map.map_tab[y][x].world.color);
			else
				printf("%f, %f, %f, %d\n", map.map_tab[y][x].local.x, map.map_tab[y][x].local.y, map.map_tab[y][x].local.z, map.map_tab[y][x].local.color);
			x++;
		}
		printf("(%d)\n", y);
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_map	map;

	(void)argc;
	(void)argv;
	// if (argc != 2)
	// 	return (0);
	// map = ft_parsing_map(argv[1]);
	if (!(ft_parsing_map("test_maps/elem2.fdf", &map)))
		return (0);
	ft_convert_map_to_iso(&map);
	ft_new_window(&map);
	print_tab(map, 1);
	ft_free_all((void **)map.map_tab);
	return (0);
}