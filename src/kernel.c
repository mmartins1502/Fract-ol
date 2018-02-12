/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 21:29:38 by mmartins          #+#    #+#             */
/*   Updated: 2017/07/24 16:41:45 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int					destroy_opencl(t_env *e)
{
	clReleaseCommandQueue(e->opencl.commands);
	clReleaseContext(e->opencl.context);
	return (0);
}

int					run_kernel(t_env *e)
{
	int				err;

	if ((err = clEnqueueNDRangeKernel(e->opencl.commands, e->opencl.kernel,
		1, NULL, &e->opencl.workgroupsize, NULL, 0, NULL, &e->opencl.event))
		< 0)
		return (-1);
	if ((err = clEnqueueReadBuffer(e->opencl.commands, e->opencl.img_mem,
		CL_TRUE, 0, sizeof(int) * SIZE_IMG, e->opencl.img, 0, NULL,
		&e->opencl.event)))
		return (-2);
	clReleaseEvent(e->opencl.event);
	clFinish(e->opencl.commands);
	return (0);
}

char				*read_file(char *filename)
{
	int				fd;
	char			*line;
	char			*source;

	line = NULL;
	source = NULL;
	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_printf("Unable to open file %s\n", filename);
		return (NULL);
	}
	while (get_next_line(fd, &line) > 0)
		source = ft_stradd(source, line);
	close(fd);
	ft_strdel(&line);
	return (source);
}

int					init_opencl(t_env *e)
{
	int				err;

	if ((err = clGetPlatformIDs(1, &e->opencl.platform_id, NULL)) < 0)
	{
		ft_printf("Platform error : %d\n", err);
		return (-1);
	}
	if ((err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1,
		&e->opencl.device_id, NULL)) < 0)
		return (-2);
	if ((e->opencl.context = clCreateContext(0, 1,
		&e->opencl.device_id, NULL, NULL, &err)) < 0)
		return (-3);
	if ((e->opencl.commands = clCreateCommandQueue(e->opencl.context,
		e->opencl.device_id, 0, &err)) < 0)
		return (-4);
	return (0);
}
