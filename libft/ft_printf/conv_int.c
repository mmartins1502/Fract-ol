/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 10:49:33 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/11 20:35:00 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		set_sign(char **str, intmax_t nbr, int size, t_flag flag)
{
	char		*tmp;
	char		c;
	int			i;

	i = 0;
	c = (nbr < 0 ? '-' : '+');
	tmp = ft_memalloc(sizeof(char) * size + 1);
	ft_memcpy(tmp + 1, *str, size);
	if (flag.zero == 0)
	{
		tmp[0] = ' ';
		while (tmp[i] == ' ')
			i++;
		tmp[i - 1] = c;
	}
	else
	{
		tmp[0] = c;
		tmp[size + 1] = '\0';
	}
	free(*str);
	*str = ft_strnew(size + 1);
	ft_memcpy(*str, tmp, size + 1);
	free(tmp);
	return (1);
}

static intmax_t	modif_long_int(va_list ap, t_flag flag)
{
	intmax_t	nbr;

	if (flag.l == 1)
		nbr = (long)va_arg(ap, intmax_t);
	else if (flag.ll == 1)
		nbr = (long long)va_arg(ap, intmax_t);
	else if (flag.h == 1)
		nbr = (short)va_arg(ap, intmax_t);
	else if (flag.hh == 1)
		nbr = (char)va_arg(ap, intmax_t);
	else if (flag.j == 1)
		nbr = va_arg(ap, intmax_t);
	else if (flag.z == 1)
		nbr = (size_t)va_arg(ap, intmax_t);
	else
		nbr = (int)va_arg(ap, intmax_t);
	return (nbr);
}

static int		ft_space(t_br *br, t_flag *flag)
{
	ft_br(' ', br);
	if (flag->width > 0)
		flag->width = flag->width - 1;
	return (0);
}

static int		free_str(char *str, t_br *br)
{
	int		j;

	j = -1;
	while (str[++j])
		ft_br(str[j], br);
	free(str);
	return (1);
}

int				conv_int(t_br *br, va_list ap, t_flag flag, char c)
{
	char		*str;
	intmax_t	nbr;
	size_t		size;

	if (c == 'D')
		flag.l = 1;
	nbr = modif_long_int(ap, flag);
	if (flag.prec == 0 && nbr == 0)
		str = ft_strnew(0);
	else
		str = ft_uitoa(nbr);
	reset_flag(nbr, &flag, 'i');
	if (flag.space == 1)
		ft_space(br, &flag);
	if (flag.prec >= 0 && flag.prec > (intmax_t)(size = ft_strlen(str)))
		ft_prec(&str, flag, size);
	if (flag.width > (size = ft_strlen(str)))
		ft_width(&str, flag, size);
	if ((flag.plus == 1 && nbr >= 0) || nbr < 0)
		set_sign(&str, nbr, (size = ft_strlen(str)), flag);
	free_str(str, br);
	return (1);
}
