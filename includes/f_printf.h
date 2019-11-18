/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_printf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:12:45 by chermist          #+#    #+#             */
/*   Updated: 2019/11/19 01:35:54 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_PRINTF_H
# define F_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <wchar.h>
# include "libft.h"

# define LENGTH "lLhjz"
# define TYPE "dDioOuUxXfFeEcCsSpaAgGpb"
# define FLAG "#0- +'"

typedef struct		s_pf
{
	unsigned char	length;
	char			hash;
	char			zero;
	char			minus;
	char			space;
	char			plus;
	int				width;
	int				preci;
}					t_pf;

void				parse_format(va_list ap, const char *format, t_vec *buf,\
																	t_pf *sup);
void				set_default(t_pf *sup);
int					ft_wildcard(va_list ap, char **str, t_pf *sup);

void				exe_int(va_list ap, char type, t_pf *sup, t_vec *buf);
void				exe_octal_hex(va_list ap, char type, t_pf *sup, t_vec *buf);
void				exe_unsigned(va_list ap, char type, t_pf *sup, t_vec *buf);
void				exe_char_string(va_list ap, char type, t_pf *sup,\
																	t_vec *buf);

void				putnbr_buf(long long num, t_pf *sup, t_vec *buf);
void				putunbr_buf(unsigned long long num, t_pf *sup, t_vec *buf);
void				putbase_buf(uintmax_t nub, char type, t_pf *sup,\
																	t_vec *buf);

#endif
