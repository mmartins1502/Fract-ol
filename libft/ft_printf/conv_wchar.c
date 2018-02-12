/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 11:23:27 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/11 15:44:40 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv_wchar(t_br *br, va_list ap, t_flag flag)
{
	char	*str;
	char	c;
	int		ret;
	int		i;
	size_t	size;

	i = 0;
	str = ft_memalloc(sizeof(char) * 5);
	ret = ft_wctomb(str, ((wchar_t)va_arg(ap, int)));
	c = flag.zero == 1 ? '0' : ' ';
	if (flag.width > (size = ft_strlen(str)))
		ft_swidth(flag.width - size, &str, flag.minus, c);
	while (i < ret)
	{
		ft_br(str[i], br);
		i++;
	}
	free(str);
	return (1);
}
