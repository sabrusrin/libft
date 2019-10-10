/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:50:26 by chermist          #+#    #+#             */
/*   Updated: 2019/09/19 17:04:29 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "libft.h"

typedef struct	s_vec
{
	void		*data;
	size_t		size;
	size_t		capacity;
	size_t		type_sz;
}				t_vec;

t_vec			*ft_vnew(size_t size, size_t type_sz);
void			ft_vresize(t_vec *v, size_t size);
void			ft_vpush_back(t_vec *v, void *val, size_t val_sz);
void			ft_vpop_back(t_vec *v);
t_vec			*ft_vdup(t_vec *vsrc);
void			*ft_vat(t_vec *v, size_t at);
void			ft_vdel(t_vec **v);
void			ft_vclear(t_vec *v);
void			*ft_vback(t_vec *v);

#endif
