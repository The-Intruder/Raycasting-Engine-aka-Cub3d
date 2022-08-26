/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:12:18 by mnaimi            #+#    #+#             */
/*   Updated: 2022/08/14 21:21:46 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* -------------------------------------------------------------------------- */

double	deg2rad(int deg)
{
    return (deg * (M_PI / 180));
}

/* -------------------------------------------------------------------------- */

int	rad2deg(double rad)
{
    return (rad * (180 / M_PI));
}

/* -------------------------------------------------------------------------- */

double	normalize_angle(double rotation)
{
	rotation = fmodf(rotation, (M_PI * 2));
	if (rotation < 0)
		rotation += M_PI * 2;
	return (rotation);
}
/* -------------------------------------------------------------------------- */

int	check_wall_colision(t_fcoords pos, char **map_arr)
{
	t_icoords	map_index;
	t_icoords	map_size;

	map_index = (t_icoords){.x = pos.x / CUB_SIZE, .y = pos.y / CUB_SIZE};
	map_size = (t_icoords){.x = 0, .y = 0};
	while (map_arr[map_size.y])
		++map_size.y;
	if (map_index.y >= map_size.y || map_index.y < 0)
		return (1);
	map_size.x = ft_strlen(map_arr[map_index.y]);
	if (map_index.x >= map_size.x || map_index.x < 0 || \
		 map_arr[map_index.y][map_index.x] == '1')
		return (1);
	return (0);
}
/* -------------------------------------------------------------------------- */
double dstnce_btwn_points(float x1, float y1, float x2, float y2)
{
    return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
/* -------------------------------------------------------------------------- */
