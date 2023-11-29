/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:51:09 by mballa            #+#    #+#             */
/*   Updated: 2023/10/07 02:51:09 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

char	**set_a(char **dup)
{
	int	i;
	int	j;

	i = 0;
	while (dup[i])
	{
		j = 0;
		while (dup[i][j])
		{
			if (dup[i][j] == ' ')
				dup[i][j] = 'A';
			j++;
		}
		i++;
	}
	return (dup);
}

void	norm_3(char **dub)
{
	free_2p(dub);
	error_message("invalid map hnaaa\n", 2);
}

void	check_souranded(char **dub)
{
	int	i;
	int	j;

	i = 0;
	while (dub[i])
	{
		j = 0;
		while (dub[i][j])
		{
			if (dub[i][j] == 'A')
			{
				if ((dub[i][j + 1] && !is_char_pattern(dub[i][j + 1], "A1"))
					|| (dub[i + 1] && !is_char_pattern(dub[i + 1][j], "A1")))
					norm_3(dub);
				if ((i != 0 && j != 0 && !is_char_pattern(dub[i][j - 1], "A1"))
					|| (i != 0 && !is_char_pattern(dub[i - 1][j], "A1")))
					norm_3(dub);
			}
			j++;
		}
		i++;
	}
	free_2p(dub);
}

void	set_and_sourand(char **dub, t_my_map *src)
{
	dub = set_a(dub);
	check_souranded(dub);
	if (src->element_numb - src->nb_map2 != 6)
		error_message("map probleme\n", 2);
}

void	check2_map(t_my_map *src)
{
	char	**dub;
	t_norm2	norm2;

	norm2.j = 1;
	norm2.i = -1;
	dub = malloc(sizeof(char *) * (src->nb_map2 + 3));
	dub[0] = malloc(src->biger_row + 3);
	ft_memset(dub[0], 'A', src->biger_row + 2);
	dub[0][src->biger_row + 2] = '\0';
	while (++norm2.i < src->nb_map2)
	{
		norm2.row_length = ft_strlen(src->map_2[norm2.i]);
		dub[norm2.j] = malloc(norm2.row_length + 3);
		dub[norm2.j][0] = 'A';
		ft_strcpy(dub[norm2.j] + 1, src->map_2[norm2.i]);
		dub[norm2.j][norm2.row_length + 1] = 'A';
		dub[norm2.j][norm2.row_length + 2] = '\0';
		norm2.j++;
	}
	dub[norm2.j] = malloc(src->biger_row + 3);
	ft_memset(dub[norm2.j], 'A', src->biger_row + 2);
	dub[norm2.j][src->biger_row + 2] = '\0';
	norm2.j++;
	dub[norm2.j] = NULL;
	set_and_sourand(dub, src);
}
