/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 19:02:10 by dsusheno          #+#    #+#             */
/*   Updated: 2015/12/04 17:18:46 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		j;
	size_t		i;
	size_t		k;

	i = 0;
	k = 0;
	j = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (s[k])
	{
		if (s[k] != '\n' && s[k] != ' '
				&& s[k] != '\t')
		{
			k++;
			j = k;
		}
		else
		{
			k++;
		}
	}
	if (j == 0)
		return (ft_strnew(0));
	return (ft_strsub(s, i, j - i));
}
