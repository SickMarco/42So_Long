/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:48:13 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/05 00:38:37 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_format(char *map)
{
	int		i;
	char	*ber;
	int		fd;

	ber = "ber\0";
	i = 7;
	while (map[i - 1] != '.' && map[i])
		i++;
	if (ft_strncmp(&map[i], &ber[0], 4) != 0)
		return (1);
	fd = open (map, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (1);
	}
	close (fd);
	return (0);
}

int	ft_wall_controll(t_program *p, int x, int y, int flag)
{
	if (flag == 1)
	{
		if (p->matrix.mat[x][y + 1] == '1' && p->matrix.mat[x][y - 1] == '1'
			&& p->matrix.mat[x + 1][y] == '1' && p->matrix.mat[x - 1][y] == '1')
			return (1);
	}
	if (flag == 0)
	{
		while (p->matrix.mat[x][y])
		{
			if (p->matrix.mat[x][y] != '1')
				return (1);
			y++;
		}
		p->num.pos_x = y;
	}
	return (0);
}

int	ft_lines_controll(t_program *p, int x, int y, int len)
{
	while (x < p->matrix.lines - 1)
	{
		if (p->matrix.mat[x][0] != '1' && p->matrix.mat[x][len] != '1')
			return (1);
		while (p->matrix.mat[x][y] != '\0')
		{
			if (p->matrix.mat[x][y] != 'C' && p->matrix.mat[x][y] != 'E' &&
				p->matrix.mat[x][y] != 'P' && p->matrix.mat[x][y] != '0' &&
				p->matrix.mat[x][y] != '1' && p->matrix.mat[x][y] != 'K')
				return (1);
			else if (p->matrix.mat[x][y] == 'C' || p->matrix.mat[x][y] == 'E' ||
				p->matrix.mat[x][y] == 'P')
				if (ft_wall_controll(p, x, y, 1) == 1)
					return (1);
			y++;
		}
		if (len != y)
			return (1);
		x++;
		y = 0;
	}
	if (ft_wall_controll(p, x, y, 0) == 1)
		return (1);
	return (0);
}

int	ft_check_collectible(t_program *p, int x, int y)
{
	static int	check_c = 0;
	static int	check_p = 0;
	static int	check_e = 0;

	while (x < p->matrix.lines - 1)
	{
		while (p->matrix.mat[x][y])
		{
			if (p->matrix.mat[x][y] == 'C')
				check_c++;
			else if (p->matrix.mat[x][y] == 'P')
				check_p++;
			else if (p->matrix.mat[x][y] == 'E')
				check_e++;
			y++;
		}
		x++;
		y = 0;
	}
	if (check_c > 0 && check_e == 1 && check_p == 1)
		return (0);
	return (1);
}

int	ft_check_map_error(t_program *p)
{
	int	len;

	p->matrix.x = 0;
	p->matrix.y = 0;
	len = ft_strlen(p->matrix.mat[0]);
	if (ft_strlen(p->matrix.mat[p->matrix.x]) == p->matrix.lines)
		return (1);
	if (ft_wall_controll(p, p->matrix.x, p->matrix.y, 0) == 1)
		return (1);
	p->matrix.x++;
	if (ft_lines_controll(p, p->matrix.x, p->matrix.y, len) == 1)
		return (1);
	if (ft_check_collectible(p, p->matrix.x, p->matrix.y) == 1)
		return (1);
	return (0);
}
