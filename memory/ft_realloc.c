/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 00:04:16 by chermist          #+#    #+#             */
/*   Updated: 2019/09/11 13:41:39 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t prevsz, size_t newsz)
{
	void	*new;

	if (!ptr)
		return (NULL);
	if (!(new = ft_memalloc(newsz)))
		return (NULL);
	ft_memcpy(new, ptr, (prevsz < newsz) ? prevsz : newsz);
	ft_memdel((void**)&ptr);
	return (new);
}
