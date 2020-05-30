/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 07:34:38 by gbaud             #+#    #+#             */
/*   Updated: 2020/05/30 08:17:17 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
    applyf(root->item);
    if (root->left)
        btree_apply_prefix(root->left, applyf);
    if (root->right)
        btree_apply_prefix(root->right, applyf);
}