/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:03:37 by mballa            #+#    #+#             */
/*   Updated: 2022/11/04 01:22:17 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*s;
	size_t	len_dst;
	size_t	res;
	size_t	len_src;
	size_t	i;

	s = (char *) src;
	len_src = ft_strlen(s);
	res = 0;
	i = 0;
	if ((dstsize == 0 && !dst) || dstsize == 0)
		return (len_src);
	len_dst = ft_strlen(dst);
	if (dstsize >= len_dst)
		res = len_src + len_dst;
	else
		res = len_src + dstsize;
	while (s[i] && (len_dst + 1) < dstsize)
	{
		dst[len_dst] = s[i];
		len_dst++;
		i++;
	}
	dst[len_dst] = '\0';
	return (res);
}
