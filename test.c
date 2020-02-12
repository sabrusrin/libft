/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:42:36 by chermist          #+#    #+#             */
/*   Updated: 2020/02/12 23:14:08 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

void	inorder_tree_walk(t_bstree *node)
{
	if (node != NULL)
	{
		inorder_tree_walk(node->left);
		printf("%d	%s\n", *(int*)((node->key)), node->data);
		inorder_tree_walk(node->right);
	}
}

int		main(void)
{
	t_bstree	*root;
	t_bstree	*node;
	int			key;
	char		str[20] = "hello1";

	key = 1;
	root = ft_bst_newnode(&key, str, 7, sizeof(int), INT32);
	while (key)
	{
		write(1, "here\n", 5);
		scanf("%d %s", &key, str);
		node = ft_bst_newnode(&key, str, ft_strlen(str) + 1, sizeof(int), INT32);
		ft_bst_insert(root, node, NULL);
	}
	inorder_tree_walk(root);
	return (0);
}
