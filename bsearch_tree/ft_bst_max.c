/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bst_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:35:28 by chermist          #+#    #+#             */
/*   Updated: 2020/02/14 21:06:23 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bstree	*ft_bst_max(t_bstree *node)
{
	t_bstree	*max;

	while (node->right != NULL)
	{
		max = node->right;
		node = node->right;
	}
	return (max);
}
