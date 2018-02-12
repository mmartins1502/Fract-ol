/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axone.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:24:05 by mmartins          #+#    #+#             */
/*   Updated: 2017/07/25 12:25:48 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int			var(t_env *e)
{
	clSetKernelArg(e->opencl.kernel, 0, sizeof(cl_mem),
	(void *)&e->opencl.img_mem);
	clSetKernelArg(e->opencl.kernel, 1, sizeof(int), &e->it_max);
	clSetKernelArg(e->opencl.kernel, 2, sizeof(int), &e->mlx->size.x);
	clSetKernelArg(e->opencl.kernel, 3, sizeof(int), &e->mlx->size.y);
	clSetKernelArg(e->opencl.kernel, 4, sizeof(float), &e->zoom);
	clSetKernelArg(e->opencl.kernel, 5, sizeof(float), &e->dec.rl);
	clSetKernelArg(e->opencl.kernel, 6, sizeof(float), &e->dec.im);
	clSetKernelArg(e->opencl.kernel, 7, sizeof(int), &e->psy);
	clSetKernelArg(e->opencl.kernel, 8, sizeof(float), &e->m.rl);
	clSetKernelArg(e->opencl.kernel, 9, sizeof(float), &e->m.im);
	clFinish(e->opencl.commands);
	return (0);
}

static int			create_kernel(char *f, char *name, t_env *e)
{
	int				err;
	char			*source;
	size_t			len;

	if (!(source = read_file(f)))
		return (-1);
	len = ft_strlen(source);
	if (!(e->opencl.img = malloc(sizeof(int) * SIZE_IMG)))
		return (-2);
	ft_bzero(e->opencl.img, SIZE_IMG);
	if ((e->opencl.program = clCreateProgramWithSource(e->opencl.context, 1,
		(const char **)&source, (const size_t *)&len, &err)) < 0)
		return (-3);
	ft_strdel(&source);
	if ((err = clBuildProgram(e->opencl.program, 0, NULL, NULL, NULL, NULL))
	!= CL_SUCCESS)
		return (-4);
	if ((e->opencl.kernel = clCreateKernel(e->opencl.program, name, &err)) < 0)
		return (-5);
	e->opencl.workgroupsize = SIZE_IMG;
	e->opencl.img_mem = clCreateBuffer(e->opencl.context, CL_MEM_WRITE_ONLY,
		sizeof(int) * SIZE_IMG, NULL, &err);
	var(e);
	return (0);
}

void				draw_axone(t_env *e)
{
	int				i;
	t_pos			pos;
	int				ret;

	if ((ret = create_kernel("src/axone.cl", "iter_axone", e)) < 0)
	{
		ft_printf("kernel error: %d\n", ret);
		kill_program(e);
	}
	run_kernel(e);
	i = 0;
	while (i < SIZE_IMG)
	{
		pos.x = i % WIDTH;
		pos.y = i / WIDTH;
		e->mlx->img->color = e->opencl.img[i];
		img_pixel_put(e->mlx, pos);
		i++;
	}
	mlx_put_image_to_window(e->mlx->mlx, e->mlx->win, \
			e->mlx->img->img, 0, 0);
	display_comment(e);
	clReleaseMemObject(e->opencl.img_mem);
	clReleaseProgram(e->opencl.program);
	clReleaseKernel(e->opencl.kernel);
}
