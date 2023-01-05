/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:51:29 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/05 12:07:18 by mbozzi           ###   ########.fr       */
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

void	ft_matrix(char *path, t_program *p)
{
	p->matrix.lines = 0;
	p->matrix.fd = open(path, O_RDONLY);
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
}

int	ft_win(t_program *p)
{
	if (p->player.pos.x == p->exit.pos.x && p->player.pos.y == p->exit.pos.y
		&& p->exit.win == 1)
	{
		ft_printf("YOU WIN!\n");
		mlx_close(p);
	}
	return (0);
}

void	ft_destroyer(t_program *p)
{
	mlx_destroy_image(p->mlx, p->sprite.collect);
	mlx_destroy_image(p->mlx, p->sprite.wall);
	mlx_destroy_image(p->mlx, p->sprite.exit);
	mlx_destroy_image(p->mlx, p->sprite.floor);
	mlx_destroy_image(p->mlx, p->player.img);
	mlx_destroy_image(p->mlx, p->exit.open);
	mlx_destroy_image(p->mlx, p->enemy.img);
	ft_destroy_num(p);
}
