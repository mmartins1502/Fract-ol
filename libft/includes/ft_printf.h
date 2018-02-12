/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 11:41:04 by mmartins          #+#    #+#             */
/*   Updated: 2017/06/01 22:34:04 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <libft.h>

typedef struct		s_flag
{
	unsigned int	h : 1;
	unsigned int	hh : 1;
	unsigned int	l : 1;
	unsigned int	ll : 1;
	unsigned int	j : 1;
	unsigned int	z : 1;
	unsigned int	htag : 1;
	unsigned int	zero : 1;
	unsigned int	plus : 1;
	unsigned int	minus : 1;
	unsigned int	space : 1;
	unsigned int	width;
	int				prec;
}					t_flag;

typedef struct		s_br
{
	char			*buff;
	size_t			ret;
}					t_br;

int					set_null(char *str, t_br *br);
int					not_flag(char c);
int					chk_flag(const char *frmt, int *i, t_flag *flag);
int					chk_modhl(const char *frmt, int *i, t_flag *flag);
int					chk_modjz(const char *frmt, int *i, t_flag *flag);
int					chk_pre(const char *frmt, int *i, t_flag *flag);
int					chk_width(const char *frmt, int *i, t_flag *flag);
int					conv_uint(t_br *br, va_list ap, t_flag flag, char c);
int					conv_int(t_br *br, va_list ap, t_flag flag, char c);
int					conv_str(t_br *br, va_list ap, t_flag flag);
int					conv_char(t_br *br, va_list ap, t_flag flag);
int					conv_wchar(t_br *br, va_list ap, t_flag flag);
int					conv_pointer(t_br *br, va_list ap, t_flag flag);
int					conv_wstr(t_br *br, va_list ap, t_flag flag);
int					ft_br(char c, t_br *br);
int					ft_printf(const char *frmt, ...);
int					ft_width(char **str, t_flag flag, size_t size);
int					ft_swidth(int n, char **str, int width, char c);
int					ft_prec(char **str, t_flag flag, size_t size);
int					reset_flag(intmax_t nbr, t_flag *flag, char c);
int					ft_isdigit(char c);
void				*ft_memalloc(size_t size);
void				*ft_memset(void *s, int c, size_t n);
char				*ft_strnew(size_t size);
char				*ft_uitoa(intmax_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_putnstr(char *str, int n);
char				*ft_itoabaseui(uintmax_t n, char c);
int					conv_per(char x, t_br *br, t_flag flag);
int					ft_wctomb(char *s, wchar_t wc);

#endif
