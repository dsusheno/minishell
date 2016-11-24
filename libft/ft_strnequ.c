/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:55:53 by dsusheno          #+#    #+#             */
/*   Updated: 2015/12/04 17:10:21 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	if (s1 && s2 && n)
	{
		while (n > 0)
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
			n--;
		}
		return (1);
	}
	return (0);
}
