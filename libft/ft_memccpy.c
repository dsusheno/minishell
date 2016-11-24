/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:47:50 by dsusheno          #+#    #+#             */
/*   Updated: 2015/12/04 18:55:07 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			count;
	unsigned char	*origin;
	unsigned char	*copy;

	origin = (unsigned char*)src;
	copy = (unsigned char*)dst;
	count = 0;
	while (count < n)
	{
		copy[count] = origin[count];
		if (origin[count] == (unsigned char)c)
			return (&copy[count + 1]);
		count++;
	}
	return (NULL);
}
