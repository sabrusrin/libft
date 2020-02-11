/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_trees.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:20:31 by chermist          #+#    #+#             */
/*   Updated: 2020/02/10 20:16:34 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREES_H
# define RB_TREES_H

# include "libft.h"

typedef struct		s_rbtree
{
	int				color;
	void			*key;
	struct s_rbtree	*left;
	struct s_rbtree	*right;
	struct s_rbtree	*p;
//	void			*p
}				t_rbtree;

#endif