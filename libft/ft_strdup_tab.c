/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 19:22:10 by dsusheno          #+#    #+#             */
/*   Updated: 2016/05/20 19:31:33 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strdup_tab(char **s1)
{
	char	**copy;
	int		line;

	line = 0;
	while (s1[line] != NULL)
		line++;
	copy = (char**)malloc(sizeof(char *) * (line + 1));
	copy[line] = NULL;
	line = 0;
	while (s1[line] != NULL)
	{
		copy[line] = ft_strdup(s1[line]);
		line++;
	}
	return (copy);
}
