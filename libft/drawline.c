/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:03:49 by mmartins          #+#    #+#             */
/*   Updated: 2017/07/26 14:03:52 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <draw.h>

static t_pos			calc_error(t_pos e, t_pos d, t_pos s, t_pos *cur)
{
	e.y = e.x;
	if (e.y > d.x * -1)
	{
		e.x -= d.y;
		(*cur).x += s.x;
	}
	if (e.y < d.y)
	{
		e.x += d.x;
		(*cur).y += s.y;
	}
	return (e);
}

void					drawline(t_pos start, t_pos end, t_mlx *mlx)
{
	t_pos				d;
	t_pos				s;
	t_pos				e;

	d.x = (end.x - start.x < 0) ? (end.x - start.x) * -1 : end.x - start.x;
	d.y = (end.y - start.y < 0) ? (end.y - start.y) * -1 : end.y - start.y;
	s.x = (start.x < end.x) ? 1 : -1;
	s.y = (start.y < end.y) ? 1 : -1;
	e.x = ((d.x > d.y) ? d.x : d.y * -1) / 2;
	while (42)
	{
		img_pixel_put(mlx, start);
		if (start.x == end.x && start.y == end.y)
			break ;
		e = calc_error(e, d, s, &start);
	}
}
