/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:50:26 by chermist          #+#    #+#             */
/*   Updated: 2019/11/21 19:11:28 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

/*
**A structure to represent a vector
**Structure parameters:
**	data - stores a vector elements.
**	size - a size of data stored.
**	capacity - number of elements that the vector could contain without.
**			allocating more storage.
**	type_sz - type size of the elements.
*/
typedef struct	s_vec
{
	void		*data;
	size_t		size;
	size_t		capacity;
	size_t		type_sz;
}				t_vec;

/*
**ft_vnew - Creates a new vector and allocates memory for <n> number of
**elements with <type_sz> size. Returns a pointer to created vector.
**	Example:
**	t_vec *vector;
**	vector = ft_vnew(5, sizeof(char*));
**	allocates memory for a vector of 5 strings
*/
t_vec			*ft_vnew(size_t n, size_t type_sz);
/*
**ft_vresize - Resizes vector to a needed size
*/
void			ft_vresize(t_vec *v, size_t size);
/*
**ft_vpush_back - Adds an element to the end of vector.
**Allocate some extra storage to accommodate for possible growth.
**	Example:
**	ft_vpush_back(vector, "Hello\n", sizeof(char*));
*/
void			ft_vpush_back(t_vec *v, void *val, size_t val_sz);
/*
**ft_vpop_back - Deletes the element at the end of the vector.
*/
void			ft_vpop_back(t_vec *v);
/*
**ft_vdup - Saves a copy of a vector. Returns a copy of a vector.
*/
t_vec			*ft_vdup(t_vec *vsrc);
/*
**ft_vat - Returns a pointer to the element at a specified location
**in the vector.
**	Example:
**	ft_vat(vector, 4); //will return forth element of the vector
*/
void			*ft_vat(t_vec *v, size_t at);
/*
** ft_vdel - Deletes vector.
*/
void			ft_vdel(t_vec **v);
/*
**ft_vclear - Erases the elements of the vector.
*/
void			ft_vclear(t_vec *v);
/*
**ft_vback - Returns a pointer to the last element in the vector.
*/
void			*ft_vback(t_vec *v);

#endif
