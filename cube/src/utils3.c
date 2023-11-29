/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:43:11 by mballa            #+#    #+#             */
/*   Updated: 2023/10/07 20:20:09 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	process_line(char *temp, t_norm *norm, int *tex_flags)
{
	if (temp[0] == 'N' || temp[0] == 'S' || temp[0] == 'W' || temp[0] == 'E')
	{
		process_texture_line(temp, norm, tex_flags);
	}
	else if (temp[0] == 'F' || temp[0] == 'C')
	{
		if (temp[1] == ' ')
		{
			if (temp[0] == 'F')
			{
				(norm->found_f)++;
			}
			else
			{
				(norm->found_c)++;
			}
		}
	}
}

void	process_texture_line(char *temp, t_norm *norm, int *tex_flags)
{
	if (ft_strncmp(temp, "NO ", 3) == 0 || ft_strncmp(temp, "SO ", 3) == 0
		|| ft_strncmp(temp, "WE ", 3) == 0 || ft_strncmp(temp, "EA ", 3) == 0)
	{
		if (ft_strncmp(temp, "NO ", 3) == 0)
		{
			(tex_flags)[0]++;
		}
		else if (ft_strncmp(temp, "SO ", 3) == 0)
		{
			(tex_flags)[1]++;
		}
		else if (ft_strncmp(temp, "WE ", 3) == 0)
		{
			(tex_flags)[2]++;
		}
		else if (ft_strncmp(temp, "EA ", 3) == 0)
		{
			(tex_flags)[3]++;
		}
		(norm->tex_numb)++;
	}
}

void	check_conditions(int tex_numb, int found_c, int found_f)
{
	if (tex_numb != 4)
	{
		error_message("There must be exactly 4 textures\n", 2);
	}
	if (found_c + found_f != 2 || !found_c || !found_f)
	{
		error_message("Color problem", 2);
	}
}

int	is_char_pattern(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_videe(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (!isspace(s[i]))
			return (0);
	return (1);
}
