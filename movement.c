/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:10:28 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/06 20:15:43 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_r_mov(t_program *p, int *count)
{
	if (p->matrix.mat[p->player.pos.x][p->player.pos.y + 1] != '1')
	{
		if (p->matrix.mat[p->player.pos.x][p->player.pos.y + 1] == 'E' &&
			p->exit.win == 0)
			return ;
		p->matrix.mat[p->player.pos.x][p->player.pos.y] = '0';
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.floor,
			p->player.pos.y * SIZE, p->player.pos.x * SIZE);
		p->player.pos.y++;
		if (p->matrix.mat[p->player.pos.x][p->player.pos.y] == 'C')
			*count += 1;
		p->matrix.mat[p->player.pos.x][p->player.pos.y] = 'P';
		mlx_put_image_to_window(p->mlx, p->win.win, p->player.img,
			p->player.pos.y * SIZE, p->player.pos.x * SIZE);
	}
}

void	ft_l_mov(t_program *p, int *count)
{
	if (p->matrix.mat[p->player.pos.x][p->player.pos.y - 1] != '1')
	{
		if (p->matrix.mat[p->player.pos.x][p->player.pos.y - 1] == 'E' &&
			p->exit.win == 0)
			return ;
		p->matrix.mat[p->player.pos.x][p->player.pos.y] = '0';
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.floor,
			p->player.pos.y * SIZE, p->player.pos.x * SIZE);
		p->player.pos.y--;
		if (p->matrix.mat[p->player.pos.x][p->player.pos.y] == 'C')
			*count += 1;
		p->matrix.mat[p->player.pos.x][p->player.pos.y] = 'P';
		mlx_put_image_to_window(p->mlx, p->win.win, p->player.img,
			p->player.pos.y * SIZE, p->player.pos.x * SIZE);
	}
}

void	ft_up_mov(t_program *p, int *count)
{
	if (p->matrix.mat[p->player.pos.x - 1][p->player.pos.y] != '1')
	{
		if (p->matrix.mat[p->player.pos.x - 1][p->player.pos.y] == 'E' &&
			p->exit.win == 0)
			return ;
		p->matrix.mat[p->player.pos.x][p->player.pos.y] = '0';
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.floor,
			p->player.pos.y * SIZE, p->player.pos.x * SIZE);
		p->player.pos.x--;
		if (p->matrix.mat[p->player.pos.x][p->player.pos.y] == 'C')
			*count += 1;
		p->matrix.mat[p->player.pos.x][p->player.pos.y] = 'P';
		mlx_put_image_to_window(p->mlx, p->win.win, p->player.img,
			p->player.pos.y * SIZE, p->player.pos.x * SIZE);
	}
}

void	ft_down_mov(t_program *p, int *count)
{
	if (p->matrix.mat[p->player.pos.x + 1][p->player.pos.y] != '1')
	{
		if (p->matrix.mat[p->player.pos.x + 1][p->player.pos.y] == 'E' &&
			p->exit.win == 0)
			return ;
		p->matrix.mat[p->player.pos.x][p->player.pos.y] = '0';
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.floor,
			p->player.pos.y * SIZE, p->player.pos.x * SIZE);
		p->player.pos.x++;
		if (p->matrix.mat[p->player.pos.x][p->player.pos.y] == 'C')
			*count += 1;
		p->matrix.mat[p->player.pos.x][p->player.pos.y] = 'P';
		mlx_put_image_to_window(p->mlx, p->win.win, p->player.img,
			p->player.pos.y * SIZE, p->player.pos.x * SIZE);
	}
}

int	ft_key(int key, void *param)
{
	t_program	*p;
	static int	count = 0;

	p = (t_program *)param;
	if (key == 65307)
		mlx_close(p);
	if (p->end != 1)
	{
		if (key == 100)
			ft_r_mov(p, &count);
		else if (key == 97)
			ft_l_mov(p, &count);
		else if (key == 119)
			ft_up_mov(p, &count);
		else if (key == 115)
			ft_down_mov(p, &count);
		if (key == 100 || key == 97 || key == 119 || key == 115)
			ft_count_move (p);
		ft_printf ("Key pressed: %d\n", key);
	}
	ft_win(p, count);
	ft_lose(p);
	return (0);
}
