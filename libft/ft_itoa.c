/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:17:56 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/17 15:27:57 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_itoa(int n)
{
	size_t			len;
	char			*s;
	unsigned int	u_nbr;
	int				nb;

	nb = n;
	len = 1;
	if (nb < 0)
	{
		u_nbr = -n;
		len++;
	}
	else
		u_nbr = n;
	while (nb /= 10)
		len++;
	if (!(s = ft_strnew(len)))
		return (NULL);
	s[--len] = u_nbr % 10 + '0';
	while (u_nbr /= 10)
		s[--len] = u_nbr % 10 + '0';
	if (n < 0)
		s[0] = '-';
	return (s);
}
