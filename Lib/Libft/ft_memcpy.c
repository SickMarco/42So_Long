/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:06:26 by mbozzi            #+#    #+#             */
/*   Updated: 2022/10/17 15:06:30 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dtmp;
	char	*stmp;

	i = 0 ;
	dtmp = (char *) dest;
	stmp = (char *) src;
	while (i < n)
	{
		dtmp[i] = stmp[i];
		i++;
	}
	return (dest);
}
