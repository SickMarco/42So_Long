/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:51:29 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/17 19:22:11 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void mlx_start()
{
	t_program start;

	start.mlx = mlx_init();
	start.window.win = mlx_new_window(start.mlx, 500, 500, "so_long");
	mlx_loop(start.mlx);
}