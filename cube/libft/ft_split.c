/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:16:12 by mballa            #+#    #+#             */
/*   Updated: 2022/11/04 06:01:05 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static int	count_of_sub(char const *s1, char c)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i] != c && s1[i] != '\0')
		{
			j++;
			i++;
		}
		if (j != 0)
			k++;
		if (s1[i] == '\0')
			break ;
		i++;
	}
	return (k);
}

static void	freee(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
}

static char	**copy(char const *s, char c, char **strs, int word)
{
	int		i;
	int		size;
	int		j;

	i = 0;
	j = -1;
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		size = ft_size_word(s, c, i);
		strs[j] = ft_substr(s, i, size);
		if (!strs[j])
		{
			freee(strs, j);
			return (NULL);
		}
		i += size;
	}
	strs[j] = 0;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	int		word;
	char	**strs;

	if (s == NULL)
	{
		strs = (char **)malloc (1 * sizeof(char *));
		if (!strs)
			return (NULL);
		strs[0] = NULL;
		return (strs);
	}
	word = count_of_sub(s, c);
	strs = (char **)malloc ((word + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	strs = copy(s, c, strs, word);
	return (strs);
}
