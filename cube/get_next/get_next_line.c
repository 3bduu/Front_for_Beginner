/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:28:00 by mballa            #+#    #+#             */
/*   Updated: 2023/10/03 17:20:08 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get(char *s1)
{
	int		i;
	char	*p;

	i = 0;
	if (!*s1)
		return (0);
	while (s1[i] != '\n' && s1[i] != '\0')
		i++;
	if (s1[i] == '\n')
		i += 1;
	p = ft_str_len_dup(s1, i);
	return (p);
}

char	*get_remember(char *s1)
{
	int		i;
	char	*line;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i] != '\0' && s1[i] != '\n')
		i++;
	if (s1[i] == '\0')
	{
		free(s1);
		return (NULL);
	}
	i++;
	line = ft_str_len_dup(&s1[i], ft_strlen(s1) - i);
	free(s1);
	return (line);
}

char	*ft_free(char *saver)
{
	free(saver);
	return (NULL);
}

int	ft_first_check(int fd, t_data *data)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	data->buff = malloc(BUFFER_SIZE + 1);
	if (!data->buff)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char		*save;
	t_data			data;

	data.rd = 1;
	if (!ft_first_check(fd, &data))
		return (NULL);
	while (data.rd != 0 && !ft_strchr(save, '\n'))
	{
		data.rd = read(fd, data.buff, BUFFER_SIZE);
		if (data.rd == -1)
		{
			free(data.buff);
			if (save)
				save = ft_free (save);
			return (NULL);
		}
		data.buff[data.rd] = '\0';
		save = ft_strjoin(save, data.buff);
	}
	free(data.buff);
	data.line = get(save);
	save = get_remember(save);
	return (data.line);
}
