/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:49:43 by mballa            #+#    #+#             */
/*   Updated: 2022/10/30 08:15:56 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*subs;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (i < len && start < ft_strlen(s) && s[start + i])
		i++;
	subs = malloc((i + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	while (j < i)
	{
		subs[j] = s[start + j];
		j++;
	}
	subs[j] = '\0';
	return (subs);
}
