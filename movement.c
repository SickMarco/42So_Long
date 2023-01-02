/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:10:28 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/02 17:24:12 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_r_mov(t_program *p, int *count, int win)
{
	if (p->matrix.mat[p->player.pos.x][p->player.pos.y + 1] != '1')
	{
		if (p->matrix.mat[p->player.pos.x][p->player.pos.y + 1] == 'E' &&
			win == 1)
		{
			ft_win(p);
			return ;
		}
		else if (p->matrix.mat[p->player.pos.x][p->player.pos.y + 1] == 'E' &&
			win == 0)
			return ;
		p->matrix.mat[p->player.pos.x][p->player.pos.y] = '0';
		mlx_put_image_to_window(p->mlx, p->window.win, p->sprite.floor,
			p->player.pos.y * SIZE, p->player.pos.x * SIZE);
		p->player.pos.y++;
		if (p->matrix.mat[p->player.pos.x][p->player.pos.y] == 'C')
			*count += 1;
		p->matrix.mat[p->player.pos.x][p->player.pos.y] = 'P';
		mlx_put_image_to_window(p->mlx, p->window.win, p->player.img,
			p->player.pos.y * SIZE, p->player.pos.x * SIZE);
	}
}

void	ft_l_mov(t_program *p, int *count, int win)
{
	if (p->matrix.mat[p->player.pos.x][p->player.pos.y - 1] != '1')
	{
		if (p->matrix.mat[p->player.pos.x][p->player.pos.y - 1] == 'E' &&
			win == 1)
		{
			ft_win(p);
			return ;
		}
		else if (p->matrix.mat[p->player.pos.x][p->player.pos.y - 1] == 'E' &&
			win == 0)
			return ;
		p->matrix.mat[p->player.pos.x][p->player.pos.y] = '0';
		mlx_put_image_to_window(p->mlx, p->window.win, p->sprite.floor,
			p->player.pos.y * SIZE, p->player.pos.x * SIZE);
		p->player.pos.y--;
		if (p->matrix.mat[p->player.pos.x][p->player.pos.y] == 'C')
			*count += 1;
		p->matrix.mat[p->player.pos.x][p->player.pos.y] = 'P';
		mlx_put_image_to_window(p->mlx, p->window.win, p->player.img,
			p->player.pos.y * SIZE, p->player.pos.x * SIZE);
	}
}

void	ft_up_mov(t_program *p, int *count, int win)
{
	if (p->matrix.mat[p->player.pos.x - 1][p->player.pos.y] != '1')
	{
		if (p->matrix.mat[p->player.pos.x - 1][p->player.pos.y] == 'E' &&
			win == 1)
		{
			ft_win(p);
			return ;
		}
		else if (p->matrix.mat[p->player.pos.x - 1][p->player.pos.y] == 'E' &&
			win == 0)
			return ;
		p->matrix.mat[p->player.pos.x][p->player.pos.y] = '0';
		mlx_put_image_to_window(p->mlx, p->window.win, p->sprite.floor,
			p->player.pos.y * SIZE, p->player.pos.x * SIZE);
		p->player.pos.x--;
		if (p->matrix.mat[p->player.pos.x][p->player.pos.y] == 'C')
			*count += 1;
		p->matrix.mat[p->player.pos.x][p->player.pos.y] = 'P';
		mlx_put_image_to_window(p->mlx, p->window.win, p->player.img,
			p->player.pos.y * SIZE, p->player.pos.x * SIZE);
	}
}

void	ft_down_mov(t_program *p, int *count, int win)
{
	if (p->matrix.mat[p->player.pos.x + 1][p->player.pos.y] != '1')
	{
		if (p->matrix.mat[p->player.pos.x + 1][p->player.pos.y] == 'E' &&
			win == 1)
		{
			ft_win(p);
			return ;
		}
		else if (p->matrix.mat[p->player.pos.x + 1][p->player.pos.y] == 'E' &&
			win == 0)
			return ;
		p->matrix.mat[p->player.pos.x][p->player.pos.y] = '0';
		mlx_put_image_to_window(p->mlx, p->window.win, p->sprite.floor,
			p->player.pos.y * SIZE, p->player.pos.x * SIZE);
		p->player.pos.x++;
		if (p->matrix.mat[p->player.pos.x][p->player.pos.y] == 'C')
			*count += 1;
		p->matrix.mat[p->player.pos.x][p->player.pos.y] = 'P';
		mlx_put_image_to_window(p->mlx, p->window.win, p->player.img,
			p->player.pos.y * SIZE, p->player.pos.x * SIZE);
	}
}

int	ft_key(int key, void *param)
{
	t_program	*p;
	static int	count = 0;
	static int	win = 0;

	p = (t_program *)param;
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
	if (count == p->collect)
	{
		win = 1;
		mlx_put_image_to_window(p->mlx, p->window.win, p->exit.open,
			p->exit.pos.y * SIZE, p->exit.pos.x * SIZE);
	}
	ft_printf ("Key pressed: %d\n", key);
	return (0);
}