/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:47:27 by dsusheno          #+#    #+#             */
/*   Updated: 2016/02/04 18:18:16 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_char_free(char *s1, char *s2, char sym, int i)
{
	char	*join;

	join = ft_strjoin_char(s1, s2, sym);
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
