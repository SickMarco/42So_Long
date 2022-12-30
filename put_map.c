/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:39:13 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/30 20:10:18 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_sprite(void *mlx, char *path, int flag)
{
	t_program p;
	int		x;
	int		y;

	x = 50;
	y = 50;
	if (flag == 0)
	{
		p.sprite.wall = mlx_xpm_file_to_image(mlx, path, &x, &y);
		return (p.sprite.wall);
	}
	else if (flag == 1)
	{
		p.player.img = mlx_xpm_file_to_image(mlx, path, &x, &y);
		return (p.player.img);
	}
	else if (flag == 2)
	{
		p.sprite.floor = mlx_xpm_file_to_image(mlx, path, &x, &y);
		return (p.sprite.floor);
	}
	return (0);
}

void ft_put_map(t_program *p, t_matrix * matrix, char c)
{
	if (c == '1')
		mlx_put_image_to_window(p->mlx, p->window.win, p->sprite.wall, matrix->y * 50, matrix->x * 50);
	else if (c == '0')
		mlx_put_image_to_window(p->mlx, p->window.win, p->sprite.floor, matrix->y * 50, matrix->x * 50);
	else if (c == 'P')
		mlx_put_image_to_window(p->mlx, p->window.win, p->player.img, matrix->y * 50, matrix->x * 50);
	else if (c == 'C')
		mlx_put_image_to_window(p->mlx, p->window.win, p->sprite.collect, matrix->y * 50, matrix->x * 50);
	else if (c == 'E')
		mlx_put_image_to_window(p->mlx, p->window.win, p->sprite.exit, matrix->y * 50, matrix->x * 50);
}

void	ft_map_init(t_program *p, t_matrix *matrix, char c)
{
	if (c == '1')
		p->sprite.wall = ft_sprite(p->mlx, "./Textures/wall50.xpm", 0);
	else if (c == '0')
		p->sprite.floor= ft_sprite(p->mlx, "./Textures/floor50.xpm", 2);
	else if (c == 'P')
	{
		p->player.img = ft_sprite(p->mlx, "./Textures/ghost1.xpm", 1);
		p->player.position.x = matrix->x;
		p->player.position.y = matrix->y;
	}
	else if (c == 'C')
		p->sprite.collect = ft_sprite(p->mlx, "./Textures/key.xpm", 0);
	else if (c == 'E')
		p->sprite.exit = ft_sprite(p->mlx, "./Textures/door.xpm", 0);
	else
		return ;
	ft_put_map(p, matrix, c);
}

void	ft_map(t_program *p, char *map, t_matrix *matrix)
{
	int			lines;

	lines = ft_matrix_lines(map);
	matrix->x = 0;
	matrix->y = 0;
	while (lines > 0)
	{
		while (matrix->mat[matrix->x][matrix->y])
		{
			ft_map_init(p, matrix, matrix->mat[matrix->x][matrix->y]);
			matrix->y++;
		}
		matrix->x++;
		matrix->y = 0;
		lines--;
	}
}

void ft_destroyer(t_program *p)
{
	mlx_destroy_image(p->mlx, p->sprite.collect);
	mlx_destroy_image(p->mlx, p->sprite.wall);
	mlx_destroy_image(p->mlx, p->sprite.exit);
	mlx_destroy_image(p->mlx, p->sprite.floor);
	mlx_destroy_image(p->mlx, p->player.img);
}
