/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:44:37 by dsusheno          #+#    #+#             */
/*   Updated: 2015/11/28 19:07:23 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*buffer;

	buffer = (char*)malloc(sizeof(*buffer) * len);
	ft_memcpy(buffer, src, len);
	ft_memcpy(dst, buffer, len);
	free(buffer);
	return (dst);
}
