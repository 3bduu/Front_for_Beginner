/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:29:07 by abenlahb          #+#    #+#             */
/*   Updated: 2023/10/08 22:01:26 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	player_move(t_my_map *player)
{
	float	nextmove;
	float	a;
	float	b;
	float	move_lr;

	mlx_destroy_image(player->mlx, player->img.img);
	player->img.img = mlx_new_image(player->mlx, WIDTH, HEIGHT);
	player->rangle += player->left_right * player->tspeed;
	nextmove = player->up_down * player->wspeed;
	move_lr = 0;
	if (player->mleft_right)
		move_lr = PI * 0.5;
	if (player->mleft_right)
		nextmove = player->mleft_right * player->wspeed;
	a = player->player_x + cos(player->rangle + move_lr) * nextmove;
	b = player->player_y + sin(player->rangle + move_lr) * nextmove;
	if (!wallat(player, a, b))
	{
		player->player_x = a;
		player->player_y = b;
	}
	mlx_clear_window(player->mlx, player->win);
	minimap(player);
}

int	player_press(int keycode, t_my_map *src)
{
	if (keycode == W)
		src->up_down += 1;
	else if (keycode == S)
		src->up_down -= 1;
	else if (keycode == A)
		src->mleft_right -= 1;
	else if (keycode == D)
		src->mleft_right += 1;
	else if (keycode == LEFT)
		src->left_right -= 1;
	else if (keycode == RIGHT)
		src->left_right += 1;
	else if (keycode == ESC)
		end_of_game(src);
	player_move(src);
	return (0);
}

int	player_up(int keycode, t_my_map *src)
{
	if (keycode == W)
		src->up_down = 0;
	else if (keycode == S)
		src->up_down = 0;
	else if (keycode == A)
		src->mleft_right = 0;
	else if (keycode == D)
		src->mleft_right = 0;
	else if (keycode == LEFT)
		src->left_right = 0;
	else if (keycode == RIGHT)
		src->left_right = 0;
	return (0);
}

void	check_more(t_my_map *param)
{
	if (test_is_derctory(param->north_texture)
		|| test_is_derctory(param->south_texture)
		|| test_is_derctory(param->east_texture)
		|| test_is_derctory(param->west_texture))
		error_message("open probleme is director", 2);
}
