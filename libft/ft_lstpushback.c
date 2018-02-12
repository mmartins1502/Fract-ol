/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:34:40 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/17 15:27:38 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstpushback(t_list **alst, t_list *new)
{
	t_list	*list;

	if (!*alst)
		*alst = new;
	else
	{
		list = *alst;
		while (list->next)
			list = list->next;
		list->next = new;
	}
}
