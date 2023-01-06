/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:51:29 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/06 21:39:47 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_start(t_program *p)
{
	p->mlx = mlx_init();
	p->win.size.x = ft_strlen(p->matrix.mat[p->matrix.x]);
	p->win.size.y = p->matrix.lines;
	p->win.win = mlx_new_window(p->mlx, p->win.size.x * SIZE,
			p->win.size.y * SIZE, "so_long");
	p->exit.win = 0;
	ft_map(p);
}

void	get_matrix(char *path, t_program *p)
{
	static char	*buff;

	p->matrix.fd = open(path, O_RDONLY);
	p->matrix.line = get_next_line(p->matrix.fd);
	if (!buff)
		buff = ft_calloc2(sizeof(char), 1);
	while (p->matrix.line != NULL)
	{
		buff = ft_strjoin2(buff, p->matrix.line);
		free(p->matrix.line);
		p->matrix.line = get_next_line(p->matrix.fd);
	}
	close(p->matrix.fd);
	free(p->matrix.line);
	p->matrix.mat = ft_split(buff, '\n');
	free(buff);
}

int	ft_matrix(char *path, t_program *p)
{
	p->matrix.lines = 0;
	p->matrix.fd = open(path, O_RDONLY);
	if (p->matrix.fd == -1)
	{
		close(p->matrix.fd);
		free(path);
		return (1);
	}
	p->matrix.line = get_next_line(p->matrix.fd);
	while (p->matrix.line != NULL)
	{
		free(p->matrix.line);
		p->matrix.line = get_next_line(p->matrix.fd);
		p->matrix.lines++;
	}
	free(p->matrix.line);
	close(p->matrix.fd);
	get_matrix(path, p);
	return (0);
}

void	ft_win(t_program *p, int count)
{
	static int	flag = 0;

	if (flag == 0)
	{
		if (count == p->collect && p->exit.win == 0)
		{
			p->exit.win = 1;
			mlx_put_image_to_window(p->mlx, p->win.win, p->exit.open,
				p->exit.pos.y * SIZE, p->exit.pos.x * SIZE);
		}
		if (p->player.pos.x == p->exit.pos.x && p->player.pos.y == p->exit.pos.y
			&& p->exit.win == 1)
		{
			p->end = 1;
			mlx_clear_window(p->mlx, p->win.win);
			mlx_string_put(p->mlx, p->win.win, p->win.size.x * SIZE / 2 - 25,
				p->win.size.y * SIZE / 2, 0xFFFF0000, "YOU WIN!");
			ft_printf("Close game with ESC or ✖\n");
			flag = 1;
		}
	}
	return ;
}

void	ft_lose(t_program *p)
{
	static int	flag = 0;

	if (flag == 0)
	{
		if (p->player.pos.x == p->enemy.pos.x
			&& p->player.pos.y == p->enemy.pos.y)
		{
			mlx_put_image_to_window(p->mlx, p->win.win, p->enemy.lose,
				p->enemy.pos.y * SIZE, p->enemy.pos.x * SIZE);
			p->end = 1;
			mlx_string_put(p->mlx, p->win.win, p->win.size.x * SIZE / 2 - 25,
				p->win.size.y * SIZE / 2, 0xFFFF0000, "YOU LOSE!");
			ft_printf("Close game with ESC or ✖\n");
			flag++;
		}
	}
	return ;
}
