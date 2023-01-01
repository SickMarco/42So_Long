/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:35:00 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/01 20:49:11 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *get_one_line(char *path, t_program *p)
{
	static char 		*buff;

	p->matrix.fd = open(path, O_RDONLY);
	p->matrix.line = get_next_line(p->matrix.fd);
	if (!buff)
		buff = ft_calloc2(sizeof(char), 1);
	while (p->matrix.line != NULL)
	{
		buff = ft_strjoin2(buff, p->matrix.line);
		free(p->matrix.line);
		p->matrix.line = get_next_line(p->matrix.fd);
	}
	close(p->matrix.fd);
	free(p->matrix.line);
	return(buff);
}

char **ft_matrix(char *path, t_program *p)
{

	p->matrix.lines = 0;
	p->matrix.fd = open(path, O_RDONLY);
	p->matrix.line = get_next_line(p->matrix.fd);
	while (p->matrix.line != NULL)
	{
		free(p->matrix.line);
		p->matrix.line = get_next_line(p->matrix.fd);
		p->matrix.lines++;
	}
	free(p->matrix.line);
	close (p->matrix.fd);
	p->matrix.mat = ft_split(get_one_line(path, p), '\n');
	return (p->matrix.mat);
}
