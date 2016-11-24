/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 21:31:20 by dsusheno          #+#    #+#             */
/*   Updated: 2015/12/07 13:24:12 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;

	copy = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (copy)
		ft_strcpy(copy, s1);
	if (!copy)
		return (NULL);
	return (copy);
}
