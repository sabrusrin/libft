/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <chermist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 00:04:16 by chermist          #+#    #+#             */
/*   Updated: 2019/08/09 17:12:52 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void **ptr, size_t prevsz, size_t newsz)
{
	void	*new;

	if (!ptr && !(*ptr))
		return (NULL);
	if (!(new = ft_memalloc(newsz)))
		return (NULL);
	ft_memcpy(new, *ptr, (prevsz < newsz) ? prevsz : newsz);
	ft_memdel(ptr);
	return (new);
}
