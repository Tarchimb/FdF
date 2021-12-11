/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:47:54 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/11 09:01:02 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

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
				ft_draw_line(img, map->map_tab[y][x].world,
					map->map_tab[y][x + 1].world);
			if (y < map->y_size - 1)
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
