/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:12:45 by chermist          #+#    #+#             */
/*   Updated: 2019/11/21 22:14:46 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <wchar.h>
# include "libft.h"
# define LENGTH "lLhjz"
# define TYPE "dDioOuUxXfFeEcCsSpaAgGpb"
# define FLAG "#0- +'"

# define TRUE 1
# define FALSE 0

typedef struct		s_pf
{
	unsigned char	length;
	char			hash;
	char			zero;
	char			minus;
	char			space;
	char			plus;
	char			sign;
	size_t			width;
	int				preci;
	int				kill;
}					t_pf;

int					ft_printf(const char *format, ...);
int					parse_format(va_list ap, const char *format, t_vec *buf,\
																	t_pf *sup);
void				set_default(t_pf *sup);
int					ft_wildcard(va_list ap, char **str, t_pf *sup);
void				put_width(t_vec *buf, t_pf *sup, char pos, char delim);

void				exe_int(va_list ap, char type, t_pf *sup, t_vec *buf);
void				exe_octal_hex(va_list ap, char type, t_pf *sup, t_vec *buf);
void				exe_unsigned(va_list ap, char type, t_pf *sup, t_vec *buf);
void				exe_char_string(va_list ap, char type, t_pf *sup,\
																	t_vec *buf);
void				exe_double(va_list ap, char type, t_pf *sup, t_vec *buf);

void				putnbr_buf(t_pf *sup, t_vec *buf, t_vec *nbuf);
/*void				putunbr_buf(unsigned long long num, t_pf *sup, t_vec *buf);
void				putbase_buf(uintmax_t num, char type, t_pf *sup,\
																	t_vec *buf);
void				putfloat_buf(float num, char type, t_pf *sup, t_vec *buf);
void				butdouble_buf(long double num, char type, t_pf *sup,\
																	t_vec *buf); */
void				putchar_buf(wchar_t c, char type, t_pf *sup, t_vec *buf);
void				putstr_buf(char *s, char type, t_pf *sup, t_vec *buf);
void				putlstr_buf(wchar_t *s, char type, t_pf *sup, t_vec *buf);

int					buf_wchar(wchar_t c, t_vec *buf, int bytes);
void				str_to_buf(char *s, t_vec *buf);
t_vec				*strnbr(int n, t_vec *nbuf);
t_vec				*strnbr_hh(signed char n, t_vec *nbuf);
t_vec				*strnbr_h(short n, t_vec *nbuf);
t_vec				*strnbr_ll(long long n, t_vec *nbuf);

#endif
