/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 09:44:22 by gbaud             #+#    #+#             */
/*   Updated: 2020/09/19 07:57:31 by gbaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstremove_node(t_list **head_ref, t_list *del)
{
	if (*head_ref == NULL || del == NULL)
		return ;
	if (*head_ref == del)
		*head_ref = del->next;
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	free(del);
}

void	ft_lstremove_if(t_list **head_ref, void *value, void (*del)(void *),
						int (*cond)(void *, void *))
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*head_ref);
	while (tmp)
	{
		tmp2 = tmp->next;
		if (cond(value, tmp->content))
		{
			del(tmp->content);
			ft_lstremove_node(head_ref, tmp);
		}
		tmp = tmp2;
	}
}
