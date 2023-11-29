/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 01:21:37 by mballa            #+#    #+#             */
/*   Updated: 2023/10/07 01:21:37 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

char	**get_content(int fd, t_my_map *info_map)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		info_map->nb_line++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	info_map->map = malloc(sizeof(char *) * (info_map->nb_line + 2));
	close(fd);
	return (info_map->map);
}

void	let_dup(t_my_map *info_mapm, char *file_name)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		info_mapm->map[i] = ft_strdup(line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	info_mapm->map[i] = NULL;
}

void	initial_data(t_my_map *data_map)
{
	data_map->map = NULL;
	data_map->map_2 = NULL;
	data_map->nb_line = 0;
	data_map->south_texture = NULL;
	data_map->north_texture = NULL;
	data_map->west_texture = NULL;
	data_map->east_texture = NULL;
}

void	get_cooma(char *str)
{
	int	k;
	int	i;

	k = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			k++;
		i++;
	}
	if (k > 2)
		error_message("color problem\n", 2);
}

void	check_tex_flags(int tex_flags[])
{
	int	j;

	j = 0;
	while (j < 4)
	{
		if (tex_flags[j] != 1)
		{
			error_message("just one \n", 2);
		}
		j++;
	}
}
