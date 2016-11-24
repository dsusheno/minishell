/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 20:01:48 by dsusheno          #+#    #+#             */
/*   Updated: 2015/12/04 17:14:34 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int i;
	int j;
	int c;
	int n2;

	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (s1[i] && n)
	{
		j = i;
		c = 0;
		n2 = n;
		while (s1[j] == s2[c] && n2)
		{
			j++;
			c++;
			n2--;
			if (s2[c] == '\0')
				return ((char *)&s1[i]);
		}
		i++;
		n--;
	}
	return (NULL);
}
