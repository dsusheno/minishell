/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 19:25:34 by dsusheno          #+#    #+#             */
/*   Updated: 2015/11/27 19:39:37 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	unsigned char	*comp1;
	unsigned char	*comp2;

	comp2 = (unsigned char*)s2;
	comp1 = (unsigned char*)s1;
	count = 0;
	while (count < n)
	{
		if (comp1[count] != comp2[count])
			return (comp1[count] - comp2[count]);
		count++;
	}
	return (0);
}
