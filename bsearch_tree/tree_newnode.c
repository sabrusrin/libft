/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_newnode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:38:03 by chermist          #+#    #+#             */
/*   Updated: 2020/02/11 22:59:26 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bstree *ft_bst_newnode(void *key, void const *data, size_t size,
													t_bst_key_type key_type)
{
	t_bstree	*new_node;

	if (!(new_node = malloc(sizeof(t_bstree))))
		return (NULL);
	if (!(new_node->data = malloc(sizeof(size))))
	{
		ft_memdel(&new_node);
		return (NULL);
	}
	if (data)
		ft_memcpy(new_node->data, data, size);
	new_node->key = key;
	new_node->data_sz = size;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->k_type = key_type;
	return (new_node);
}
