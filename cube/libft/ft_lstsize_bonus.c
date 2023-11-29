/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:41:38 by mballa            #+#    #+#             */
/*   Updated: 2022/11/03 00:16:30 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*ptr;

	count = 1;
	ptr = lst;
	if (!lst)
		return (0);
	while (ptr ->next)
	{
		count++;
		ptr = ptr ->next;
	}
	return (count);
}
