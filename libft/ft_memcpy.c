/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:56:57 by dsusheno          #+#    #+#             */
/*   Updated: 2015/11/27 18:39:04 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			count;
	unsigned char	*origin;
	unsigned char	*copy;

	count = 0;
	origin = (unsigned char *)src;
	copy = (unsigned char *)dst;
	while (count < n)
	{
		copy[count] = origin[count];
		count++;
	}
	return (dst);
}
