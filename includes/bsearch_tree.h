/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsearch_tree.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:22:41 by chermist          #+#    #+#             */
/*   Updated: 2020/02/10 20:35:34 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSEARCH_TREE_H
# define BSEARCH_TREE_H
# include "libft.h"

typedef struct		s_stree
{
	int				color;
	void			*key;
	void			*data;
	struct s_rbtree	*left;
	struct s_rbtree	*right;
	struct s_rbtree	*p;
//	void			*p
}				t_stree;

#endif
