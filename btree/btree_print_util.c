/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_print_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 02:55:58 by gbaud             #+#    #+#             */
/*   Updated: 2020/06/03 03:10:43 by gbaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	btree_print_util_str(t_btree *root, int space)
{
	int i;

	i = 9;
	if (root == NULL)
		return ;
	space += 10;
	btree_print_util_str(root->right, space);
	ft_printf("\n");
	while (++i < space)
		ft_printf(" ");
	ft_printf("%s\n", (char *)root->item);
	btree_print_util_str(root->left, space);
}

void	btree_print_str(t_btree *root)
{
	btree_print_util_str(root, 0);
}

void	btree_print_util_int(t_btree *root, int space)
{
	int i;

	i = 9;
	if (root == NULL)
		return ;
	space += 10;
	btree_print_util_int(root->right, space);
	ft_printf("\n");
	while (++i < space)
		ft_printf(" ");
	ft_printf("%d\n", *((int *)root->item));
	btree_print_util_int(root->left, space);
}

void	btree_print_int(t_btree *root)
{
	btree_print_util_int(root, 0);
}
