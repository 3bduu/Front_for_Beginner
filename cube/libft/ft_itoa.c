/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:19:54 by mballa            #+#    #+#             */
/*   Updated: 2023/10/03 18:00:58 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int nbr)
{
	int	lent;

	lent = 0;
	if (nbr <= 0)
		lent = 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		lent++;
	}
	return (lent);
}

static int	check_sign(int n)
{
	int	sign;

	if (n < 0)
		sign = -1;
	else
		sign = 0;
	return (sign);
}

static int	check_negtive(int n)
{
	int	nbr;

	if (n < 0)
		nbr = n * (-1);
	else
		nbr = n;
	return (nbr);
}

char	*ft_itoa(int n)
{
	int		nbr;
	int		sign;
	int		len;
	char	*alpha;
	int		last_index;

	sign = check_sign(n);
	len = ft_len(n);
	nbr = check_negtive(n);
	last_index = len;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	alpha = malloc(sizeof(char) * len + 1);
	if (!alpha)
		return (NULL);
	while (len > 0)
	{
		alpha[len - 1] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	alpha[last_index] = '\0';
	if (sign == 1)
		alpha[0] = '-';
	return (alpha);
}
