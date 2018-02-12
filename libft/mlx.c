/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:36:11 by mmartins          #+#    #+#             */
/*   Updated: 2017/05/17 15:36:13 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <draw.h>

void				mlx_destroy(t_mlx **mlx)
{
	if (*mlx == NULL)
		return ;
	mlx_destroy_window((*mlx)->mlx, (*mlx)->win);
	ft_destroy_image(&(*mlx)->img, (*mlx)->mlx);
	free(*mlx);
	*mlx = NULL;
}

t_mlx				*mlx_start(int width, int height, char *title)
{
	t_mlx			*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->mlx = mlx_init()))
	{
		free(mlx);
		return (NULL);
	}
	if (!(mlx->win = mlx_new_window(mlx->mlx, width, height, title)))
	{
		free(mlx->mlx);
		free(mlx);
		return (NULL);
	}
	mlx->size.x = width;
	mlx->size.y = height;
	mlx->img = ft_new_image(mlx->mlx, width, height);
	return (mlx);
}
