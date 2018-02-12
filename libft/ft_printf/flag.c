/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 10:47:03 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/11 20:24:10 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		chk_width(const char *frmt, int *i, t_flag *flag)
{
	if (ft_isdigit(frmt[*i]) && frmt[*i] != '0')
		flag->width = ft_atoi((char*)(frmt + (*i)));
	else
		return (0);
	while (frmt[*i] && ft_isdigit(frmt[*i + 1]))
		*i = *i + 1;
	return (1);
}

int		chk_flag(const char *frmt, int *i, t_flag *flag)
{
	if (frmt[*i] == '0')
		flag->zero = 1;
	else if (frmt[*i] == '-')
		flag->minus = 1;
	else if (frmt[*i] == '+')
		flag->plus = 1;
	else if (frmt[*i] == '#')
		flag->htag = 1;
	else if (frmt[*i] == ' ')
		flag->space = 1;
	else
		return (0);
	return (1);
}

int		chk_modhl(const char *frmt, int *i, t_flag *flag)
{
	if (frmt[*i] == 'h' && frmt[*i + 1] != 'h')
		flag->h = 1;
	else if (frmt[*i] == 'h' && frmt[*i + 1] == 'h')
	{
		flag->hh = 1;
		*i = *i + 1;
	}
	else if (frmt[*i] == 'l' && frmt[*i + 1] != 'l')
		flag->l = 1;
	else if (frmt[*i] == 'l' && frmt[*i + 1] == 'l')
	{
		flag->ll = 1;
		*i = *i + 1;
	}
	else
		return (0);
	return (1);
}

int		chk_modjz(const char *frmt, int *i, t_flag *flag)
{
	if (frmt[*i] == 'j')
		flag->j = 1;
	else if (frmt[*i] == 'z')
		flag->z = 1;
	else
		return (0);
	return (1);
}

int		chk_pre(const char *frmt, int *i, t_flag *flag)
{
	if (frmt[*i] == '.')
		flag->prec = ft_atoi((char *)(frmt + (*i) + 1));
	else
		return (0);
	while (frmt[*i] && ft_isdigit(frmt[*i + 1]))
		*i = *i + 1;
	return (1);
}
