/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <chermist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:56:53 by chermist          #+#    #+#             */
/*   Updated: 2018/12/08 23:55:18 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_arrdel(void **res)
{
	size_t i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
	res = NULL;
	return (res);
}
