/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 18:52:33 by dsusheno          #+#    #+#             */
/*   Updated: 2015/12/04 17:18:18 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;
	int c;

	i = 0;
	c = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (s1[i])
	{
		j = i;
		c = 0;
		while (s1[j] == s2[c])
		{
			j++;
			c++;
			if (s2[c] == '\0')
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
