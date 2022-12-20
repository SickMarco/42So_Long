/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:09:32 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/20 16:35:21 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../minilibx-linux/mlx.h"
#include "./Lib/Libft/libft.h"
#include "./Lib/Printf/ft_printf.h"
#include "./Lib/GetNextLine/get_next_line.h"
#include <fcntl.h>

//STRUCTS

typedef struct	s_vector {
	int	x;
	int	y;
}				t_vector;

typedef struct	s_window {
	void		*win;
	t_vector	size;
}				t_window;

typedef struct	s_program {
	void		*mlx;
	t_window	window;
}				t_program;

typedef struct 	s_image {
	void 		*image;
	t_vector 	size;
}				t_image;

typedef struct s_matrix {
	char 		**mat;
	char		*line;
	int			fd;
	int			i;
	int			x;
	int 		y;
}				t_matrix;

//FUNCTIONS

void ft_arguments(int ac);
int ft_check_map_format(char *map);
void mlx_start(char *str);
void ft_window (char *str, void *mlx);
int ft_check_map_error(char *path);
char **ft_matrix(char *path, int *lines);
#endif
