/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:09:32 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/29 18:39:28 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../minilibx-linux/mlx.h"
#include "./Lib/Libft/libft.h"
#include "./Lib/Printf/ft_printf.h"
#include "./Lib/GetNextLine/get_next_line.h"
#include <fcntl.h>

typedef struct	s_vector {
	int	x;
	int	y;
}				t_vector;

typedef struct	s_window {
	void		*win;
	t_vector	size;
}				t_window;

typedef struct 	s_image {
	void 		*image;
	t_vector 	size;
	t_vector 	position;
}				t_image;

typedef struct s_matrix {
	char 		**mat;
	char		*line;
	int			fd;
	int			x;
	int 		y;
}				t_matrix;

typedef struct	s_program {
	void		*mlx;
	t_window	window;
	t_image		sprite;
}				t_program;

int 		ft_check_map_format(char *map);
void 		mlx_start(char *str, char **matrix);
void 		*ft_window (char *str, void *mlx);
int 		ft_check_map_error(char *path, char **matrix);
char 		**ft_matrix(char *path);
void		ft_map(void *mlx, void *win, char *map, char **mat);
int 		ft_matrix_lines(char *path);
void 		ft_putmap (void *mlx, void *win, int x, int y, char c);
int			ft_key (int key);

#endif
