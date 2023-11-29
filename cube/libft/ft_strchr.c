/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:10:16 by mballa            #+#    #+#             */
/*   Updated: 2022/11/04 01:49:08 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			c1;

	c1 = (char) c;
	i = 0;
	while (s[i] != c1 && s[i])
		i++;
	if (s[i] == c1)
		return ((char *) &s[i]);
	else
		return (NULL);
}
