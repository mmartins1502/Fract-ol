/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 10:50:04 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/11 15:44:36 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		set_htag(char c, char **str, t_flag flag, size_t size)
{
	char		*tmp;
	int			i;

	i = 0;
	tmp = ft_strnew(size + 2);
	ft_memcpy(tmp + ((c == 'X' || c == 'x') ? 2 : 1), *str, size);
	tmp[0] = ((c == 'X' || c == 'x') && flag.zero == 1) ? '0' : ' ';
	if (flag.zero == 0)
	{
		if (c == 'X' || c == 'x')
			tmp[1] = ' ';
		while (tmp[i] == ' ')
			i++;
		tmp[i - 1] = (c == 'X' || c == 'x') ? c : '0';
		if (c == 'X' || c == 'x')
			tmp[i - 2] = (c == 'X' || c == 'x') ? '0' : ' ';
	}
	else
		tmp[1] = (c == 'X' || c == 'x') ? c : '0';
	free(*str);
	*str = ft_strnew(ft_strlen(tmp));
	ft_memcpy(*str, tmp, ft_strlen(tmp));
	free(tmp);
	return (1);
}

uintmax_t		modif_long(va_list ap, t_flag flag)
{
	uintmax_t	nbr;

	if (flag.l == 1)
		nbr = (unsigned long)va_arg(ap, uintmax_t);
	else if (flag.ll == 1)
		nbr = (unsigned long long)va_arg(ap, uintmax_t);
	else if (flag.h == 1)
		nbr = (unsigned short)va_arg(ap, uintmax_t);
	else if (flag.hh == 1)
		nbr = (unsigned char)va_arg(ap, uintmax_t);
	else if (flag.j == 1)
		nbr = va_arg(ap, uintmax_t);
	else if (flag.z == 1)
		nbr = (ssize_t)va_arg(ap, uintmax_t);
	else
		nbr = (unsigned int)va_arg(ap, uintmax_t);
	return (nbr);
}

int				conv_uint(t_br *br, va_list ap, t_flag flag, char c)
{
	char		*str;
	uintmax_t	nbr;
	int			j;
	size_t		size;

	j = -1;
	if (c == 'U' || c == 'O')
		flag.l = 1;
	nbr = modif_long(ap, flag);
	if (flag.prec == 0 && nbr == 0 && (c != 'O' || (c == 'O' && flag.htag == 0))
			&& (c != 'o' || (c == 'o' && flag.htag == 0)))
		str = ft_strnew(0);
	else
		str = ft_itoabaseui(nbr, c);
	reset_flag(nbr, &flag, c);
	if (flag.prec >= 0 && flag.prec > (int)(size = ft_strlen(str)))
		ft_prec(&str, flag, size);
	if (flag.width > (size = ft_strlen(str)))
		ft_width(&str, flag, size);
	if (flag.htag == 1 && (nbr > 0 || (c == 'o' || c == 'O')))
		set_htag(c, &str, flag, (size = ft_strlen(str)));
	while (str[++j])
		ft_br(str[j], br);
	free(str);
	return (1);
}
