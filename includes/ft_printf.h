/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:12:45 by chermist          #+#    #+#             */
/*   Updated: 2019/11/24 23:57:46 by chermist         ###   ########.fr       */
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
# define FLAG "#0- +' %"
# define TYPE(x) (ft_strchr("dDioOuUxXfFeEcCsSpaAgGpb", x))
# define LENGTH(x) (ft_strchr("lLhjzt", x))

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
	int				width;
	int				preci;
	char			*hash_symb;
	int				kill;
}					t_pf;

/*
**	ft_printf - produces output according to a format;
**	Write output to stdout.
*/
int					ft_printf(const char *format, ...);
/*
**	ft_dprintf - produces output according to a format;
**	Write output to the given file descriptor.
*/
int					ft_dprintf(int fd, const char *format, ...);
int					parse_format(va_list ap, const char *format, t_vec *buf,\
																	t_pf *sup);
/*
**	helper functions
*/
void				set_default(t_pf *sup);
int					ft_wildcard(va_list ap, char **str, t_pf *sup);
void				put_width(t_vec *buf, t_pf *sup, char pos, char delim);
void				put_full_width(t_vec *buf, t_pf *sup, char pos, char delim);
void				do_hash(t_pf *sup, int *wlen, int *h, char type);
void				put_precision_width(t_pf *sup, t_vec *buf, int pr, int h);
int					precision_len(wchar_t *s, t_pf *sup);
size_t				ft_lstrlen(const wchar_t *s);
int					wchar_bytes(wint_t c);
/*
**	exe_(type) functions consider type size and call the function that
**	put an argument to the ft_printf buffer.
*/
void				exe_int(va_list ap, char type, t_pf *sup, t_vec *buf);
void				exe_octal_hex(va_list ap, char type, t_pf *sup, t_vec *buf);
void				exe_unsigned(va_list ap, char type, t_pf *sup, t_vec *buf);
void				exe_char_string(va_list ap, char type, t_pf *sup,\
																	t_vec *buf);
void				exe_double(va_list ap, char type, t_pf *sup, t_vec *buf);

void				putnbr_buf(t_pf *sup, t_vec *buf, t_vec *nbuf);
void				putbase_buf(t_pf *sup, t_vec *buf, char type, t_vec *nbuf);
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

/*
**	itoa_buf - converts number to ASCII and puts it to num buffer
*/

t_vec				*itoa_buf(long long n, t_vec *nbuf);
t_vec				*uitoa_buf(uintmax_t n, t_vec *nbuf);
t_vec				*itoa_base_buf(uintmax_t num, t_vec *nbuf, t_pf *sup,\
																	char type);

#endif
