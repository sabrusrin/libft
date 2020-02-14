/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:42:36 by chermist          #+#    #+#             */
/*   Updated: 2020/02/14 20:50:05 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

void	inorder_tree_walk(t_bstree *node)
{
	if (node != NULL)
	{
		inorder_tree_walk(node->left);
		ft_printf("%s -- %s\n", (node->key), node->data);
		inorder_tree_walk(node->right);
	}
}

int		main(void)
{
	t_bstree	*root;
	t_bstree	*node;
	t_bstree	*min;
	t_bstree	*max;
	char		key[20] = "Rustam";
	char		str[20] = "Sabitov";

	root = ft_bst_newnode(key, str, ft_strlen(str) + 1, ft_strlen(key) + 1, STRING);
	while (!ft_strstr(key, "end"))
	{
		scanf("%s %s", key, str);
		node = ft_bst_newnode(key, str, ft_strlen(str) + 1, ft_strlen(key) + 1, STRING);
		ft_bst_insert(root, node, NULL);
	}
	write(1, "kk", 2);
	min = ft_bst_min(root);
	max = ft_bst_max(root);
	ft_printf("min_key %s -- min_val %s\n", min->key, min->data);
	ft_printf("max_key %s -- max_val %s\n", max->key, max->data);

	inorder_tree_walk(root);
	return (0);
}
