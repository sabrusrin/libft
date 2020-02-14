/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bst_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:35:20 by chermist          #+#    #+#             */
/*   Updated: 2020/02/14 21:06:09 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bstree	*ft_bst_min(t_bstree *node)
{
	t_bstree	*min;

	while (node->left != NULL)
	{
		min = node->left;
		node = node->left;
	}
	return (min);
}
