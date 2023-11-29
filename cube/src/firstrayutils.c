/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firstrayutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:36:46 by abenlahb          #+#    #+#             */
/*   Updated: 2023/10/08 19:08:04 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_data	*get_tex(t_ray *r, t_data *data)
{
	if (r->hitvert)
	{
		if ((r->rayalpha >= 0 && r->rayalpha <= PI / 2.0) || (r->rayalpha >= 3.0
				* PI / 2 && r->rayalpha <= 2.0 * PI))
		{
			return (&data[0]);
		}
		else
		{
			return (&data[1]);
		}
	}
	else
	{
		if (r->rayalpha >= 0 && r->rayalpha < PI)
		{
			return (&data[2]);
		}
		else
		{
			return (&data[3]);
		}
	}
}

void	drawcolorsection(t_my_map *src, float start_h, int w, float x)
{
	while (w < x)
	{
		my_mlx_pixel_put(&src->img, start_h, w, create_rgb(src->c_color.r,
				src->c_color.g, src->c_color.b));
		w++;
	}
}

void	drawfinalcolorsection(t_my_map *src, float start_h, int w)
{
	while (w < HEIGHT)
	{
		my_mlx_pixel_put(&src->img, start_h, w, create_rgb(src->f_color.r,
				src->f_color.g, src->f_color.b));
		w++;
	}
}

void	drawtexturesection(t_my_map *src, float x, t_norm3 *norm3, t_data *tex)
{
	int	distance_from_to;

	while (x < norm3->end_w)
	{
		distance_from_to = x + (norm3->wall / 2) - (HEIGHT / 2);
		norm3->offset_y = distance_from_to * (tex->tex_height / norm3->wall);
		my_mlx_pixel_put(&src->img, norm3->start_h, x, my_mlx_pixel_get(*tex,
				norm3->offset_x, norm3->offset_y));
		(x) += 1;
	}
}

void	draw_square1(t_my_map *src, float start_h, float end_w, float wall)
{
	t_data	*tex;
	t_norm3	norm3;
	int		i;
	float	w;

	norm3.wall = wall;
	w = 0;
	i = start_h;
	norm3.start_w = (HEIGHT / 2 - wall / 2);
	if (src->ray[i].hitvert)
		norm3.offset_x = (int)src->ray[i].hity % SIZE;
	else
		norm3.offset_x = (int)src->ray[i].hitx % SIZE;
	tex = get_tex(&src->ray[i], src->data);
	if (norm3.start_w < 0)
		end_w = HEIGHT;
	if (norm3.start_w < 0)
		norm3.start_w = 0;
	norm3.x = norm3.start_w;
	norm3.start_h = start_h;
	norm3.end_w = end_w;
	drawcolorsection(src, start_h, w, norm3.x);
	drawtexturesection(src, norm3.x, &norm3, tex);
	w = end_w;
	drawfinalcolorsection(src, start_h, w);
}
