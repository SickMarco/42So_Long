/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:35:00 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/31 17:15:05 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *get_one_line(char *path)
{
	t_matrix 			matrix;
	static char 		*buff;

	matrix.fd = open(path, O_RDONLY);
	matrix.line = get_next_line(matrix.fd);
	if (!buff)
		buff = ft_calloc2(sizeof(char), 1);
	while (matrix.line != NULL)
	{
		buff = ft_strjoin2(buff, matrix.line);
		free(matrix.line);
		matrix.line = get_next_line(matrix.fd);
	}
	close(matrix.fd);
	free(matrix.line);
	return(buff);
}

char **ft_matrix(char *path)
{
	t_matrix matrix;
	int 	i;

	i = 0;
	matrix.fd = open(path, O_RDONLY);
	matrix.line = get_next_line(matrix.fd);
	while (matrix.line != NULL)
	{
		free(matrix.line);
		matrix.line = get_next_line(matrix.fd);
		i++;
	}
	free(matrix.line);
	close (matrix.fd);
	matrix.mat = ft_split(get_one_line(path), '\n');
	return (matrix.mat);
}

int ft_matrix_lines(t_program *p)
{
	p->matrix.x = 0;
	p->matrix.y = 0;
	while (p->matrix.mat[p->matrix.x])
	{
		while (p->matrix.mat[p->matrix.x][p->matrix.y])
			p->matrix.y++;
		p->matrix.x++;
		p->matrix.y = 0;
	}
	return (p->matrix.x);
}

