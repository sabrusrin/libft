/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:50:26 by chermist          #+#    #+#             */
/*   Updated: 2019/08/09 17:29:29 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

#include "libft.h"

typedef struct	s_vector
{
	void	*data;
	size_t	size;
	size_t	type_sz;
}				t_vector;

t_vector		*ft_vnew(size_t size, size_t type_sz);
void			ft_vresize(t_vector *v, size_t size);

#endif
