/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondrayutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:17:36 by abenlahb          #+#    #+#             */
/*   Updated: 2023/10/06 23:02:19 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	my_mlx_pixel_get(t_data data, int x, int y)
{
	char	*dst;

	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
		return (0);
	dst = data.addr + (y * data.line_length + x * (data.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	free_map(t_my_map *src)
{
	int	i;

	i = -1;
	while (src->map_2[++i])
		free(src->map_2[i]);
	free(src->map_2);
	src->map_2 = NULL;
}

int	end_of_game(t_my_map *src)
{
	free_map(src);
	mlx_destroy_image(src->mlx, src->img.img);
	mlx_clear_window(src->mlx, src->win);
	free(src->mlx);
	exit(0);
	return (0);
}
