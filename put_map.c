/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:39:13 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/28 17:48:03 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_sprite(void *mlx, char *path)
{
	t_image img;
	int x;
	int y;

	x = 50;
	y = 50;
	img.image = mlx_xpm_file_to_image(mlx, path, &x, &y);
	return(img.image);
}

void	ft_map(void *mlx, void *win, char *map)
{
	t_matrix matrix;
	int lines;

	lines = ft_matrix_lines(map);
	matrix.x = 0;
	matrix.y = 0;
	matrix.mat = ft_matrix(map);
	while (lines > 0)
	{
		while (matrix.mat[matrix.x][matrix.y])
		{
			ft_putmap(mlx, win, matrix.x, matrix.y, matrix.mat[matrix.x][matrix.y]);
			matrix.y++;
		}
		matrix.x++;
		matrix.y = 0;
		lines--;
	}
}

void	ft_putmap(void *mlx, void *win, int x, int y, char c)
{
	t_program 	img;

	if (c == '1')
		img.sprite.image = ft_sprite(mlx, "./Textures/wall50.xpm");
	else if (c == '0')
		img.sprite.image = ft_sprite(mlx, "./Textures/floor50.xpm");
	else if (c == 'P')
		img.sprite.image = ft_sprite(mlx, "./Textures/ghost1.xpm");
	/*else if (c == 'C')
		img.sprite.image = ft_sprite(mlx, "./Textures/");*/
	else if (c == 'E')
		img.sprite.image = ft_sprite(mlx, "./Textures/door.xpm");
	else
		return ;
	mlx_put_image_to_window(mlx, win, img.sprite.image, y * 50, x * 50);
	free(img.sprite.image);
}