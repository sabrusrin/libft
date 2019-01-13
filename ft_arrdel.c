/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:56:53 by chermist          #+#    #+#             */
/*   Updated: 2019/01/11 22:01:46 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_arrdel(void **res)
{
	void	**tmp;

	tmp = res;
	while (res && *res)
		free(*res++);
	free(tmp);
	tmp = NULL;
	return (tmp);
}
