/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 11:21:10 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/11 15:44:32 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_swidth(int n, char **str, int minus, char c)
{
	int		i;
	char	*tmp;
	size_t	size;

	i = -1;
	size = ft_strlen(*str);
	tmp = ft_strnew(n + size);
	if (minus == 0)
	{
		ft_memcpy((tmp + n), *str, size);
		while (++i < n)
			tmp[i] = c;
	}
	else
	{
		ft_memcpy(tmp, *str, size);
		while (++i < n)
			tmp[size + i] = c;
	}
	*str = ft_strnew(ft_strlen(tmp));
	ft_memcpy(*str, tmp, ft_strlen(tmp));
	free(tmp);
	return (1);
}

int			set_null(char *str, t_br *br)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_br(str[i], br);
		i++;
	}
	return (1);
}

static int	ft_spre(char **str, int pre)
{
	char	*tmp;

	tmp = ft_strnew(pre);
	ft_memcpy(tmp, *str, pre);
	*str = ft_strnew(pre);
	ft_memcpy(*str, tmp, pre);
	free(tmp);
	return (1);
}

int			conv_str(t_br *br, va_list ap, t_flag flag)
{
	char	*str;
	char	c;
	size_t	size;
	int		i;

	i = -1;
	if ((str = va_arg(ap, char *)) == NULL)
	{
		if (flag.width == 0 && flag.prec == -1)
		{
			set_null("(null)", br);
			return (1);
		}
		else
			str = ft_strnew(0);
	}
	size = ft_strlen(str);
	if (flag.prec >= 0 && flag.prec < (int)size)
		ft_spre(&str, flag.prec);
	c = flag.zero == 1 ? '0' : ' ';
	if (flag.width > (size = ft_strlen(str)))
		ft_swidth(flag.width - size, &str, flag.minus, c);
	while (str[++i])
		ft_br(str[i], br);
	return (1);
}
