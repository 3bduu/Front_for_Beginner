/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mysplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 03:16:40 by mballa            #+#    #+#             */
/*   Updated: 2023/10/08 03:16:40 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_word(char const *s, char *c, int i)
{
	int	size;

	size = 0;
	while (s[i] != '\0' && ft_strchr(c, s[i]) == NULL)
	{
		size++;
		i++;
	}
	return (size);
}

static int	count_of_sub(char const *s1, char *c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s1[i])
	{
		while (s1[i] != '\0' && ft_strchr(c, s1[i]) != NULL)
			i++;
		if (s1[i] != '\0')
			k++;
		while (s1[i] != '\0' && ft_strchr(c, s1[i]) == NULL)
			i++;
	}
	return (k);
}

char	**ft_split_str(char *str)
{
	char	**ptr;
	int		count_word;
	int		i;
	int		j;
	int		size;

	count_word = count_of_sub(str, ", \n\t");
	ptr = malloc((count_word + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	j = -1;
	while (++j < count_word)
	{
		while (str[i] != '\0' && ft_strchr(", \n\t", str[i]) != NULL)
			i++;
		size = ft_size_word(str, ", \n\t", i);
		ptr[j] = ft_substr(str, i, size);
		i += size;
	}
	ptr[j] = NULL;
	return (ptr);
}
