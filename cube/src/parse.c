/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:41:48 by mballa            #+#    #+#             */
/*   Updated: 2023/10/07 02:48:56 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	nbr_rgb(char **color)
{
	int	i;

	i = 0;
	while (color[i])
	{
		i++;
	}
	if (i != 3)
		return (1);
	return (0);
}

int	get_rgb(char **str, t_color *color)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	while (str[i])
		i++;
	if (i != 3 || ft_strlen(str[0]) > 3 || ft_strlen(str[1]) > 3
		|| ft_strlen(str[2]) > 3)
		return (1);
	if (!is_valid_digit(str[0]) || !is_valid_digit(str[1])
		|| !is_valid_digit(str[2]))
		return (1);
	r = ft_atoi(str[0]);
	g = ft_atoi(str[1]);
	b = ft_atoi(str[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (1);
	color->r = r;
	color->g = g;
	color->b = b;
	return (0);
}

void	procces_color(t_my_map *param, char **splited)
{
	if (!splited[0])
		return ;
	if (!ft_strcmp(splited[0], F_COLOR))
	{
		if (get_rgb(splited + 1, &param->f_color) != 0)
			error_message("invalid color ", 2);
	}
	else if (!ft_strcmp(splited[0], C_COLOR))
	{
		if (get_rgb(splited + 1, &param->c_color) != 0)
			error_message("invalid color range\n", 2);
	}
}

void	check_color(char **map)
{
	int	found_f;
	int	found_c;
	int	i;

	found_f = 0;
	found_c = 0;
	i = 0;
	while (map[i])
	{
		while (isspace(*map[i]))
			map[i]++;
		if (ft_strncmp(map[i], "F ", 2) == 0)
			found_f = 1;
		else if (ft_strncmp(map[i], "C ", 2) == 0)
			found_c = 1;
		i++;
	}
	if (found_c + found_f != 2 || !found_c || !found_f)
	{
		free_2p(map);
		error_message("Color problem", 2);
	}
}

void	process_texture(t_my_map *param, char **splited)
{
	if (!splited[0])
		return ;
	if (ft_strcmp(splited[0], NORTH_TEXTURE) == 0)
		param->north_texture = ft_strdup(splited[1]);
	else if (ft_strcmp(splited[0], SOUTH_TEXTURE) == 0)
		param->south_texture = ft_strdup(splited[1]);
	else if (ft_strcmp(splited[0], EAST_TEXTURE) == 0)
		param->east_texture = ft_strdup(splited[1]);
	else if (ft_strcmp(splited[0], WEST_TEXTURE) == 0)
		param->west_texture = ft_strdup(splited[1]);
}
