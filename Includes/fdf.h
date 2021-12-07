/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:59:52 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/07 08:55:08 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDH_H
# define FDH_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <mlx.h>
# define BASE_HEXA "0123456789ABCDEF"

typedef	struct	s_val4
{
	double	x;
	double	y;
	double	z;
	int	color;
}	t_val4;

typedef	struct	s_vertex
{
	t_val4	local;
	t_val4	world;
}	t_vertex;

typedef struct	s_map
{
	t_vertex	**map_tab;
	int			x_size;
	int			y_size;
}	t_map;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	t_data	*win;
}				t_vars;

int		ft_parsing_map(char *argv, t_map *map);
int		ft_fill_map(t_map *map, char **line, int i);
int		ft_malloc_map(t_map *map);
char	**ft_get_file(char *argv, int count_line, t_map *map);
int		ft_count_line(char *str, t_map *map);
int		ft_count_int(const char *str, char charset);
void	*ft_free_all(void **tab);
void	ft_new_window(t_map *map);
void	ft_convert_map_to_iso(t_map *map);


# endif
