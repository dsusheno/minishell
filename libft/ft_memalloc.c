/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:33:41 by dsusheno          #+#    #+#             */
/*   Updated: 2015/12/01 17:27:12 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*zone;

	zone = (void *)malloc(sizeof(void) * size);
	if (!zone)
		return (NULL);
	ft_bzero(zone, size);
	return ((void *)zone);
}
