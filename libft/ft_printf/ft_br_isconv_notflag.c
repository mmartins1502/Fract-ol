/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_br_isconv_notflag.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 10:46:31 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/11 15:44:59 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_conv(char c)
{
	if (c == 'd' || c == 'D' || c == 'i' || c == 'o' || c == 'O' || c == 'u'
			|| c == 'U' || c == 'x' || c == 'X' || c == 's' || c == 'S' ||
			c == 'c' || c == 'C' || c == 'p')
		return (1);
	else
		return (0);
}

int			ft_br(char c, t_br *br)
{
	char	*tmp;

	tmp = ft_strnew(br->ret + 1);
	ft_memcpy(tmp, br->buff, br->ret);
	free(br->buff);
	tmp[br->ret] = c;
	br->ret = br->ret + 1;
	br->buff = ft_memalloc(br->ret * sizeof(char *));
	ft_memcpy(br->buff, tmp, br->ret + 1);
	free(tmp);
	return (1);
}

int			not_flag(char c)
{
	if ((ft_isdigit(c) == 0 && c != 'l' && c != 'h' && c != 'j' &&
				c != 'z' && c != '-' && c != ' ' && c != '+' && c != '#'
				&& c != '.') || is_conv(c) == 1)
		return (1);
	else
		return (0);
}
