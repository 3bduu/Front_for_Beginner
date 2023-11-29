/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_partfive.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 22:10:16 by abenlahb          #+#    #+#             */
/*   Updated: 2023/10/06 23:07:04 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	wallat(t_my_map *src, float x, float y)
{
	int	mapx;
	int	mapy;

	if (x < 0 || x > src->windows_w || y < 0 || y > src->windows_h)
		return (1);
	mapx = (int)floor(x / SIZE);
	mapy = (int)floor(y / SIZE);
	if (src->map_2[mapy] && src->map_2[mapy][mapx]
		&& src->map_2[mapy][mapx] == '1')
		return (1);
	return (0);
}

float	corrvalue(float rayangle)
{
	rayangle = remainder(rayangle, TWOPI);
	if (rayangle < 0)
		rayangle = TWOPI + rayangle;
	return (rayangle);
}

/* UP DOWN */
int	rayfacingud(float rayangle)
{
	if (rayangle > 0 && rayangle < PI)
		return (1);
	return (0);
}

/* Right Left */
int	rayfacingrl(float rayangle)
{
	if (rayangle < 0.5 * PI || rayangle > 1.5 * PI)
		return (1);
	return (0);
}

float	distancebetweenpoint(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
