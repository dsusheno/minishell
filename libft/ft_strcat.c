/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:17:29 by dsusheno          #+#    #+#             */
/*   Updated: 2015/11/29 17:41:21 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	size_t	length;

	i = 0;
	length = ft_strlen(s1);
	while (s2[i] != '\0')
	{
		ft_strcpy(&s1[length + i], &s2[i]);
		i++;
	}
	return (s1);
}
