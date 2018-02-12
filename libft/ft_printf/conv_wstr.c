/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_wstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 11:24:28 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/11 20:46:19 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	wc_char(wchar_t x, char **str, int prec, size_t size)
{
	char	*wchar;
	char	*tmp;
	int		ret;
	int		j;

	j = -1;
	wchar = ft_memalloc(sizeof(char) * 5);
	ret = ft_wctomb(wchar, x);
	if (((int)ft_strlen(*str) + ret) <= prec || prec == -1)
	{
		tmp = ft_strnew(size + ret);
		ft_memcpy(tmp, *str, size);
		free(*str);
		while (++j < ret)
			tmp[size + j] = wchar[j];
		*str = ft_strnew(size + ret);
		ft_memcpy(*str, tmp, (size + ret));
		free(tmp);
	}
	free(wchar);
	return (j);
}

int			conv_wstr(t_br *br, va_list ap, t_flag flag)
{
	wchar_t	*wstr;
	char	*str;
	int		i;
	size_t	size;
	char	c;

	i = -1;
	str = ft_strnew(0);
	if ((wstr = va_arg(ap, wchar_t *)) == NULL)
	{
		set_null("(null)", br);
		return (1);
	}
	while (wstr[++i])
		if ((wc_char(wstr[i], &str, flag.prec, ft_strlen(str)) == 0))
			break ;
	i = -1;
	c = flag.zero == 1 ? '0' : ' ';
	if (flag.width > (size = ft_strlen(str)))
		ft_swidth(flag.width - size, &str, flag.minus, c);
	while (str[++i])
		ft_br(str[i], br);
	free(str);
	return (1);
}
