/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:48:13 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/29 18:40:53 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_check_map_format(char *map)
{
	int 	i;
	char 	*ber;
	int 	fd;
	
	ber = "ber\0";
	i = 7;
	while (map[i - 1] != '.' && map[i])
		i++;
	if (ft_strncmp(&map[i],&ber[0], 4) != 0)
		return (1);
	fd = open (map, O_RDONLY);
	if (fd == -1)
		return (1);
	close (fd);
	return (0);
}

int ft_wall_controll(char **matrix, int x, int y, int flag)
{
	if (flag == 1)
	{
		if (matrix[x][y + 1] == '1' && matrix[x][y - 1] == '1' 
			&& matrix[x + 1][y] == '1' && matrix[x - 1][y] == '1')
			return (1);
	}
	else if (flag == 0)
	{
		while (matrix[x][y])
		{
			if (matrix[x][y] != '1')
				return (1);
			if (matrix[x][y] != '\0')
				y++;
		}
	}
	return (0);
}

int ft_lines_controll(char **mat, int lines, int x, int y)
{
	int len;

	len = ft_strlen(mat[x]);
	while (x < lines - 1)
	{
		if (mat[x][0]  != '1' && mat[x][ft_strlen(mat[x])] != '1')
			return (1);
		while (mat[x][y] != '\0')
		{
			if (mat[x][y] != 'C' && mat[x][y] != 'E' && mat[x][y] != 'P' 
				&& mat[x][y] != '0' && mat[x][y] != '1')
				return (1);
			else if (mat[x][y] == 'C' || mat[x][y] == 'E' || mat[x][y] == 'P')
				if (ft_wall_controll(mat, x , y, 1) == 1)
					return (1);
			y++;
		}
		if (len != y)
			return (1);
		x++;
		y = 0;
	}
	if (ft_wall_controll(mat, x , y, 0) == 1)
		return (1);
	return (0);
}
int ft_check_collectible(char **matrix, int lines, int x, int y)
{
	static int check_c = 0;
	static int check_p = 0;
	static int check_e = 0;
	
	while (x < lines - 1)
	{
		while (matrix[x][y])
		{
			if (matrix[x][y] == 'C')
				check_c++;
			else if (matrix[x][y] == 'P')
				check_p++;
			else if (matrix[x][y] == 'E')
				check_e++;
			y++;
		}
		x++;
		y = 0;
	}
	if (check_c > 0 && check_e == 1 && check_p == 1)
		return (0);
	return(1);
}

int ft_check_map_error(char *path, char **mat)
{
	t_matrix 	matrix;
	int			lines;

	matrix.x = 0;
	matrix.y = 0;
	lines = ft_matrix_lines(path);
	if (ft_strlen(mat[matrix.x]) == lines)
		return (1);
	if (ft_wall_controll(mat, matrix.x , matrix.y, 0) == 1)
		return (1);
	matrix.x++;
	if (ft_lines_controll(mat, lines, matrix.x, matrix.y) == 1)
		return (1);
	if (ft_check_collectible(mat, lines, matrix.x, matrix.y) == 1)
		return (1);
	return (0);
}

