/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:47:54 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/07 16:04:28 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

// void	ft_fill_image(t_map map, t_vars new)
// {
	
// }
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

int	ft_draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
	int		pixels;
	double	deltaX;
	double	deltaY;

	deltaX = endX - beginX;
	deltaY = endY - beginY;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
    	mlx_pixel_put(mlx, win, pixelX, pixelY, color);
   		pixelX += deltaX;
   		pixelY += deltaY;
    	--pixels;
	}
	return (0);
}
void	ft_new_window(t_map *map)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		hauteur;
	int		largeur;
	//t_data	img;

	hauteur = 1080;
	largeur = 1920;
	int		espx = largeur / (map->x_size + map->y_size);
	int		espy = espx / 2;
	x = 0;
	y = 0;

	mlx = mlx_init();
	win = mlx_new_window(mlx, largeur, hauteur, "Fdf");
	while (y < map->y_size)
	{
		while (x < map->x_size)
		{
			ft_draw_line(mlx, win, largeur / 2, (hauteur / 8),
				largeur / 2 + espx, (hauteur / 8) + espy, 0xFFFFFF);
			x++;
		}
		y++;
		x = 0;
	}
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	// 		&img.line_length, &img.endian);
	//ft_fill_image(img);
	// my_mlx_pixel_put(&img, map->map_tab[x][y].world.x,
	// 	map->map_tab[x][y].world.y, map->map_tab[x][y].local.color);
	// x++;
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}