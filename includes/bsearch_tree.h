/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsearch_tree.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:22:41 by chermist          #+#    #+#             */
/*   Updated: 2020/02/12 23:11:39 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSEARCH_TREE_H
# define BSEARCH_TREE_H
# include "libft.h"

typedef enum	e_bstree_key_type
{
	INT32,
	INT64,
	STRING,
	OTHER
}				t_bst_key_type;
/*
** A stucture to represent a binary search tree
** Structure parameters;
**	key - node key value.
**	data - stores a nodes element.
**	data_sz - data size.
**	left - pointer to the left branch.
**	right - pointer to the right branch.
**	parent - pointer to the parent node.
*/
typedef struct		s_bstree
{
	void			*key;
	void			*data;
	size_t			data_sz;
	struct s_bstree	*left;
	struct s_bstree	*right;
	struct s_bstree	*parent;
	t_bst_key_type	k_type;
}				t_bstree;
/*
**ft_bst_newnode - Creates a new node. Returns a pointer to created node.
*/
t_bstree			*ft_bst_newnode(void *key, void const *data, size_t size,
										int key_size, t_bst_key_type key_type);
/*
**ft_bst_insert - Creates a new node, puts data into it and
**					inserts this node to the tree.
*/
void				ft_bst_insert(t_bstree *root, t_bstree *node, \
														int *f(void*, void*));
/*
**
*/
void				*ft_bst_search(t_bstree *root, void *key, \
														int *f(void*, void*));
/*
**
*/
t_bstree	*ft_bst_minimum(t_bstree *node);
/*
**
*/
t_bstree	*ft_bst_maximum(t_bstree *node);
/*
**
*/
int					ft_bst_keycomp(t_bstree *a, t_bstree *b,
								t_bst_key_type k_type, int *f(void*, void*));

#endif
