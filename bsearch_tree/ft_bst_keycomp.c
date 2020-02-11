/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bst_keycomp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 23:19:25 by chermist          #+#    #+#             */
/*   Updated: 2020/02/11 23:58:56 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_bst_keycomp(t_bstree *a, t_bstree *b, t_bst_key_type k_type, \
														int *f(void*, void*))
{
	if (k_type < STRING)
	{
		if (a == b)
			return (0);
		else if (a < b)
			return (-1);
		else
			return (1);
	}
	else if (k_type == STRING)
		return (ft_strcmp(a, b));
	else
		return (f(a, b));
}
