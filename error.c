/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:48:13 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/17 17:48:17 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_arguments(int ac)
{
	if (ac < 2)
		ft_printf ("\033[0;31mInsert map\n");
	else if (ac > 2)
		ft_printf ("\033[0;31mToo many arguments\n");
}

int ft_check_map_format(char *map)
{
	int i;
	char ber[4] = {'b','e','r','\0'};

	i = 0;
	while (map[i - 1] != '.')
		i++;
	if (ft_strncmp(&map[i],&ber[0], 4) != 0)
		return (1);
	return (0);
}