/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballa <mballa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:29:57 by mballa            #+#    #+#             */
/*   Updated: 2022/11/03 00:29:34 by mballa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_back;
	t_list	*new_node;

	if (!f || !lst)
		return (NULL);
	lst_back = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&lst_back, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_back, new_node);
		lst = lst->next;
	}
	return (lst_back);
}
// void * f(void *a)
// {
//     (void) a;
//     return ("kaRAM");
// }

// int main()
// {
//     t_list    *lst1 = ft_lstnew("Mustapha");
//     t_list    *lst2 = ft_lstnew("Balla");
//     ft_lstadd_back(&lst1, lst2);
//     t_list    *lst3 = ft_lstmap(lst1, &f, free);
//     printf("%s\n", lst3 -> content );
//     printf("%s\n", lst3 -> next -> content );
// }