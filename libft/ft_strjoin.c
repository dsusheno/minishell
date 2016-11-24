/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:15:04 by dsusheno          #+#    #+#             */
/*   Updated: 2015/12/04 19:09:23 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	size_t	length;
	size_t	lengths1;
	char	*join;

	i = 0;
	length = ft_strlen(s1) + ft_strlen(s2);
	lengths1 = ft_strlen(s1);
	join = (char *)malloc(sizeof(char) * (length + 1));
	if (join)
	{
		ft_strcpy(join, s1);
		while (s2[i] != '\0')
		{
			ft_strcpy(&join[lengths1 + i], &s2[i]);
			i++;
		}
		return (join);
	}
	return (NULL);
}
