/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/10/07 17:02:21 by mballa            #+#    #+#             */
/*   Updated: 2023/10/07 17:02:21 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	free_2p(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i++]);
	}
	free(array);
}

int	test_extension(char *file_name, char *extension)
{
	char	*last_period;

	last_period = ft_strrchr(file_name, '.');
	if (last_period == NULL)
		return (0);
	if (ft_strcmp(last_period + 1, extension) == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	is_empty(int fd)
{
	char	*line;
	int		is_file_emty;

	is_file_emty = 1;
	line = get_next_line(fd);
	while (line)
	{
		if (*line != '\0')
		{
			is_file_emty = 0;
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (is_file_emty);
}

int	test_is_derctory(char *file_name)
{
	int	fd;

	fd = open(file_name, O_DIRECTORY);
	if (fd != -1)
		return (1);
	return (0);
}

int	count_longest_line(int i, char **map)
{
	int	max_length;
	int	length;

	max_length = 0;
	while (map[i] != NULL)
	{
		length = ft_strlen(map[i]);
		if (length > max_length)
			max_length = length;
		i++;
	}
	return (max_length);
}
