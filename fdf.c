/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:51:57 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/11 09:01:02 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"
#include <fdf.h>

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (0);
	if (!(ft_parsing_map(argv[1], &map)))
		return (0);
	ft_convert_map_to_iso(&map);
	ft_new_window(&map);
	ft_free_all((void **)map.map_tab);
	return (0);
}
