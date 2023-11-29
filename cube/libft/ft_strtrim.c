/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:07:54 by mballa            #+#    #+#             */
/*   Updated: 2022/11/04 05:18:18 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	check(char const *s1, char const *set, int len_set)
{
	int	i;
	int	k;

	i = 0;
	while (s1[i] != '\0')
	{
		k = 0;
		while (k < len_set)
		{
			if (s1[i] == set[k])
				break ;
			else
				k++ ;
		}
		if (k == len_set)
			break ;
		i++;
	}
	return (i);
}

static int	check2(char const *s1, char const *set, int len_set, int len_s1)
{
	int	k;

	while (len_s1 >= 0)
	{
		k = 0;
		while (k < len_set)
		{
			if (s1[len_s1 - 1] == set[k])
				break ;
			else
				k++;
		}
		len_s1--;
		if (k == len_set)
			break ;
	}
	return (len_s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cpy;
	int		k;
	int		i;
	int		len_s1;
	int		len_set;

	i = 0;
	k = 0;
	if (s1 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_set = ft_strlen(set);
	i = check(s1, set, len_set);
	len_s1 = check2(s1, set, len_set, len_s1);
	k = 0;
	if (i <= len_s1)
		cpy = malloc((len_s1 - i + 1) + 1);
	else
		cpy = malloc(1);
	if (!cpy)
		return (0);
	while (i <= len_s1)
		cpy[k++] = s1[i++];
	cpy[k] = '\0';
	return (cpy);
}
