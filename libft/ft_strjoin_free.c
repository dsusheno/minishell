/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 14:03:20 by dsusheno          #+#    #+#             */
/*   Updated: 2016/01/24 14:24:43 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int i)
{
	char	*join;

	join = ft_strjoin(s1, s2);
	if (!join)
		return (NULL);
	if (i == 1 || i == 3)
	{
		free(s1);
		s1 = NULL;
	}
	if (i == 2 || i == 3)
	{
		free(s2);
		s2 = NULL;
	}
	return (join);
}
