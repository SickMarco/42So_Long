/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:28:41 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/16 16:38:26 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char**av)
{
	void	*mlx_ptr;
	void	*window;

	if (ac == 2)
	{
		mlx_ptr = mlx_init();
		window = mlx_new_window(mlx_ptr, 500, 500, "so_long");
		mlx_loop(mlx_ptr);
	}
	else if (ac < 2)
		ft_printf ("Insert map\n");
	else if (ac > 2)
		ft_printf ("Too much arguments\n");
}
