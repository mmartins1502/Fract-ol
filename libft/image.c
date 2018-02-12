/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:35:41 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/17 15:35:43 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <draw.h>

void			ft_destroy_image(t_image **image, void *mlx)
{
	if (*image == NULL)
		return ;
	mlx_destroy_image(mlx, (*image)->img);
	free(*image);
	*image = NULL;
}

t_image			*ft_new_image(void *mlx, int width, int height)
{
	t_image		*image;

	if (!(image = (t_image *)malloc(sizeof(t_image))))
		return (NULL);
	image->width = width;
	image->height = height;
	if (!(image->img = mlx_new_image(mlx, width, height)))
	{
		free(image);
		return (NULL);
	}
	image->data = mlx_get_data_addr(image->img, &image->bpp, \
		&image->size_line, &image->endian);
	return (image);
}

static t_uint32	swap_endian(t_uint32 in)
{
	t_uint32	out;

	out = (in << 24);
	out |= ((in << 8) & 0x00ff0000);
	out |= ((in >> 8) & 0x0000ff00);
	out |= (in >> 24);
	return (out);
}

static t_uint32	true_color(void *mlx, int endian, int rgb)
{
	t_uint32	color;

	color = mlx_get_color_value(mlx, rgb);
	if (endian == MLX_BIG_ENDIAN)
		color = swap_endian(color);
	return (color);
}

void			img_pixel_put(t_mlx *mlx, t_pos pos)
{
	int			pixel_index;
	int			bpp;
	t_uint32	color;
	t_image		*image;

	image = mlx->img;
	if (pos.x >= 0 && pos.x < mlx->size.x && pos.y >= 0 \
		&& pos.y < mlx->size.y)
	{
		bpp = image->bpp / 8;
		color = true_color(mlx->mlx, image->endian, image->color);
		pixel_index = pos.y * image->size_line + pos.x * bpp;
		ft_memcpy(image->data + pixel_index, &color, bpp);
	}
}
