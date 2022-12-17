/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:09:32 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/17 18:01:36 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../minilibx-linux/mlx.h"
#include "./Lib/Libft/libft.h"
#include "./Lib/Printf/ft_printf.h"
#include "./Lib/GetNextLine/get_next_line.h"

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

//FUNCTIONS

void ft_arguments(int ac);
int ft_check_map_format(char *map);
void mlx_start();

#endif
