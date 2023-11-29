/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/10/06 20:26:10 by mballa            #+#    #+#             */
/*   Updated: 2023/10/06 20:26:10 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	get_postion(t_my_map *src)
{
	int	i;
	int	j;

	i = 0;
	while (src->map_2[i])
	{
		j = 0;
		while (src->map_2[i][j])
		{
			if (is_char_pattern(src->map_2[i][j], "NSEW"))
			{
				src->row_player = i;
				src->col_player = j;
				src->pos_player = src->map_2[i][j];
				return ;
			}
			j++;
		}
		i++;
	}
	error_message("have set pos player\n", 2);
}

void	check_map(t_my_map *src)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (src->map_2[i])
	{
		j = 0;
		while (src->map_2[i][j])
		{
			if (!is_char_pattern(src->map_2[i][j], "NSEW01 "))
				error_message("must have this NSEW01\n", 2);
			if (is_char_pattern(src->map_2[i][j], "NSEW"))
				flag++;
			j++;
		}
		i++;
	}
	if (flag > 1)
		error_message("have at lest one player pos\n", 2);
}

int	is_valid_line(char *line)
{
	int		len;
	int		j;
	int		is_valid_line;
	int		has_valid_character;
	char	c;

	j = 0;
	len = ft_strlen(line);
	has_valid_character = 0;
	is_valid_line = 1;
	while (j < len)
	{
		c = line[j];
		if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W'
			&& c != ' ')
		{
			is_valid_line = 0;
			break ;
		}
		if (c != ' ' && c != '\t')
			has_valid_character = 1;
		j++;
	}
	return (is_valid_line && has_valid_character);
}

int	count_soulton_lines(char **map, int map_height)
{
	int		soulton_count;
	int		i;
	char	*line;

	i = 0;
	soulton_count = 0;
	while (i < map_height)
	{
		line = ft_strtrim(map[i], "\n");
		if (is_valid_line(line))
			soulton_count++;
		i++;
		free(line);
		line = NULL;
	}
	return (soulton_count);
}

void	get_map(t_my_map *src)
{
	int		get_len;
	int		j;
	int		start;

	j = 0;
	get_len = count_soulton_lines(src->map, src->nb_line) + 1;
	src->nb_map2 = get_len;
	src->map_2 = malloc(sizeof(char *) * (get_len + 1));
	start = src->nb_line - get_len + 1;
	if (!src->map[start])
		error_message("1 invalid map\n", 2);
	if (count_soulton_lines(src->map, src->nb_line) == 0)
		error_message("2 invalid map\n", 2);
	src->biger_row = count_longest_line(start, src->map);
	while (src->map[start])
	{
		process_and_copy_map_line(src, start, j);
		start++;
		j++;
	}
	src->map_2[j] = NULL;
	get_postion(src);
}
