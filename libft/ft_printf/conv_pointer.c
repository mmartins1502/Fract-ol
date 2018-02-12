/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 11:18:44 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/11 15:44:28 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_0x(char **str, t_flag flag, size_t size)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strnew(size + 2);
	ft_memcpy(tmp + 2, *str, size);
	if (flag.zero == 0)
	{
		tmp[0] = ' ';
		tmp[1] = ' ';
		while (tmp[i] == ' ')
			i++;
		tmp[i - 1] = 'x';
		tmp[i - 2] = '0';
	}
	else
	{
		tmp[0] = '0';
		tmp[1] = 'x';
	}
	free(*str);
	*str = ft_strnew(size + 2);
	ft_memcpy(*str, tmp, size + 2);
	free(tmp);
	return (1);
}

int		conv_pointer(t_br *br, va_list ap, t_flag flag)
{
	uintmax_t	adr;
	int			i;
	char		*str;
	size_t		size;

	i = 0;
	if (flag.width > 1)
		flag.width = flag.width - 2;
	adr = (uintmax_t)va_arg(ap, void *);
	if (flag.prec == 0 && adr == 0)
		str = ft_strnew(0);
	else
		str = ft_itoabaseui(adr, 'x');
	if (flag.prec >= 0 && flag.prec >= (int)(size = ft_strlen(str)))
		ft_prec(&str, flag, size);
	if (flag.width > (size = ft_strlen(str)))
		ft_width(&str, flag, (size = ft_strlen(str)));
	set_0x(&str, flag, ft_strlen(str));
	while (str[i])
	{
		ft_br(str[i], br);
		i++;
	}
	free(str);
	return (0);
}
