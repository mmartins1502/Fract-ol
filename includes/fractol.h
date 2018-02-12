/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 10:48:38 by mmartins          #+#    #+#             */
/*   Updated: 2017/07/26 12:30:21 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <libft.h>
# include <draw.h>
# include <mlx.h>
# include <math.h>
# include <OpenCL/opencl.h>

# define WIDTH 1300
# define HEIGHT 1300
# define SIZE_IMG WIDTH * HEIGHT
# define ABS(x) (x < 0 ? -x : x)
# define X1 -2.1
# define X2 0.6
# define Y1 -1.2
# define Y2 1.2

typedef struct			s_opencl
{
	size_t				workgroupsize;
	cl_platform_id		platform_id;
	cl_device_id		device_id;
	cl_context			context;
	cl_command_queue	commands;
	cl_program			program;
	cl_kernel			kernel;
	cl_event			event;
	cl_mem				img_mem;
	int					*img;
}						t_opencl;

typedef	struct			s_cplx
{
	float				rl;
	float				im;
}						t_cplx;

typedef	struct			s_fractal
{
	float				x1;
	float				x2;
	float				y1;
	float				y2;
	float				tmp;
	t_cplx				zoom;
	t_cplx				c;
	t_cplx				z;
}						t_frac;

typedef struct			s_env
{
	t_mlx				*mlx;
	t_frac				*fr;
	float				zoom;
	int					it_max;
	t_cplx				dec;
	t_cplx				decz;
	float				deca;
	int					psy;
	void				(*f)(struct s_env *);
	t_pos				mouse;
	int					julia;
	t_opencl			opencl;
	t_cplx				m;
	int					h;
}						t_env;

int						main(int ac, char **av);
void					display_comment(t_env *e);
int						key_hook(int keycode, t_env *e);
int						kill_program(t_env *e);
void					init_mandel(t_env *e);
t_env					*init_env(t_env *e);
void					init_julia(t_env *e);
int						mouse_hook(int button, int x, int y, t_env *e);
void					init_zoom(t_env *e);
void					init_axone(t_env *e);
int						e_mouse_move(int x, int y, t_env *e);
void					init_rabbit(t_env *e);
int						init_opencl(t_env *env);
int						run_kernel(t_env *env);
int						destroy_opencl(t_env *env);
char					*read_file(char *filename);
void					draw_mandelbrot(t_env *env);
void					draw_julia(t_env *e);
void					draw_axone(t_env *e);
void					draw_rabbit(t_env *e);
void					draw_burningship(t_env *e);

#endif
