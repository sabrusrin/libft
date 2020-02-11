/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:49:01 by chermist          #+#    #+#             */
/*   Updated: 2020/02/12 00:08:06 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_bst_insert(t_bstree **root, t_bstree *node, int *f(void*, void*))
{
	t_bstree	*y;
	t_bstree	*x;

	y = NULL;
	x = *root;
	while (x != NULL)
	{
		y = x;
		if (ft_bst_keycomp(node->key, x->key, node->k_type, f) <= 0)
			x = x->left;
		else
			x = x->right;
	}
	if (y == NULL)
		*root = node;
	else if (ft_bst_keycomp(node->key, y->key, node->k_type, f) <= 0)
		y->left = node;
	else
		y->right = node;
}
