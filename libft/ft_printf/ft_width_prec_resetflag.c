/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_prec_resetflag.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 11:28:19 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/11 15:45:55 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_width(char **str, t_flag flag, size_t size)
{
	char	c;
	char	*tmp;

	c = (flag.zero == 1 ? '0' : ' ');
	tmp = ft_memalloc(sizeof(char) * flag.width);
	ft_memset(tmp, c, flag.width);
	if (flag.minus == 0)
		ft_memcpy((tmp + (flag.width - size)), *str, size);
	else
		ft_memcpy(tmp, *str, size);
	free(*str);
	*str = ft_strnew(flag.width);
	ft_memcpy(*str, tmp, flag.width);
	free(tmp);
	return (1);
}

int		reset_flag(intmax_t nbr, t_flag *flag, char c)
{
	if (flag->zero == 1 && (flag->prec >= 0 || flag->minus == 1))
		flag->zero = 0;
	if (flag->space == 1 && (flag->plus == 1 || nbr < 0))
		flag->space = 0;
	if (flag->width > 1 && flag->htag == 1 && (c == 'x' || c == 'X'))
		flag->width = flag->width - 2;
	if (flag->width > 1 && flag->htag == 1 && (c == 'o' || c == 'O'))
		flag->width = flag->width - 1;
	if ((flag->plus == 1 || nbr < 0) && flag->width > 0 && c == 'i')
		flag->width = flag->width - 1;
	if (flag->htag == 1 && flag->prec > 1 && (c == 'o' || c == 'O'))
		flag->prec = flag->prec - 1;
	if ((c == 'o' || c == 'O') && nbr == 0)
		flag->htag = 0;
	return (1);
}

int		ft_prec(char **str, t_flag flag, size_t size)
{
	char	*tmp;

	tmp = ft_strnew(flag.prec);
	ft_memset(tmp, '0', flag.prec);
	ft_memcpy(tmp + (flag.prec - size), *str, size);
	free(*str);
	*str = ft_strnew(flag.prec);
	ft_memcpy(*str, tmp, flag.prec);
	ft_memcpy(*str, tmp, flag.prec);
	free(tmp);
	return (1);
}
