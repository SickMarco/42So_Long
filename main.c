/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:28:41 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/06 21:42:38 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_arguments(int ac)
{
	if (ac < 2)
		ft_printf("\033[0;31mError\nInsert map\n\033[0;37m");
	else if (ac > 2)
		ft_printf("\033[0;31mError\nToo many arguments\n\033[0;37m");
}

int	ft_check_map(t_program *game, char *path)
{
	if (ft_matrix(path, game) == 1)
	{
		ft_printf("\033[0;31mError\nInvalid Map\n\033[0;37m");
		return (1);
	}
	if (ft_check_map_error(game) == 1)
	{
		while (game->matrix.lines >= 0)
		{
			free(game->matrix.mat[game->matrix.lines]);
			game->matrix.lines--;
		}
		free(path);
		free(game->matrix.mat);
		ft_printf("\033[0;31mError\nMap Error\n\033[0;37m");
		return (1);
	}
	free(path);
	return (0);
}

int	mlx_close(t_program *p)
{
	mlx_clear_window(p->mlx, p->win.win);
	mlx_loop_end(p->mlx);
	mlx_destroy_window(p->mlx, p->win.win);
	ft_destroyer(p);
	free(p->anim);
	while (p->matrix.mat[p->matrix.lines])
	{
		free(p->matrix.mat[p->matrix.lines]);
		p->matrix.lines++;
	}
	free(p->matrix.mat);
	mlx_destroy_display(p->mlx);
	free(p->mlx);
	exit(0);
}

void	game_loop(t_program *game)
{
	game->end = 0;
	game->enemy.random = 0;
	game->enemy.wait = 0;
	mlx_hook(game->win.win, 17, 0, mlx_close, game);
	mlx_key_hook(game->win.win, *ft_key, game);
	mlx_loop_hook(game->mlx, *ft_animation, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char**av)
{
	t_program	game;
	char		*path;

	if (ac == 2)
	{
		path = ft_strjoin("./Maps/", av[1]);
		if (ft_check_map(&game, path) == 1)
			return (0);
		game_start(&game);
		game_loop(&game);
	}
	else
		ft_arguments(ac);
	return (0);
}
