/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:09:32 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/31 17:29:47 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../minilibx-linux/mlx.h"
#include "./Lib/Libft/libft.h"
#include "./Lib/Printf/ft_printf.h"
#include "./Lib/GetNextLine/get_next_line.h"
#include <fcntl.h>

#ifndef SIZE
#define SIZE 50
#endif

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
}				t_image;

typedef struct s_matrix {
	char 		**mat;
	char		*line;
	int			fd;
	int			x;
	int 		y;
}				t_matrix;

typedef struct 	s_player {
	void		*img;
	t_vector 	position;
}				t_player;

typedef struct 	s_sprite {
	void		*floor;
	void		*wall;
	void		*collect;
	void		*exit;
}				t_sprite;

typedef struct	s_program {
	void		*mlx;
	t_window	window;
	t_player	player;
	t_image		img;
	t_sprite	sprite;
	t_matrix	matrix;
}				t_program;

int 		ft_check_map_format(char *map);
int 		ft_check_map_error(t_program *p);
void 		mlx_start(t_program *game);
void 		ft_window(t_program *p);
char 		**ft_matrix(char *path);
void		ft_map(t_program *p);
int 		ft_matrix_lines(t_program *p);
int			ft_key (int key, void *param);
void 		ft_destroyer(t_program *p);

#endif
