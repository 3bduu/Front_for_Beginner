/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 07:22:14 by mballa            #+#    #+#             */
/*   Updated: 2022/11/03 00:33:42 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*store;

	if (!del || !lst)
		return ;
	else
	{
		while (*lst)
		{
			store = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = store;
		}
		*lst = NULL;
	}
}
