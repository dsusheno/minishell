/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:24:56 by dsusheno          #+#    #+#             */
/*   Updated: 2015/12/01 17:25:33 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s2;
	size_t	length;
	size_t	count;

	if (s && f)
	{
		count = 0;
		length = ft_strlen(s);
		s2 = (char*)malloc(sizeof(char) * (length + 1));
		if (s2)
		{
			while (s[count] != '\0')
			{
				s2[count] = f(s[count]);
				count++;
			}
			s2[count] = '\0';
			return ((char *)s2);
		}
	}
	return (NULL);
}
