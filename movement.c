/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbdozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:10:28 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/01 17:41:27 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_r_mov (t_program *p, int *count, int win)
{
	if (p->matrix.mat[p->player.position.x][p->player.position.y + 1] != '1')
	{
		if (p->matrix.mat[p->player.position.x][p->player.position.y + 1] == 'E' && win == 1)
		{
			ft_win(p);
			return ;
		}
		else if (p->matrix.mat[p->player.position.x][p->player.position.y + 1] == 'E' && win == 0)
			return ;
		p->matrix.mat[p->player.position.x][p->player.position.y] = '0';
		mlx_put_image_to_window(p->mlx, p->window.win, p->sprite.floor, p->player.position.y * SIZE, p->player.position.x * SIZE);
		p->player.position.y++;
		if (p->matrix.mat[p->player.position.x][p->player.position.y] == 'C')
			*count += 1;
		p->matrix.mat[p->player.position.x][p->player.position.y] = 'P';
		mlx_put_image_to_window(p->mlx, p->window.win, p->player.img, p->player.position.y * SIZE, p->player.position.x * SIZE);
	}
}

void ft_l_mov (t_program *p, int *count, int win)
{
	if (p->matrix.mat[p->player.position.x][p->player.position.y - 1] != '1')
	{
		if (p->matrix.mat[p->player.position.x][p->player.position.y - 1] == 'E' && win == 1)
		{
			ft_win(p);
			return ;
		}
		else if (p->matrix.mat[p->player.position.x][p->player.position.y - 1] == 'E' && win == 0)
			return ;
		p->matrix.mat[p->player.position.x][p->player.position.y] = '0';
		mlx_put_image_to_window(p->mlx, p->window.win, p->sprite.floor, p->player.position.y * SIZE, p->player.position.x * SIZE);
		p->player.position.y--;
		if (p->matrix.mat[p->player.position.x][p->player.position.y] == 'C')
			*count += 1;
		p->matrix.mat[p->player.position.x][p->player.position.y] = 'P';
		mlx_put_image_to_window(p->mlx, p->window.win, p->player.img, p->player.position.y * SIZE, p->player.position.x * SIZE);
	}
}

void ft_up_mov (t_program *p, int *count, int win)
{
	if (p->matrix.mat[p->player.position.x - 1][p->player.position.y] != '1')
	{
		if (p->matrix.mat[p->player.position.x - 1][p->player.position.y] == 'E' && win == 1)
		{
			ft_win(p);
			return ;
		}
		else if (p->matrix.mat[p->player.position.x - 1][p->player.position.y] == 'E' && win == 0)
			return ;
		p->matrix.mat[p->player.position.x][p->player.position.y] = '0';
		mlx_put_image_to_window(p->mlx, p->window.win, p->sprite.floor, p->player.position.y * SIZE, p->player.position.x * SIZE);
		p->player.position.x--;
		if (p->matrix.mat[p->player.position.x][p->player.position.y] == 'C')
			*count += 1;
		p->matrix.mat[p->player.position.x][p->player.position.y] = 'P';
		mlx_put_image_to_window(p->mlx, p->window.win, p->player.img, p->player.position.y * SIZE, p->player.position.x * SIZE);
	}
}

void ft_down_mov (t_program *p, int *count, int win)
{
	if (p->matrix.mat[p->player.position.x + 1][p->player.position.y] != '1')
	{
		if (p->matrix.mat[p->player.position.x + 1][p->player.position.y] == 'E' && win == 1)
		{
			ft_win(p);
			return ;
		}
		else if (p->matrix.mat[p->player.position.x + 1][p->player.position.y] == 'E' && win == 0)
			return ;
		p->matrix.mat[p->player.position.x][p->player.position.y] = '0';
		mlx_put_image_to_window(p->mlx, p->window.win, p->sprite.floor, p->player.position.y * SIZE, p->player.position.x * SIZE);
		p->player.position.x++;
		if (p->matrix.mat[p->player.position.x][p->player.position.y] == 'C')
			*count += 1;
		p->matrix.mat[p->player.position.x][p->player.position.y] = 'P';
		mlx_put_image_to_window(p->mlx, p->window.win, p->player.img, p->player.position.y * SIZE, p->player.position.x * SIZE);
	}
}

int	ft_key (int key, void *param)
{
	t_program *p = (t_program *)param;
	
	static int count = 0;
	int win;

	win = 0;
	if (count == p->collect)
		win = 1;
	if (key == 100)
		ft_r_mov(p, &count, win);
	else if (key == 97)
		ft_l_mov(p, &count, win);
	else if (key == 119)
		ft_up_mov(p, &count, win);
	else if (key == 115)
		ft_down_mov(p, &count, win);
	else if (key == 65307)
		mlx_close(p);
	ft_printf ("Key pressed: %d\n", key);
	return (0);
}