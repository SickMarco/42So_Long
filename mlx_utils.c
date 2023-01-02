/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:51:29 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/02 19:29:47 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroyer(t_program *p)
{
	mlx_destroy_image(p->mlx, p->sprite.collect);
	mlx_destroy_image(p->mlx, p->sprite.wall);
	mlx_destroy_image(p->mlx, p->sprite.exit);
	mlx_destroy_image(p->mlx, p->sprite.floor);
	mlx_destroy_image(p->mlx, p->player.img);
	mlx_destroy_image(p->mlx, p->sprite.win);
	mlx_destroy_image(p->mlx, p->exit.open);
	ft_destroy_num(p);
}

int	mlx_close(t_program *p)
{
	mlx_loop_end(p->mlx);
	mlx_clear_window(p->mlx, p->window.win);
	mlx_destroy_window(p->mlx, p->window.win);
	ft_destroyer(p);
	free(p->matrix.mat);
	free(p->mlx);
	exit(0);
}

void	ft_win(t_program *p)
{
	ft_printf("YOU WIN!\n");
	mlx_close(p);
}

void	game_start(t_program *p)
{
	p->mlx = mlx_init();
	p->window.size.x = 0;
	p->window.size.y = 0;
	p->window.size.x = ft_strlen(p->matrix.mat[p->matrix.x]);
	p->window.size.y = p->matrix.lines;
	p->window.win = mlx_new_window(p->mlx, p->window.size.x * SIZE,
			p->window.size.y * SIZE, "so_long");
	ft_map(p);
}
