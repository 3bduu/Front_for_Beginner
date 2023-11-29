/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:35:49 by mballa            #+#    #+#             */
/*   Updated: 2022/11/04 00:05:26 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*sr;

	d = (unsigned char *) dst;
	sr = (unsigned char *) src;
	i = 0;
	if (n <= 0)
		return (dst);
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst == src)
		return (d);
	while (i < n)
	{
		d[i] = sr[i];
		i++;
	}
	return (d);
}
