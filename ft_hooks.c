/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:28:52 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/09 13:30:46 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/fdf.h"

int	key_hook(int keycode, t_vars *vars, t_map *map)
{
	if (keycode == 53)
	{
		(void)map;
		//mlx_destroy_image(vars->mlx, vars->win);
		//ft_free_all((void **)map->map_tab);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}
