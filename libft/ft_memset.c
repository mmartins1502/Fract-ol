/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:09:35 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/17 15:26:57 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *v, int c, size_t i)
{
	int j;

	j = 0;
	while (i--)
		((unsigned char*)v)[j++] = (unsigned char)c;
	return (v);
}
