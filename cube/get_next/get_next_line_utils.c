/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:47:27 by mballa            #+#    #+#             */
/*   Updated: 2023/10/03 17:20:50 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc (1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	i = -1;
	j = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	while (s1[++i])
		ptr[j++] = s1[i];
	i = -1;
	while (s2[++i])
		ptr[j++] = s2[i];
	ptr[j] = '\0';
	free(s1);
	return (ptr);
}

char	*ft_str_len_dup(const char *s1, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s1)
		return (0);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr(char *s, char c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (0);
}
