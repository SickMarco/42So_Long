/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:10:28 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/30 18:45:25 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key (int key, void *param)
{
	t_program *game = (t_program *)param;
	
	if (key == 100)
	{
		game->player.position.y++;
		//mlx_put_image_to_window(game->mlx, game->window.win, game->player.img, game->player.position.y * 50, game->player.position.x * 50);
		//mlx_destroy_image(game->mlx, game->sprite.floor);
	}
	else if (key == 97)
		game->player.position.y--;
	else if (key == 119)
		game->player.position.x++;
	else if (key == 115)
		game->player.position.x--;
	ft_printf ("Key pressed: %d\n", key);
	ft_printf ("%d, %d", game->player.position.y, game->player.position.x);
	//mlx_put_image_to_window(game->mlx, game->window.win, game->player.img, game->player.position.y * 50, game->player.position.x * 50);
	return (0);
}