/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:51:29 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/31 17:55:03 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int mlx_close()
{
	exit(0);
}

void ft_window(t_program *p)
{
	p->window.size.x = 0;
	p->window.size.y = 0;
	p->window.size.x = ft_strlen(p->matrix.mat[p->matrix.x]);
	p->window.size.y = ft_matrix_lines(p);
	p->window.win = mlx_new_window(p->mlx, p->window.size.x * SIZE,  p->window.size.y * SIZE, "so_long");
}

void ft_destroyer(t_program *p)
{
	mlx_destroy_image(p->mlx, p->sprite.collect);
	mlx_destroy_image(p->mlx, p->sprite.wall);
	mlx_destroy_image(p->mlx, p->sprite.exit);
	mlx_destroy_image(p->mlx, p->sprite.floor);
	mlx_destroy_image(p->mlx, p->player.img);
}

void mlx_start(t_program *game)
{
	game->mlx = mlx_init();
	ft_window(game);
	ft_map(game);
	mlx_hook(game->window.win, 17, 0, mlx_close, 0);
}