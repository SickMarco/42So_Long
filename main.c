/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:28:41 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/31 17:55:24 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_arguments(int ac)
{
	if (ac < 2)
		ft_printf("\033[0;31mError\nInsert map\n");
	else if (ac > 2)
		ft_printf("\033[0;31mError\nToo many arguments\n");
}

int main(int ac, char**av)
{
	t_program game;
	char *path;
	
	path = ft_strjoin("./Maps/", av[1]);
	if (ac == 2)
	{
		game.matrix.mat = ft_matrix(path);
		if (ft_check_map_format(path) == 1)
			return (ft_printf("\033[0;31mError\nWrong Map Format\n"));
		else if (ft_check_map_error(&game) == 1)
			return (ft_printf("\033[0;31mError\nMap Error\n"));
		free(path);
		mlx_start(&game);
		mlx_key_hook(game.window.win, *ft_key, &game);
		mlx_loop(game.mlx);
	}
	else
		ft_arguments(ac);
}
