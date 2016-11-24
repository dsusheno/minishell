/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:14:47 by dsusheno          #+#    #+#             */
/*   Updated: 2015/12/04 17:09:25 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s2;
	unsigned int	count;

	count = 0;
	if (s && f)
	{
		s2 = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (s2)
		{
			while (s[count] != '\0')
			{
				s2[count] = f(count, s[count]);
				count++;
			}
			s2[count] = '\0';
			return ((char *)s2);
		}
	}
	return (NULL);
}
