/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:48:13 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/20 16:48:18 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_arguments(int ac)
{
	if (ac < 2)
		ft_printf ("\033[0;31mInsert map\n");
	else if (ac > 2)
		ft_printf ("\033[0;31mToo many arguments\n");
}

int ft_check_map_format(char *map)
{
	int i;
	char ber[4] = {'b','e','r','\0'};

	i = 7;
	while (map[i - 1] != '.')
		i++;
	if (ft_strncmp(&map[i],&ber[0], 4) != 0)
		return (1);
	return (0);
}

int ft_wall_controll(char **matrix, int x, int y, int flag)
{
	if (flag == 1)
	{
		if (matrix[x][y + 1] == '1' && matrix[x][y - 1] == '1' && matrix[x + 1][y] == '1' && matrix[x - 1][y] == '1')
			return (1);
	}
	else if (flag == 0)
	{
		while (matrix[x][y + 1])
		{
			if (matrix[x][y] != '1')
				return (1);
			y++;
		}
	}
	return (0);
}

int ft_check_map_error(char *path)
{
	t_matrix 	matrix;
	int			lines;

	matrix.x = 0;
	matrix.y = 0;
	lines = 0;
	matrix.mat = ft_matrix(path, &lines);
	if (ft_wall_controll(matrix.mat, matrix.x , matrix.y, 0) == 1)
			return (1);
	matrix.x++;
	while (matrix.x < lines - 1)
	{
		matrix.y = 0;
		while (matrix.mat[matrix.x][matrix.y] != 'C' && matrix.mat[matrix.x][matrix.y] != 'E' && matrix.mat[matrix.x][matrix.y] != 'P')
			matrix.y++;
		if (ft_wall_controll(matrix.mat, matrix.x , matrix.y, 1) == 1)
			return (1);
		while (matrix.mat[matrix.x][matrix.y] != '\0')
			matrix.y++;
		matrix.x++;
	}
	matrix.y = 0;
	if (ft_wall_controll(matrix.mat, matrix.x , matrix.y, 0) == 1)
		return (1);
	free(matrix.mat);
	return (0);
}

