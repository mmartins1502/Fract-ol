/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:35:17 by mmartins          #+#    #+#             */
/*   Updated: 2017/07/26 12:05:21 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		mouse_hook(int button, int x, int y, t_env *e)
{
	float		ex;

	if (button == 5 || button == 4)
	{
		e->zoom *= (button == 4) ? 1.1 : 0.7;
		e->decz.rl = button == 4 ? e->decz.rl / 1.1 : e->decz.rl * 1.1;
		e->decz.im = button == 4 ? e->decz.im / 1.1 : e->decz.im * 1.1;
		e->m.rl = x;
		ex = (e->m.rl * 100) / e->mlx->size.x;
		e->m.rl = ex / 100;
		e->m.im = y;
		ex = (e->m.im * 100) / e->mlx->size.y;
		e->m.im = ex / 100;
		if (e->zoom <= 0)
			e->zoom = 1;
		mlx_clear_window(e->mlx->mlx, e->mlx->win);
		e->f(e);
	}
	if (button == 1)
		e->julia = e->julia == 1 ? 0 : 1;
	return (1);
}

int		e_mouse_move(int x, int y, t_env *e)
{
	if (e->julia == 1 && e->f == &draw_julia)
	{
		e->mouse.x = x;
		e->mouse.y = y;
		mlx_clear_window(e->mlx->mlx, e->mlx->win);
		e->f(e);
	}
	return (1);
}
