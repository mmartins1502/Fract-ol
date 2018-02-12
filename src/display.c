/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:36:37 by mmartins          #+#    #+#             */
/*   Updated: 2017/07/26 11:49:37 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void		display_comment_bis(t_env *e)
{
	mlx_string_put(e->mlx->mlx, e->mlx->win, 10, 0, 0xFFFFFF,
		"Quit             = esc");
	mlx_string_put(e->mlx->mlx, e->mlx->win, 10, 15, 0xFFFFFF,
		"Zoom in / out    = + / - (num keyboard) or mouse scroll");
	mlx_string_put(e->mlx->mlx, e->mlx->win, 10, 30, 0xFFFFFF,
		"Reset            = Z");
	mlx_string_put(e->mlx->mlx, e->mlx->win, 10, 45, 0xFFFFFF,
		"Move map         = < > ^ v");
	mlx_string_put(e->mlx->mlx, e->mlx->win, 10, 60, 0xFFFFFF,
		"Psy color        = P or O");
	mlx_string_put(e->mlx->mlx, e->mlx->win, 10, 75, 0xFFFFFF,
		"Iterations       = + / - (alpha keyboard)");
	mlx_string_put(e->mlx->mlx, e->mlx->win, 10, 90, 0xFFFFFF,
		"Mandelbrot       = 1");
	mlx_string_put(e->mlx->mlx, e->mlx->win, 10, 105, 0xFFFFFF,
		"Julia            = 2");
	mlx_string_put(e->mlx->mlx, e->mlx->win, 10, 120, 0xFFFFFF,
		"Axone            = 3");
	mlx_string_put(e->mlx->mlx, e->mlx->win, 10, 135, 0xFFFFFF,
		"Rabbit           = 4");
	mlx_string_put(e->mlx->mlx, e->mlx->win, 10, 150, 0xFFFFFF,
		"Bunrningship     = 5");
	mlx_string_put(e->mlx->mlx, e->mlx->win, 10, 165, 0xFFFFFF,
		"Hide             = H");
}

void			display_comment(t_env *e)
{
	if (e->h == 0)
	{
		mlx_string_put(e->mlx->mlx, e->mlx->win, 10, 0, 0xFFFFFF,
			"Help             = H");
	}
	else if (e->h == 1)
		display_comment_bis(e);
}
