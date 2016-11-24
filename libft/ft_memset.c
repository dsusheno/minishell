/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:15:27 by dsusheno          #+#    #+#             */
/*   Updated: 2015/11/27 18:43:27 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			counter;
	unsigned char	*str;

	counter = 0;
	str = (unsigned char *)b;
	while (counter < len)
	{
		str[counter] = (char)c;
		counter++;
	}
	return (b);
}
