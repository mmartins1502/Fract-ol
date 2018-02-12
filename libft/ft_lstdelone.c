/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:04:03 by mmartins          #+#    #+#             */
/*   Updated: 2017/07/26 14:04:09 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdelone(t_list **begin_list, void (*del)(void *, size_t))
{
	t_list	*list;

	list = *begin_list;
	del(list->content, list->content_size);
	free(list);
	*begin_list = NULL;
}
