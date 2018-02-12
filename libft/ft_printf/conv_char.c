/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 10:51:14 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/11 15:44:11 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv_char(t_br *br, va_list ap, t_flag flag)
{
	int		i;
	char	*str;
	char	c;
	int		limit;

	i = 0;
	str = ft_strnew(2);
	str[0] = (char)va_arg(ap, int);
	c = flag.zero == 1 ? '0' : ' ';
	if (flag.width > 0)
		ft_swidth(flag.width - 1, &str, flag.minus, c);
	limit = flag.width > 1 ? flag.width : 1;
	while (i < limit)
	{
		ft_br(str[i], br);
		i++;
	}
	free(str);
	return (1);
}

int		conv_per(char x, t_br *br, t_flag flag)
{
	char	*str;
	int		i;
	char	c;

	i = 0;
	str = ft_strnew(1);
	str[0] = x;
	c = flag.zero == 1 ? '0' : ' ';
	if (flag.width > 1)
		ft_swidth(flag.width - 1, &str, flag.minus, c);
	while (str[i])
	{
		ft_br(str[i], br);
		i++;
	}
	free(str);
	return (1);
}
