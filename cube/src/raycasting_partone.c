/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_partone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:42:24 by abenlahb          #+#    #+#             */
/*   Updated: 2023/10/08 16:53:54 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	minimap(t_my_map *src)
{
	render_rays(src);
	mlx_put_image_to_window(src->mlx, src->win, src->img.img, 0, 0);
}

void	init_texteur(t_my_map *src)
{
	char	*texturepaths[4];
	int		i;

	texturepaths[0] = src->north_texture;
	texturepaths[1] = src->south_texture;
	texturepaths[2] = src->west_texture;
	texturepaths[3] = src->east_texture;
	i = 0;
	while (i < 4)
	{
		take_image(src->mlx, &(src->data[i]), texturepaths[i]);
		i++;
	}
}

void	init_player(t_my_map *src)
{
	src->player_x = src->col_player * SIZE + 1.5;
	src->player_y = src->row_player * SIZE + 1.5;
	src->casted_rays = WIDTH;
	src->step_angle = FOV / src->casted_rays;
	src->ray = malloc(src->casted_rays * sizeof(t_ray));
	src->screen_dist = (WIDTH / 2) / tan(HALF_FOV);
	src->up_down = 0;
	src->left_right = 0;
	if (src->map_2[src->row_player][src->col_player] == 'N')
		src->rangle = 0.5 * PI;
	else if (src->map_2[src->row_player][src->col_player] == 'S')
		src->rangle = 1.5 * PI;
	else if (src->map_2[src->row_player][src->col_player] == 'W')
		src->rangle = PI;
	else
		src->rangle = 0;
	src->wspeed = 5.0;
	src->tspeed = 1.5 * (PI / 180);
}

int	init_value(t_my_map *src)
{
	src->i = 0;
	src->mlx = mlx_init();
	if (!src->mlx)
		return (1);
	src->windows_w = ft_strlen(src->map_2[0]) * SIZE;
	while (src->map_2[src->i])
		src->i++;
	src->windows_h = src->i * SIZE;
	src->win = mlx_new_window(src->mlx, WIDTH, HEIGHT, "Cub3d");
	if (!src->win)
		return (1);
	init_player(src);
	init_texteur(src);
	return (0);
}

void	raycasting(t_my_map *src)
{
	init_value(src);
	src->img.img = mlx_new_image(src->mlx, WIDTH, HEIGHT);
	src->img.addr = mlx_get_data_addr(src->img.img, &src->img.bits_per_pixel,
			&src->img.line_length, &src->img.endian);
	minimap(src);
	mlx_hook(src->win, KEYPRESS, (1L << 0), &player_press, src);
	mlx_hook(src->win, KEYUP, (1L << 1), &player_up, src);
	mlx_hook(src->win, 6, (1L << 6), &handle_mouse_motion, src);
	mlx_loop_hook(src->mlx, render_frame, src);
	mlx_hook(src->win, DESTROY, (1L << 17), &end_of_game, src);
	mlx_loop(src->mlx);
}
