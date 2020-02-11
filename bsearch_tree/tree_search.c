/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:35:25 by chermist          #+#    #+#             */
/*   Updated: 2020/02/12 00:11:17 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bst_search(t_bstree *root, void *key, int *f(void*, void*));
{
	if (root == NULL)
		return (NULL);
	if (ft_bst_keycomp(root->key, key, root->k_type, f) == 0)
		return (root->data)
	if (ft_bst_keycomp(key, root->key, root->k_type, f) < 0)
		return (ft_bst_search(root->left, key, f));
	else
		return (ft_bst_search(root->right, key, f));
}
