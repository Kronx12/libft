/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 02:22:42 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/01 13:34:35 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new;
	t_list		*list;

	if (!lst)
		return (NULL);
	if (!(list = ft_lstnew(f(lst->content))))
		return (NULL);
	new = list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(list->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		list = list->next;
	}
	return (new);
}
