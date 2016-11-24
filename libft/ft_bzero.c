/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:53:02 by dsusheno          #+#    #+#             */
/*   Updated: 2015/12/01 13:49:24 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			number;
	unsigned char	*str;

	number = 0;
	str = (unsigned char *)s;
	while (number < n)
	{
		str[number] = 0;
		number++;
	}
}
