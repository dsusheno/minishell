/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 11:28:18 by dsusheno          #+#    #+#             */
/*   Updated: 2015/12/07 13:26:50 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nb_num(int n)
{
	size_t	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n / 10)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static int		ft_nb(char *nb, int n, int i)
{
	if (n < 0)
	{
		nb[i] = ('-');
		n = -n;
		i++;
	}
	if (n >= 10)
	{
		i = ft_nb(nb, n / 10, i);
		i = ft_nb(nb, n % 10, i);
	}
	else
	{
		nb[i] = n + '0';
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*nb;
	int		i;
	char	*min;

	i = 0;
	nb = (char *)malloc(sizeof(char) * (ft_nb_num(n) + 1));
	if (n == -2147483648)
	{
		min = "-2147483648";
		ft_strcpy(nb, min);
		nb[12] = '\0';
		return (nb);
	}
	if (!nb)
		return (NULL);
	ft_nb(nb, n, i);
	nb[ft_nb_num(n)] = '\0';
	return (nb);
}
