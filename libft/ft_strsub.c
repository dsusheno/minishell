/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:01:33 by dsusheno          #+#    #+#             */
/*   Updated: 2015/12/01 18:14:19 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(sizeof(char) * len + 1);
	if (copy)
	{
		while (len--)
		{
			copy[i] = s[start + i];
			i++;
		}
		copy[i] = '\0';
		return ((char *)copy);
	}
	return (NULL);
}
