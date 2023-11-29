/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:16:42 by mballa            #+#    #+#             */
/*   Updated: 2022/10/29 11:22:43 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		lent;
	char	c1;
	char	*str;

	lent = 0;
	str = (char *) s;
	c1 = (char ) c;
	while (str[lent])
		lent++;
	while (lent >= 0)
	{
		if (str[lent] == c1)
			return ((char *) &str[lent]);
		lent--;
	}
	return (0);
}
