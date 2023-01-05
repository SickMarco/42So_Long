/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:50:44 by mbozzi            #+#    #+#             */
/*   Updated: 2023/01/05 16:03:20 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_anim(t_program *p)
{
	int	counter;

	counter = 0;
	while (counter <= 11)
	{
		mlx_destroy_image(p->mlx, p->anim[counter]);
		counter++;
	}
}

void	ft_ghost_sprite(t_program *p, int x, int y)
{
	p->anim = ft_calloc(sizeof(void *), 12);
	p->anim[0] = mlx_xpm_file_to_image(p->mlx, "./Textures/Ghost/0.xpm",
			&x, &y);
	p->anim[1] = mlx_xpm_file_to_image(p->mlx, "./Textures/Ghost/1.xpm",
			&x, &y);
	p->anim[2] = mlx_xpm_file_to_image(p->mlx, "./Textures/Ghost/2.xpm",
			&x, &y);
	p->anim[3] = mlx_xpm_file_to_image(p->mlx, "./Textures/Ghost/3.xpm",
			&x, &y);
	p->anim[4] = mlx_xpm_file_to_image(p->mlx, "./Textures/Ghost/4.xpm",
			&x, &y);
	p->anim[5] = mlx_xpm_file_to_image(p->mlx, "./Textures/Ghost/5.xpm",
			&x, &y);
	p->anim[6] = mlx_xpm_file_to_image(p->mlx, "./Textures/Ghost/6.xpm",
			&x, &y);
	p->anim[7] = mlx_xpm_file_to_image(p->mlx, "./Textures/Ghost/7.xpm",
			&x, &y);
	p->anim[8] = mlx_xpm_file_to_image(p->mlx, "./Textures/Ghost/8.xpm",
			&x, &y);
	p->anim[9] = mlx_xpm_file_to_image(p->mlx, "./Textures/Ghost/9.xpm",
			&x, &y);
	p->anim[10] = mlx_xpm_file_to_image(p->mlx, "./Textures/Ghost/10.xpm",
			&x, &y);
	p->anim[11] = mlx_xpm_file_to_image(p->mlx, "./Textures/Ghost/11.xpm",
			&x, &y);
}

int	ft_animation(t_program *p)
{
	static int	counter = 0;

	if (counter == 11)
		counter = 0;
	mlx_put_image_to_window(p->mlx, p->win.win, p->anim[counter],
		p->player.pos.y * SIZE,
		p->player.pos.x * SIZE);
	counter++;
	usleep(30000);
	return (0);
}
