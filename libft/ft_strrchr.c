/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 18:33:45 by dsusheno          #+#    #+#             */
/*   Updated: 2015/12/04 18:33:25 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*s2;

	s2 = s + ft_strlen(s);
	while (*s2 != (char)c && s2 != s)
		s2--;
	if (*s2 == (char)c)
		return ((char*)s2);
	return (NULL);
}
