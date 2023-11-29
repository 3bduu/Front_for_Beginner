/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_parttwo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:18:35 by abenlahb          #+#    #+#             */
/*   Updated: 2023/10/08 16:55:06 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ray_cast(t_my_map *src)
{
	float	rayangle;
	int		i;

	rayangle = src->rangle - HALF_FOV;
	i = 0;
	while (i < src->casted_rays)
	{
		one_ray(src, rayangle, i);
		rayangle += src->step_angle;
		i++;
	}
}

/* Drawing Rays */
void	render_rays(t_my_map *src)
{
	int		i;
	float	wallstri;

	i = 0;
	ray_cast(src);
	while (i < src->casted_rays)
	{
		wallstri = (SIZE / src->ray[i].dist) * src->screen_dist;
		draw_square1(src, i, (HEIGHT / 2
				- wallstri / 2) + wallstri, wallstri);
		i++;
	}
}

void	take_image(void *mlx, t_data *img, char *path)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &img->tex_width,
			&img->tex_height);
	if (!img->img)
	{
		error_message("invalid texture files\n", 2);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
	{
		printf("Error While getting Img Address\n");
		exit(0);
	}
}

int	render_frame(t_my_map *src)
{
	player_move(src);
	return (0);
}

int	handle_mouse_motion(int x, int y, t_my_map *src)
{
	static double	mouse;

	(void)y;
	if (mouse == 0)
		mouse = x;
	if (x > mouse)
		src->rangle += 0.20 * src->tspeed * fabs(x - mouse);
	else if (x < mouse)
		src->rangle -= 0.20 * src->tspeed * fabs(x - mouse);
	mouse = x;
	return (0);
}
