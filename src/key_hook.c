/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 20:05:08 by mmartins          #+#    #+#             */
/*   Updated: 2017/07/26 13:40:29 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int		key_hook_ter(int keycode, t_env *e)
{
	if (keycode == 35 || keycode == 31)
	{
		e->psy = keycode == 35 ? (e->psy * 1.1) : (e->psy / 1.1);
		if (e->psy < 1)
			e->psy = 1;
	}
	if (keycode == 4)
	{
		e->h = e->h == 0 ? 1 : 0;
	}
	e->m.rl = 0;
	e->m.im = 0;
	display_comment(e);
	mlx_clear_window(e->mlx->mlx, e->mlx->win);
	e->f(e);
	return (1);
}

static int		key_hook_bis(int keycode, t_env *e)
{
	if (keycode == 53)
		kill_program(e);
	else if (keycode == 69 || keycode == 78)
	{
		e->zoom *= keycode == 69 ? 1.1 : 0.9;
		if (e->zoom <= 0)
			e->zoom = 1;
		e->decz.rl = keycode == 69 ? e->decz.rl / 1.1 : e->decz.rl * 1.1;
		e->decz.im = keycode == 69 ? e->decz.im / 1.1 : e->decz.im * 1.1;
	}
	else if (keycode == 24 || keycode == 27)
	{
		e->it_max *= keycode == 24 ? 1.4 : 0.6;
		if (e->it_max > 10000 || e->it_max < 75)
			e->it_max = 10000 ? 10000 : 75;
	}
	else if (keycode == 9)
	{
		e->psy = 128241;
		e->it_max = 4118;
	}
	key_hook_ter(keycode, e);
	return (1);
}

int				key_hook(int keycode, t_env *e)
{
	if (keycode == 6)
		init_zoom(e);
	else if (keycode == 124 || keycode == 123)
		e->dec.rl = keycode == 124 ? e->dec.rl + e->decz.rl :
		e->dec.rl - e->decz.rl;
	else if (keycode == 126 || keycode == 125)
		e->dec.im = keycode == 126 ? e->dec.im - e->decz.im :
		e->dec.im + e->decz.im;
	else if (keycode == 83 || keycode == 84)
	{
		init_zoom(e);
		e->f = keycode == 83 ? &draw_mandelbrot : &draw_julia;
	}
	else if (keycode == 85 || keycode == 86)
	{
		init_zoom(e);
		e->f = keycode == 85 ? &draw_axone : &draw_rabbit;
	}
	if (keycode == 87)
	{
		init_zoom(e);
		e->f = &draw_burningship;
	}
	key_hook_bis(keycode, e);
	return (1);
}
