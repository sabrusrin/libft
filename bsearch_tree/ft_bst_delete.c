/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bst_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:28:24 by chermist          #+#    #+#             */
/*   Updated: 2020/02/12 20:14:13 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	bst_transplant(t_bstree *u, t_bstree *v)
{
	if (u->parent != NULL)
	{
		if (u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;
	}
	if (v != NULL)
		v->parent = u->parent;
}

void	ft_bst_delete(t_bstree *node)
{
	t_bstree	*y;

	if (node->left == NULL)
		bst_transplant(node, node->right);
	else if (node->right == NULL)
		bst_transplant(node, node->left);
	else
	{
		y = ft_bst_minimum(node->right);
		if (y->parent != node)
		{
			bst_transplant(y, y->right);
			y->right = node->right;
			y->right->parent = y;
		}
		bst_transplant(node, y);
		y->left = node->left;
		y->left->parent = y;
	}
}
