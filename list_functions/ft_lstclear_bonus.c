/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 22:40:03 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/01 13:34:08 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;
	t_list *tmp2;

	tmp = *lst;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = tmp2;
	}
	*lst = NULL;
}
