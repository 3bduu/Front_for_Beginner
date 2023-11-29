/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_partfour.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 22:05:58 by abenlahb          #+#    #+#             */
/*   Updated: 2023/10/08 18:53:23 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	hori_norm(t_my_map *src, t_tocheck *ptr)
{
	float	ytocheck;

	while (ptr->x >= 0 && ptr->x <= src->windows_w && ptr->y >= 0
		&& ptr->y <= src->windows_h)
	{
		ytocheck = ptr->y;
		if (ptr->facingup)
			ytocheck -= 1;
		if (wallat(src, ptr->x, ytocheck))
		{
			ptr->horz_hitx = ptr->x;
			ptr->horz_hity = ptr->y;
			ptr->foundh_hit = 1;
			break ;
		}
		else
		{
			ptr->x += ptr->deltax;
			ptr->y += ptr->deltay;
		}
	}
}

void	horizontalfunction(t_my_map *src, float rayangle, t_tocheck *ptr)
{
	ptr->y = floor(src->player_y / SIZE) * SIZE;
	if (ptr->facingdw)
		ptr->y += SIZE;
	ptr->x = src->player_x + (ptr->y - src->player_y) / tan(rayangle);
	ptr->deltay = SIZE;
	if (ptr->facingup)
		ptr->deltay *= -1;
	ptr->deltax = SIZE / tan(rayangle);
	if (ptr->facingleft && ptr->deltax > 0)
		ptr->deltax *= -1;
	if (ptr->facingright && ptr->deltax < 0)
		ptr->deltax *= -1;
	hori_norm(src, ptr);
}

void	vert_norm(t_my_map *src, t_tocheck *ptr)
{
	float	xtocheck;

	while (ptr->x >= 0 && ptr->x <= src->windows_w && ptr->y >= 0
		&& ptr->y <= src->windows_h)
	{
		xtocheck = ptr->x;
		if (ptr->facingleft)
			xtocheck -= 1;
		if (wallat(src, xtocheck, ptr->y))
		{
			ptr->vert_hitx = ptr->x;
			ptr->vert_hity = ptr->y;
			ptr->foundv_hit = 1;
			break ;
		}
		else
		{
			ptr->x += ptr->deltax;
			ptr->y += ptr->deltay;
		}
	}
}

void	verticalfunction(t_my_map *src, float rayangle, t_tocheck *ptr)
{
	ptr->foundv_hit = 0;
	ptr->vert_hitx = 0;
	ptr->vert_hity = 0;
	ptr->x = floor(src->player_x / SIZE) * SIZE;
	if (ptr->facingright)
		ptr->x += SIZE;
	ptr->y = src->player_y + (ptr->x - src->player_x) * tan(rayangle);
	ptr->deltax = SIZE;
	if (ptr->facingleft)
		ptr->deltax *= -1;
	ptr->deltay = SIZE * tan(rayangle);
	if (ptr->facingup && ptr->deltay > 0)
		ptr->deltay *= -1;
	if (ptr->facingdw && ptr->deltay < 0)
		ptr->deltay *= -1;
	vert_norm(src, ptr);
}

void	calculate_dist(t_my_map *src, t_tocheck *ptr, float *dh, float *dv)
{
	if (ptr->foundh_hit)
		*dh = distancebetweenpoint(src->player_x, src->player_y, ptr->horz_hitx,
				ptr->horz_hity);
	else
		*dh = INT_MAX;
	if (ptr->foundv_hit)
		*dv = distancebetweenpoint(src->player_x, src->player_y, ptr->vert_hitx,
				ptr->vert_hity);
	else
		*dv = INT_MAX;
}
