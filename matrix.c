/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:35:00 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/28 15:56:27 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *get_one_line(char *path, int i)
{
	t_matrix 	matrix;
	char 		*buff;

	matrix.fd = open(path, O_RDONLY);
	matrix.line = get_next_line(matrix.fd);
	buff = ft_calloc(sizeof(char), (i * ft_strlen(matrix.line) + 1));
	if (!buff)
		return (NULL);
	while (matrix.line != NULL)
	{
		buff = ft_strjoin2(buff, matrix.line);
		free(matrix.line);
		matrix.line = get_next_line(matrix.fd);
	}
	free(matrix.line);
	close(matrix.fd);
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
	matrix.mat = ft_split(get_one_line(path, i), '\n');
	return (matrix.mat);
}

int ft_matrix_lines(char *path)
{
	t_matrix 	matrix;
	int 		i;

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
	return (i);
}
