/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/08/28 12:30:17 by abenlahb          #+#    #+#             */
/*   Updated: 2023/08/28 12:30:17 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	get_texture(t_my_map *param)
{
	int		i;
	char	**splited;

	i = 0;
	while (param->map[i])
	{
		if (ft_strncmp(param->map[i], "F ", 2) == 0 || ft_strncmp(param->map[i],
				"C ", 2) == 0)
			get_cooma(param->map[i]);
		splited = ft_split_str(param->map[i]);
		process_texture(param, splited);
		procces_color(param, splited);
		free_2p(splited);
		i++;
	}
	if (!test_extension(param->north_texture + 1, "xpm")
		|| !test_extension(param->south_texture + 1, "xpm")
		|| !test_extension(param->east_texture + 1, "xpm")
		|| !test_extension(param->west_texture + 1, "xpm"))
		error_message("Texture filenames must have .xpm extension!\n", 2);
	if (open(param->north_texture, O_RDONLY) < 0 || open(param->south_texture,
			O_RDONLY) < 0 || open(param->east_texture, O_RDONLY) < 0
		|| open(param->west_texture, O_RDONLY) < 0)
		error_message("Texture open probleme\n", 2);
	check_more(param);
}

void	initialize_tex_flags(int tex_flags[])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		tex_flags[i] = 0;
		i++;
	}
}

void	let_check(t_my_map *src, char **map)
{
	t_norm	norm;	
	int		i;
	char	*temp;
	int		tex_flags[4];

	i = 0;
	norm.found_c = 0;
	norm.found_f = 0;
	norm.tex_numb = 0;
	src->element_numb = 0;
	initialize_tex_flags(tex_flags);
	while (map[i])
	{
		temp = map[i];
		while (isspace(*temp))
			temp++;
		process_line(temp, &norm, tex_flags);
		if (*map[i] != '\n')
			src->element_numb++;
		i++;
	}
	check_conditions(norm.tex_numb, norm.found_c, norm.found_f);
	check_tex_flags(tex_flags);
}

void	start_parse(char *filename, t_my_map *src)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_message("file open error\n", 2);
	else if (is_empty(fd))
		error_message("Your file is emptyy\n", 2);
	else
	{
		initial_data(src);
		src->map = get_content(fd, src);
		let_dup(src, filename);
		let_check(src, src->map);
		get_texture(src);
		get_map(src);
		check_map(src);
		check2_map(src);
	}
	close(fd);
}

int	main(int ac, char **av)
{
	t_my_map	src;

	if (ac == 2)
	{
		if (handle_arg(av[1]))
		{
			start_parse(av[1], &src);
			raycasting(&src);
			free_funct(&src);
		}
	}
	else
		error_message("args problem\n", 2);
	return (0);
}
