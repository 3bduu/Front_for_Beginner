/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:40:16 by mballa            #+#    #+#             */
/*   Updated: 2023/10/08 19:04:55 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	free_funct(t_my_map *src)
{
	if (src->map)
		free_2p(src->map);
	if (src->map_2)
		free_2p(src->map_2);
	if (src->north_texture)
		free(src->north_texture);
	if (src->south_texture)
		free(src->south_texture);
	if (src->east_texture)
		free(src->east_texture);
	if (src->west_texture)
		free(src->west_texture);
}

void	error_message(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	exit(1);
}

int	handle_arg(char *str)
{
	if (test_is_derctory(str))
		error_message("Error: invalid\n", 2);
	else if (!test_extension(str, "cub"))
		error_message("Error: invalid file extension\n", 2);
	else
		return (1);
	return (0);
}

int	is_valid_digit(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	process_and_copy_map_line(t_my_map *src, int start, int j)
{
	char	*trimmed;

	trimmed = ft_strtrim(src->map[start], "\n");
	src->map_2[j] = ft_strlen_dup(trimmed, src->biger_row);
	free(trimmed);
	trimmed = NULL;
	if (is_videe(src->map_2[j]))
		error_message("3 invalid map\n", 2);
}
