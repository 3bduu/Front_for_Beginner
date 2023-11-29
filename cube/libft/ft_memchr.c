/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:56:54 by mballa            #+#    #+#             */
/*   Updated: 2022/10/29 12:30:55 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	car;

	car = (unsigned char) c;
	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (str[i] == car)
			return (str + i);
		i++;
	}
	return (NULL);
}
