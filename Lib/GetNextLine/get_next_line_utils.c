/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:39:01 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/29 16:43:39 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen2(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*str;
	int		len;
	int		i;
	int		x;

	i = 0;
	x = 0;
	len = ft_strlen2(s1) + ft_strlen2(s2);
	str = ft_calloc2(sizeof(char), len + 1);
	if (!str || !s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[x])
		str[i++] = s2[x++];
	str[i] = '\0';
	free (s1);
	return (str);
}

void	ft_bzero2(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc2(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero2(ptr, nmemb * size);
	return (ptr);
}

int	ft_check_eol(char *buff)
{
	int	x;

	x = 0;
	while (buff[x])
	{
		if (buff[x] == '\n')
			return (1);
		x++;
	}
	return (0);
}
