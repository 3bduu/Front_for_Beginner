/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:47:31 by mballa            #+#    #+#             */
/*   Updated: 2022/11/04 05:16:45 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	count_size;

	if (size != 0 && SIZE_MAX / size <= count)
		return (NULL);
	count_size = count * size;
	p = malloc (count_size);
	if (p == 0)
		return (NULL);
	ft_bzero (p, count_size);
	return (p);
}
