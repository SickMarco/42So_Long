/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:06:38 by mbozzi            #+#    #+#             */
/*   Updated: 2022/10/17 15:06:41 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*tmpd;
	char	*tmps;

	i = 0;
	tmpd = (char *)dest;
	tmps = (char *)src;
	if (tmpd > tmps)
	{
		while (n > 0)
		{
			n--;
			tmpd[n] = tmps[n];
		}
	}
	else
	{
		while (i < n)
		{
			tmpd[i] = tmps[i];
			i++;
		}
	}
	return (dest);
}
