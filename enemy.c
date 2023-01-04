/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:05:08 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/04 18:12:07 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_up(t_program *p)
{
	if (p->matrix.mat[p->enemy.pos.x - 1][p->enemy.pos.y] != '1'
		&& p->matrix.mat[p->enemy.pos.x - 1][p->enemy.pos.y] != 'E'
		&& p->matrix.mat[p->enemy.pos.x - 1][p->enemy.pos.y] != 'C')
	{
		p->matrix.mat[p->enemy.pos.x][p->enemy.pos.y] = '0';
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.floor,
			p->enemy.pos.y * SIZE, p->enemy.pos.x * SIZE);
		p->enemy.pos.x--;
		p->matrix.mat[p->enemy.pos.x][p->enemy.pos.y] = 'K';
		mlx_put_image_to_window(p->mlx, p->win.win, p->enemy.img,
			p->enemy.pos.y * SIZE, p->enemy.pos.x * SIZE);
	}
	else if (p->matrix.mat[p->enemy.pos.x + 1][p->enemy.pos.y] != '1'
		&& p->matrix.mat[p->enemy.pos.x + 1][p->enemy.pos.y] != 'E'
		&& p->matrix.mat[p->enemy.pos.x + 1][p->enemy.pos.y] != 'C')
		enemy_down(p);
	else
		return ;
}

void	enemy_down(t_program *p)
{
	if (p->matrix.mat[p->enemy.pos.x + 1][p->enemy.pos.y] != '1'
		&& p->matrix.mat[p->enemy.pos.x + 1][p->enemy.pos.y] != 'E'
		&& p->matrix.mat[p->enemy.pos.x + 1][p->enemy.pos.y] != 'C')
	{
		p->matrix.mat[p->enemy.pos.x][p->enemy.pos.y] = '0';
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.floor,
			p->enemy.pos.y * SIZE, p->enemy.pos.x * SIZE);
		p->enemy.pos.x++;
		p->matrix.mat[p->enemy.pos.x][p->enemy.pos.y] = 'K';
		mlx_put_image_to_window(p->mlx, p->win.win, p->enemy.img,
			p->enemy.pos.y * SIZE, p->enemy.pos.x * SIZE);
	}
	else if (p->matrix.mat[p->enemy.pos.x - 1][p->enemy.pos.y] != '1'
		&& p->matrix.mat[p->enemy.pos.x - 1][p->enemy.pos.y] != 'E'
		&& p->matrix.mat[p->enemy.pos.x - 1][p->enemy.pos.y] != 'C')
		enemy_up(p);
	else
		return ;
}

void	enemy_left(t_program *p)
{
	if (p->matrix.mat[p->enemy.pos.x][p->enemy.pos.y - 1] != '1'
		&& p->matrix.mat[p->enemy.pos.x][p->enemy.pos.y - 1] != 'E'
		&& p->matrix.mat[p->enemy.pos.x][p->enemy.pos.y - 1] != 'C')
	{
		p->matrix.mat[p->enemy.pos.x][p->enemy.pos.y] = '0';
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.floor,
			p->enemy.pos.y * SIZE, p->enemy.pos.x * SIZE);
		p->enemy.pos.y--;
		p->matrix.mat[p->enemy.pos.x][p->enemy.pos.y] = 'K';
		mlx_put_image_to_window(p->mlx, p->win.win, p->enemy.img,
			p->enemy.pos.y * SIZE, p->enemy.pos.x * SIZE);
	}
	else if (p->matrix.mat[p->enemy.pos.x][p->enemy.pos.y + 1] != '1'
		&& p->matrix.mat[p->enemy.pos.x][p->enemy.pos.y + 1] != 'E'
		&& p->matrix.mat[p->enemy.pos.x][p->enemy.pos.y + 1] != 'C')
		enemy_right(p);
	else
		return ;
}

void	enemy_right(t_program *p)
{
	if (p->matrix.mat[p->enemy.pos.x][p->enemy.pos.y + 1] != '1'
		&& p->matrix.mat[p->enemy.pos.x][p->enemy.pos.y + 1] != 'E'
		&& p->matrix.mat[p->enemy.pos.x][p->enemy.pos.y + 1] != 'C')
	{
		p->matrix.mat[p->enemy.pos.x][p->enemy.pos.y] = '0';
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.floor,
			p->enemy.pos.y * SIZE, p->enemy.pos.x * SIZE);
		p->enemy.pos.y++;
		p->matrix.mat[p->enemy.pos.x][p->enemy.pos.y] = 'K';
		mlx_put_image_to_window(p->mlx, p->win.win, p->enemy.img,
			p->enemy.pos.y * SIZE, p->enemy.pos.x * SIZE);
	}
	else if (p->matrix.mat[p->enemy.pos.x][p->enemy.pos.y - 1] != '1'
		&& p->matrix.mat[p->enemy.pos.x][p->enemy.pos.y - 1] != 'E'
		&& p->matrix.mat[p->enemy.pos.x][p->enemy.pos.y - 1] != 'C')
		enemy_left(p);
	else
		return ;
}

int	enemy_move(void *param)
{
	t_program	*p;
	int			move;

	p = (t_program *)param;
	move = 0;
	move = rand() % (4 + 1 - 1);
	if (p->enemy.pos.x == p->player.pos.x && p->enemy.pos.y == p->player.pos.y)
	{
		ft_printf("YOU LOSE!\n");
		mlx_close(p);
	}
	if (move == 1)
		enemy_up(p);
	else if (move == 2)
		enemy_down(p);
	else if (move == 3)
		enemy_left(p);
	else if (move == 4)
		enemy_right(p);
	usleep(400000);
	return (0);
}
