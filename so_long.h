/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:09:32 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/06 17:26:09 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "./Lib/Libft/libft.h"
# include "./Lib/Printf/ft_printf.h"
# include "./Lib/GetNextLine/get_next_line.h"
# include <fcntl.h>
# include <time.h>

# ifndef SIZE
#  define SIZE 50
# endif

typedef struct s_vector {
	int			x;
	int			y;
}				t_vector;

typedef struct s_window {
	void		*win;
	t_vector	size;
}				t_window;

typedef struct s_matrix {
	char		**mat;
	char		*line;
	int			lines;
	int			fd;
	int			x;
	int			y;
}				t_matrix;

typedef struct s_player {
	void		*img;
	t_vector	pos;
}				t_player;

typedef struct s_exit {
	t_vector	pos;
	void		*open;
	int			win;
}				t_exit;

typedef struct s_sprite {
	void		*floor;
	void		*wall;
	void		*collect;
	void		*exit;
}				t_sprite;

typedef struct s_num {
	void		*zero;
	void		*one;
	void		*two;
	void		*three;
	void		*four;
	void		*five;
	void		*six;
	void		*seven;
	void		*eight;
	void		*nine;
	int			pos_x;
}				t_num;

typedef struct s_enemy {
	void		*img;
	t_vector	pos;
	int			count;
	int			random;
	int			wait;
}				t_enemy;

typedef struct s_program {
	void		*mlx;
	t_window	win;
	t_player	player;
	t_exit		exit;
	t_sprite	sprite;
	t_matrix	matrix;
	int			collect;
	t_num		num;
	t_enemy		enemy;
	void		**anim;
	int			end;
}				t_program;

int		ft_check_map_format(char *map);
int		ft_check_map_error(t_program *p);
void	game_start(t_program *game);
void	ft_matrix(char *path, t_program *p);
void	ft_map(t_program *p);
int		ft_key(int key, void *param);
void	ft_destroyer(t_program *p);
int		mlx_close(t_program *p);
void	ft_win(t_program *p, int count);
void	ft_number_sprite(t_program *p);
void	ft_count_move(t_program *p);
void	ft_destroy_num(t_program *p);
int		enemy_move(void *param);
void	ft_ghost_sprite(t_program *p, int x, int y);
int		ft_animation(t_program *p);
void	ft_destroy_anim(t_program *p);
void	ft_lose(t_program *p);

#endif
