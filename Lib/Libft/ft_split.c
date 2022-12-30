/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:27:49 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/29 17:21:31 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_words_alloc(const char *s, int start, int end)
{
	static char	*str;
	int		i;

	i = 0;
	str = ft_calloc(sizeof(char), 1);
	if (!str)
		return (NULL);
	while (end > start)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

int	ft_words_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			++count;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		words;
	int		start;
	int		end;

	i = 0;
	start = 0;
	end = 0;
	words = ft_words_count(s, c);
	str = ft_calloc(sizeof(char *) * (words + 1), 1);
	if (!str)
		return (NULL);
	while (words != 0)
	{
		start += (s[start] == c);
		if ((s[end] != c && s[end + 1] == c) || s[end + 1] == '\0')
		{
			str[i++] = ft_words_alloc(s, start, ++end);
			words--;
			start = end;
		}
		end++;
	}
	return (str);
}
