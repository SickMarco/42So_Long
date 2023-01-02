/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:40:41 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/02 19:15:34 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_num(t_program *p)
{
	mlx_destroy_image(p->mlx, p->num.zero);
	mlx_destroy_image(p->mlx, p->num.one);
	mlx_destroy_image(p->mlx, p->num.two);
	mlx_destroy_image(p->mlx, p->num.three);
	mlx_destroy_image(p->mlx, p->num.four);
	mlx_destroy_image(p->mlx, p->num.five);
	mlx_destroy_image(p->mlx, p->num.six);
	mlx_destroy_image(p->mlx, p->num.seven);
	mlx_destroy_image(p->mlx, p->num.eight);
	mlx_destroy_image(p->mlx, p->num.nine);
}

void	ft_number_sprite(t_program *p)
{
	int	x;
	int	y;

	x = 7;
	y = 10;
	p->num.zero = mlx_xpm_file_to_image(p->mlx, "./Textures/Num/0.xpm",
			&x, &y);
	p->num.one = mlx_xpm_file_to_image(p->mlx, "./Textures/Num/1.xpm",
			&x, &y);
	p->num.two = mlx_xpm_file_to_image(p->mlx, "./Textures/Num/2.xpm",
			&x, &y);
	p->num.three = mlx_xpm_file_to_image(p->mlx, "./Textures/Num/3.xpm",
			&x, &y);
	p->num.four = mlx_xpm_file_to_image(p->mlx, "./Textures/Num/4.xpm",
			&x, &y);
	p->num.five = mlx_xpm_file_to_image(p->mlx, "./Textures/Num/5.xpm",
			&x, &y);
	p->num.six = mlx_xpm_file_to_image(p->mlx, "./Textures/Num/6.xpm",
			&x, &y);
	p->num.seven = mlx_xpm_file_to_image(p->mlx, "./Textures/Num/7.xpm",
			&x, &y);
	p->num.eight = mlx_xpm_file_to_image(p->mlx, "./Textures/Num/8.xpm",
			&x, &y);
	p->num.nine = mlx_xpm_file_to_image(p->mlx, "./Textures/Num/9.xpm",
			&x, &y);
}

void	ft_put_num(t_program *p, int count, float x)
{
	int	len;

	len = ft_strlen (p->matrix.mat[0]) + 1;
	if (count == 0)
		mlx_put_image_to_window(p->mlx, p->window.win, p->num.zero,
			len * x, 20);
	else if (count == 1)
		mlx_put_image_to_window(p->mlx, p->window.win, p->num.one, len * x, 20);
	else if (count == 2)
		mlx_put_image_to_window(p->mlx, p->window.win, p->num.two, len * x, 20);
	else if (count == 3)
		mlx_put_image_to_window(p->mlx, p->window.win, p->num.three,
			len * x, 20);
	else if (count == 4)
		mlx_put_image_to_window(p->mlx, p->window.win, p->num.four,
			len * x, 20);
	else if (count == 5)
		mlx_put_image_to_window(p->mlx, p->window.win, p->num.five,
			len * x, 20);
	else if (count == 6)
		mlx_put_image_to_window(p->mlx, p->window.win, p->num.six, len * x, 20);
	else if (count == 7)
		mlx_put_image_to_window(p->mlx, p->window.win, p->num.seven,
			len * x, 20);
	else if (count == 8)
		mlx_put_image_to_window(p->mlx, p->window.win, p->num.eight, len * x, 20);
	else if (count == 9)
		mlx_put_image_to_window(p->mlx, p->window.win, p->num.nine, len * x, 20);
}

void	ft_count_move(t_program *p)
{
	static int count = 0;

	count++;
	float	x;
	if (count <= 9)
	{
		x = 45;
		ft_put_num(p, count, x);
	}
	else if (count <= 99)
	{
		x = 44.5;
		ft_put_num(p, count % 10, 45);
		ft_put_num(p, count / 10, x);
	}
	else if (count <= 999)
	{
		x = 44;
		ft_put_num(p, count % 10, 45);
		ft_put_num(p, count / 10 % 10, 44.5);
		ft_put_num(p, count / 100, x);
	}
}
