/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 16:52:18 by dsusheno          #+#    #+#             */
/*   Updated: 2016/02/03 16:56:41 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_char(char *s1, char *s2, char sym)
{
	int		i;
	size_t	length;
	size_t	lengths1;
	char	*join;

	i = 0;
	length = ft_strlen(s1) + ft_strlen(s2);
	lengths1 = ft_strlen(s1);
	join = (char *)malloc(sizeof(char) * (length + 2));
	if (join)
	{
		ft_strcpy(join, s1);
		join[lengths1] = sym;
		lengths1++;
		while (s2[i] != '\0')
		{
			ft_strcpy(&join[lengths1 + i], &s2[i]);
			i++;
		}
		return (join);
	}
	return (NULL);
}
