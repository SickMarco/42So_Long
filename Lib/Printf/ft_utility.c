/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:19:11 by mbozzi            #+#    #+#             */
/*   Updated: 2022/11/08 17:18:53 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_putstrn(char *str)
{
	int		i;
	char	*tmp;
	int		len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	len = ft_strlen(str);
	tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp [i] = '\0';
	i = 0;
	while (tmp[i])
		write(1, &tmp[i++], 1);
	free(tmp);
	return (i);
}

int	ft_putnbrn(int num)
{
	char		*str;
	int			i;
	int			len;
	long int	n;

	i = 0;
	n = (long int)num;
	str = ft_itoa2(n);
	while (str[i])
		write(1, &str[i++], 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int		i;
	int		conv[100];
	int		ret;

	i = 0;
	ret = 0;
	if (!nbr)
		return (0);
	while (nbr >= 16)
	{
		conv[i] = base[nbr % 16];
		nbr = nbr / 16;
		i++;
	}
	conv[i] = base[nbr];
	while (i >= 0)
	{
		write(1, &conv[i], 1);
		i--;
		ret++;
	}
	return (ret);
}
