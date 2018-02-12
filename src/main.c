/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 10:57:20 by mmartins          #+#    #+#             */
/*   Updated: 2017/07/26 13:49:51 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_env			*init_env(t_env *e)
{
	e = (t_env *)ft_memalloc(sizeof(t_env));
	return (e);
	e->julia = 0;
	e->m.rl = 0;
	e->m.im = 0;
	e->h = 0;
}

void			init_zoom(t_env *e)
{
	e->it_max = 200;
	e->zoom = 1;
	e->dec.im = 0.00001;
	e->dec.rl = 0.00001;
	e->decz.im = 0.25;
	e->decz.rl = 0.25;
	e->psy = 25;
	e->mouse.x = 449;
	e->mouse.y = 994;
}

void			check_frac(char **av, t_env *e)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		e->f = &draw_mandelbrot;
	else if (ft_strcmp(av[1], "julia") == 0)
		e->f = &draw_julia;
	else if (ft_strcmp(av[1], "axone") == 0)
		e->f = &draw_axone;
	else if (ft_strcmp(av[1], "rabbit") == 0)
		e->f = &draw_rabbit;
	else if (ft_strcmp(av[1], "burningship") == 0)
		e->f = &draw_burningship;
	else
	{
		ft_putstr_fd("Usage <filename> [mandelbrot/julia/axone/rabbit]\n", 2);
		kill_program(e);
	}
	e->f(e);
}

static int		mlx_launch(t_env *e)
{
	mlx_key_hook(e->mlx->win, key_hook, e);
	mlx_mouse_hook(e->mlx->win, mouse_hook, e);
	mlx_hook(e->mlx->win, 6, (1L << 6), e_mouse_move, e);
	mlx_hook(e->mlx->win, 17, (1L << 17), kill_program, e);
	mlx_loop(e->mlx->mlx);
	return (1);
}

int				main(int ac, char **av)
{
	t_env	*e;
	int		ret;

	e = NULL;
	e = init_env(e);
	if (!e || !(e->fr = (t_frac *)malloc(sizeof(t_frac))))
	{
		ft_putstr_fd("Fract'ol error.", 2);
		kill_program(e);
	}
	if (ac != 2)
	{
		ft_putstr_fd("Usage <filename> [mandelbrot/julia/axone/rabbit]\n", 2);
		return (0);
	}
	if ((ret = init_opencl(e) < 0))
	{
		ft_printf("opencl error: %d\n", ret);
		kill_program(e);
	}
	e->mlx = mlx_start(WIDTH, HEIGHT, "Fract'ol");
	init_zoom(e);
	check_frac(av, e);
	mlx_launch(e);
	return (1);
}
