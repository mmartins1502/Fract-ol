/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:37:23 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/17 15:37:32 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# define MLX_BIG_ENDIAN 1
# include <libft.h>
# include <mlx.h>

typedef unsigned int	t_uint32;

typedef struct			s_pos
{
	int					x;
	int					y;
}						t_pos;

typedef struct			s_image
{
	void				*img;
	char				*data;
	int					width;
	int					height;
	int					bpp;
	int					size_line;
	int					endian;
	int					color;
}						t_image;

typedef struct			s_mlx
{
	t_pos				size;
	void				*mlx;
	void				*win;
	t_image				*img;
}						t_mlx;

void					ft_destroy_image(t_image **image, void *mlx);
t_image					*ft_new_image(void *mlx, int width, int height);
void					img_pixel_put(t_mlx *mlx, t_pos pos);
void					drawline(t_pos start, t_pos end, t_mlx *mlx);
t_mlx					*mlx_start(int width, int height, char *title);
void					mlx_destroy(t_mlx **mlx);

#endif
