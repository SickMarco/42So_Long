/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:10:28 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/31 18:24:19 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_r_mov (t_program *p)
{
	if (p->matrix.mat[p->player.position.y + 1][p->player.position.x] != '1')
	{
		p->matrix.mat[p->player.position.y][p->player.position.x] = '0';
		mlx_put_image_to_window(p->mlx, p->window.win, p->sprite.floor, p->player.position.y * SIZE, p->player.position.x * SIZE);
		p->player.position.y++;
		p->matrix.mat[p->player.position.y][p->player.position.x] = '1';
		mlx_put_image_to_window(p->mlx, p->window.win, p->player.img, p->player.position.y * SIZE, p->player.position.x * SIZE);
	}
}

void ft_l_mov (t_program *p)
{
	if (p->matrix.mat[p->player.position.y - 1][p->player.position.x] != '1')
	{
		p->matrix.mat[p->player.position.y][p->player.position.x] = '0';
		mlx_put_image_to_window(p->mlx, p->window.win, p->sprite.floor, p->player.position.y * SIZE, p->player.position.x * SIZE);
		p->player.position.y--;
		p->matrix.mat[p->player.position.y][p->player.position.x] = '1';
		mlx_put_image_to_window(p->mlx, p->window.win, p->player.img, p->player.position.y * SIZE, p->player.position.x * SIZE);
	}
}

void ft_up_mov (t_program *p)
{
	if (p->matrix.mat[p->player.position.y][p->player.position.x - 1] != '1')
	{
		p->matrix.mat[p->player.position.y][p->player.position.x] = '0';
		mlx_put_image_to_window(p->mlx, p->window.win, p->sprite.floor, p->player.position.y * SIZE, p->player.position.x * SIZE);
		p->player.position.x--;
		p->matrix.mat[p->player.position.y][p->player.position.x] = '1';
		mlx_put_image_to_window(p->mlx, p->window.win, p->player.img, p->player.position.y * SIZE, p->player.position.x * SIZE);
	}
}

void ft_down_mov (t_program *p)
{
	if (p->matrix.mat[p->player.position.y][p->player.position.x + 1] != '1')
	{
		p->matrix.mat[p->player.position.y][p->player.position.x] = '0';
		mlx_put_image_to_window(p->mlx, p->window.win, p->sprite.floor, p->player.position.y * SIZE, p->player.position.x * SIZE);
		p->player.position.x++;
		p->matrix.mat[p->player.position.y][p->player.position.x] = '1';
		mlx_put_image_to_window(p->mlx, p->window.win, p->player.img, p->player.position.y * SIZE, p->player.position.x * SIZE);
	}
}

int	ft_key (int key, void *param)
{
	t_program *p = (t_program *)param;

	if (key == 100)
		ft_r_mov(p);
	else if (key == 97)
		ft_l_mov(p);
	else if (key == 119)
		ft_up_mov(p);
	else if (key == 115)
		ft_down_mov(p);
	else if (key == 17)
		ft_destroyer(p);
	ft_printf ("%d %d", p->player.position.y, p->player.position.x);
	ft_printf ("Key pressed: %d\n", key);
	return (0);
}