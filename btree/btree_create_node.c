/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 07:23:10 by gbaud             #+#    #+#             */
/*   Updated: 2020/05/30 07:59:19 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_btree *btree_create_node(t_btree *parent, void *item)
{
    t_btree *node;

    if (!(node = malloc(sizeof(node))))
        return (NULL);
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;
    node->item = item;
    return (node);
}
