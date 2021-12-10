/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:47:54 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/10 18:15:51 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		pixel;

	pixel = (y * data->line_length + x * (data->bits_per_pixel / 8));
	if (pixel < 0)
		return ;
	dst = data->addr + pixel;
	*(unsigned int *)dst = color;
}

int	ft_draw_line(t_data *img, t_val4 start, t_val4 end)
{
	t_int	i;

	i.deltacolor = 0;
	i.deltax = end.x - start.x;
	i.deltay = end.y - start.y;
	i.pixels = sqrt((i.deltax * i.deltax) + (i.deltay * i.deltay));
	i.deltax /= i.pixels;
	i.deltay /= i.pixels;
	i.pixelx = start.x - (LARGEUR / 8);
	i.pixely = start.y;
	if (end.color != start.color)
		i.deltacolor = (end.color - start.color) / (i.pixels * 16);
	while (i.pixels)
	{
		my_mlx_pixel_put(img, i.pixelx, i.pixely, start.color);
		i.pixelx += i.deltax;
		i.pixely += i.deltay;
		--i.pixels;
		start.color = start.color + i.deltacolor;
	}
	return (0);
}

// int	ft_check_position(t_map *map, int *x, int *y, int check)
// {
// 	if (!(map->map_tab[*y][*x].local.x < 0 || map->map_tab[*y][*x].local.x
// 		> LARGEUR || map->map_tab[*y][*x].local.y < 0
// 		|| map->map_tab[*y][*x].local.x > HAUTEUR))
// 	{
// 		if (check == 0)
// 			if ((*x < map->x_size - 1)
// 			&& (!(map->map_tab[*y][*x + 1].local.x < 0)
// 			|| (map->map_tab[*y][*x + 1].local.x > LARGEUR)
// 			|| (map->map_tab[*y][*x + 1].local.y < 0)
// 			|| (map->map_tab[*y][*x + 1].local.y > HAUTEUR)))
// 				return (0);
// 		if (check == 1)
// 			if ((*y < map->y_size - 1)
// 			&& (!(map->map_tab[*y + 1][*x].local.x < 0)
// 			|| (map->map_tab[*y + 1][*x].local.x > LARGEUR)
// 			|| (map->map_tab[*y + 1][*x].local.y < 0)
// 			|| (map->map_tab[*y + 1][*x].local.y > HAUTEUR)))
// 				return (0);
// 	}
// 	return (1);
// }

// static void	check_pixel_put(t_program *fdf, int x, int y)
// {
// 	if (!(fdf->map.tab[y][x].world.x < 0 - fdf->img.x
// 		|| fdf->map.tab[y][x].world.x > fdf->win.width - fdf->img.x
// 		|| fdf->map.tab[y][x].world.y < 0 - fdf->img.y
// 		|| fdf->map.tab[y][x].world.y > fdf->win.height - fdf->img.y))
// 	{
// 		if (x < fdf->map.x_size - 1
// 			&& (!(fdf->map.tab[y][x + 1].world.x < 0 - fdf->img.x
// 				|| fdf->map.tab[y][x + 1].world.x > fdf->win.width - fdf->img.x
// 			|| fdf->map.tab[y][x + 1].world.y < 0 - fdf->img.y
// 			|| fdf->map.tab[y][x + 1].world.y > fdf->win.height - fdf->img.y)))
// 			drawline(fdf, fdf->map.tab[y][x].world,
// 				fdf->map.tab[y][x + 1].world);
// 		if (y < fdf->map.y_size - 1
// 			&& (!(fdf->map.tab[y + 1][x].world.x < 0 - fdf->img.x
// 				|| fdf->map.tab[y + 1][x].world.x > fdf->win.width - fdf->img.x
// 			|| fdf->map.tab[y + 1][x].world.y < 0 - fdf->img.y
// 			|| fdf->map.tab[y + 1][x].world.y > fdf->win.height - fdf->img.y)))
// 			drawline(fdf, fdf->map.tab[y][x].world,
// 				fdf->map.tab[y + 1][x].world);
// 	}
// }
void	ft_print_map(t_map *map, t_data *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->y_size)
	{
		while (x < map->x_size)
		{
			if (x < map->x_size - 1)
				// if (ft_check_position(map, &x, &y, 0) == 0)
					ft_draw_line(img, map->map_tab[y][x].world,
						map->map_tab[y][x + 1].world);
			if (y < map->y_size - 1)
				// if (ft_check_position(map, &x, &y, 1) == 0)
					ft_draw_line(img, map->map_tab[y][x].world,
						map->map_tab[y + 1][x].world);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_new_window(t_map *map)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, LARGEUR, HAUTEUR, "Fdf");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	ft_print_map(map, &img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
