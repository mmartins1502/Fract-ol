/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 11:45:04 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/11 15:45:17 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		*(ptr + i) = c;
		i++;
	}
	return (s);
}
