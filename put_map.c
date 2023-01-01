/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:39:13 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/01 20:51:21 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_sprite(t_program *p)
{
	static int	x = 50;
	static int	y = 50;

	p->sprite.wall = mlx_xpm_file_to_image(p->mlx, "./Textures/wall50.xpm",  &x, &y);
	p->player.img = mlx_xpm_file_to_image(p->mlx, "./Textures/ghost1.xpm", &x, &y);
	p->sprite.floor = mlx_xpm_file_to_image(p->mlx, "./Textures/floor50.xpm", &x, &y);
	p->sprite.collect = mlx_xpm_file_to_image(p->mlx, "./Textures/key.xpm", &x, &y);
	p->sprite.exit = mlx_xpm_file_to_image(p->mlx, "./Textures/door.xpm", &x, &y);
	p->sprite.win = mlx_xpm_file_to_image(p->mlx, "./Textures/win.xpm", &x, &y);
}

void ft_put_map(t_program *p, char c)
{
	if (c == '1')
		mlx_put_image_to_window(p->mlx, p->window.win, p->sprite.wall, p->matrix.y * SIZE, p->matrix.x * SIZE);
	else if (c == '0')
		mlx_put_image_to_window(p->mlx, p->window.win, p->sprite.floor, p->matrix.y * SIZE, p->matrix.x * SIZE);
	else if (c == 'P')
		mlx_put_image_to_window(p->mlx, p->window.win, p->player.img, p->matrix.y * SIZE, p->matrix.x * SIZE);
	else if (c == 'C')
		mlx_put_image_to_window(p->mlx, p->window.win, p->sprite.collect, p->matrix.y * SIZE, p->matrix.x * SIZE);
	else if (c == 'E')
		mlx_put_image_to_window(p->mlx, p->window.win, p->sprite.exit, p->matrix.y * SIZE, p->matrix.x * SIZE);
}

void	ft_map(t_program *p)
{
	p->matrix.x = 0;
	p->matrix.y = 0;
	p->collect = 0;
	ft_sprite(p);
	while (p->matrix.lines > 0)
	{
		while (p->matrix.mat[p->matrix.x][p->matrix.y])
		{
			if (p->matrix.mat[p->matrix.x][p->matrix.y] == 'P')
			{
				p->player.position.x = p->matrix.x;
				p->player.position.y = p->matrix.y;
			}
			else if (p->matrix.mat[p->matrix.x][p->matrix.y] == 'C')
				p->collect++;
			ft_put_map(p, p->matrix.mat[p->matrix.x][p->matrix.y]);
			p->matrix.y++;
		}
		p->matrix.x++;
		p->matrix.y = 0;
		p->matrix.lines--;
	}
}
