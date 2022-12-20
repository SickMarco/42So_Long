/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:51:29 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/19 17:13:14 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int mlx_close()
{
	exit(0);
}

void mlx_start(char *map)
{
	t_program start;

	start.mlx = mlx_init();
	ft_window(map, start.mlx);
	mlx_loop(start.mlx);
}

void ft_window(char *path, void *mlx)
{
	t_window window;
	int fd;
	char *line;

	window.size.x = 0;
	window.size.y = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	window.size.x = ft_strlen(line);
	while (line != NULL)
	{
		window.size.y++;
		free(line);
		line = get_next_line(fd);
	}
	window.win = mlx_new_window(mlx, window.size.x * 50,  window.size.y * 50, "so_long");
	mlx_hook(window.win, 17, 0, mlx_close, 0);
	free(path);
	free(line);
}
