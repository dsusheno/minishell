/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:44:14 by dsusheno          #+#    #+#             */
/*   Updated: 2015/12/08 10:51:46 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*copy;

	copy = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (copy)
		ft_strncpy(copy, s1, n);
	if (!copy)
		return (NULL);
	return (copy);
}
