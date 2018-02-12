/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 10:44:04 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/11 15:45:23 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse(char c, t_br *br, va_list ap, t_flag flag)
{
	if (c == 'd' || c == 'D' || c == 'i')
		conv_int(br, ap, flag, c);
	else if (c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' ||
			c == 'X')
		conv_uint(br, ap, flag, c);
	else if (c == 's' && flag.l == 0)
		conv_str(br, ap, flag);
	else if (c == 'S' || (c == 's' && flag.l == 1))
		conv_wstr(br, ap, flag);
	else if (c == 'c' && flag.l == 0)
		conv_char(br, ap, flag);
	else if (c == 'C' || (c == 'c' && flag.l == 1))
		conv_wchar(br, ap, flag);
	else if (c == 'p')
		conv_pointer(br, ap, flag);
	else
		conv_per(c, br, flag);
	return (1);
}

static int	set_flag(const char *frmt, t_flag *flag, int *i)
{
	*i = *i + 1;
	while (frmt[*i])
	{
		if (not_flag(frmt[*i]))
			return (1);
		else if (!chk_flag(frmt, i, flag) && !chk_width(frmt, i, flag) &&
				!chk_pre(frmt, i, flag) && !chk_modhl(frmt, i, flag)
			&& !chk_modjz(frmt, i, flag))
			return (0);
		else
			*i = *i + 1;
	}
	return (0);
}

static int	new_flag(t_flag *flag)
{
	ft_memset(flag, 0, sizeof(t_flag));
	flag->prec = -1;
	return (1);
}

int			ft_printf(const char *frmt, ...)
{
	int		i;
	t_br	br;
	t_flag	flag;
	va_list	ap;

	i = -1;
	va_start(ap, frmt);
	ft_memset(&br, 0, sizeof(t_br));
	while (frmt[++i] != '\0')
	{
		new_flag(&flag);
		if (frmt[i] == '%')
		{
			if (set_flag(frmt, &flag, &i) == 1)
				ft_parse(frmt[i], &br, ap, flag);
			else
				frmt[i] == '\0' ? (i = i - 1) : ft_br(frmt[i], &br);
		}
		else
			ft_br(frmt[i], &br);
	}
	va_end(ap);
	ft_putnstr(br.buff, br.ret);
	free(br.buff);
	return (br.ret);
}
