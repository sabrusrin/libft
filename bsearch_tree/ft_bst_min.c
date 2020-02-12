/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bst_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:35:20 by chermist          #+#    #+#             */
/*   Updated: 2020/02/12 20:31:47 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bstree	*ft_bst_minimum(t_bstree *node)
{
	t_bstree	*min;

	while (node->left != NULL)
		min = node->left;
	return (min);
}
