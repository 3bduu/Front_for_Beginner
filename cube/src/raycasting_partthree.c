/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_partthree.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 22:04:12 by abenlahb          #+#    #+#             */
/*   Updated: 2023/10/08 18:52:08 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	dv_rightdist(t_my_map *src, float rayangle, int index, t_tocheck *ptr)
{
	src->ray[index].dist = src->ray[index].dist * cos(rayangle - src->rangle);
	src->ray[index].hitx = ptr->vert_hitx;
	src->ray[index].hity = ptr->vert_hity;
	src->ray[index].hitvert = 1;
}

void	dh_rightdist(t_my_map *src, float rayangle, int index, t_tocheck *ptr)
{
	src->ray[index].dist = src->ray[index].dist * cos(rayangle - src->rangle);
	src->ray[index].hitx = ptr->horz_hitx;
	src->ray[index].hity = ptr->horz_hity;
	src->ray[index].hitvert = 0;
}

void	other_values(t_my_map *src, float rayangle, int index, t_tocheck *ptr)
{
	src->ray[index].rayalpha = rayangle;
	src->ray[index].facindw = ptr->facingdw;
	src->ray[index].facingup = ptr->facingup;
	src->ray[index].facinleft = ptr->facingleft;
	src->ray[index].facinright = ptr->facingright;
}

t_tocheck	*allocation(float *rayangle)
{
	t_tocheck	*ptr;

	ptr = malloc(sizeof(t_tocheck));
	ptr->foundv_hit = 0;
	ptr->foundh_hit = 0;
	ptr->horz_hitx = 0;
	ptr->horz_hity = 0;
	*rayangle = corrvalue(*rayangle);
	ptr->facingdw = rayfacingud(*rayangle);
	ptr->facingup = !ptr->facingdw;
	ptr->facingright = rayfacingrl(*rayangle);
	ptr->facingleft = !ptr->facingright;
	return (ptr);
}

void	one_ray(t_my_map *src, float rayangle, int index)
{
	t_tocheck	*ptr;
	float		dh;
	float		dv;

	ptr = allocation(&rayangle);
	horizontalfunction(src, rayangle, ptr);
	verticalfunction(src, rayangle, ptr);
	calculate_dist(src, ptr, &dh, &dv);
	if (dv < dh)
	{
		src->ray[index].dist = dv;
		dv_rightdist(src, rayangle, index, ptr);
	}
	else
	{
		src->ray[index].dist = dh;
		dh_rightdist(src, rayangle, index, ptr);
	}
	other_values(src, rayangle, index, ptr);
	free(ptr);
}
