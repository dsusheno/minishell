/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:11:36 by dsusheno          #+#    #+#             */
/*   Updated: 2015/12/04 17:01:41 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_len_word(const char *str, int start, char c_end)
{
	size_t			counter;

	if (!str)
		return (0);
	counter = 0;
	while (str[start] && str[start] != c_end)
	{
		start++;
		counter++;
	}
	return (counter);
}

static int			ft_words(char *str, char c)
{
	int				count_word;
	int				j;
	int				is_word;

	j = 0;
	count_word = 0;
	is_word = 1;
	while (str[j])
	{
		if (str[j] != c && is_word == 1)
		{
			is_word = 0;
			count_word++;
		}
		if (str[j] == c && is_word == 0)
			is_word = 1;
		j++;
	}
	return (count_word);
}

char				**ft_strsplit(char const *s, char c)
{
	int				count_word;
	int				i;
	unsigned int	j;
	char			**array;
	char			*str;

	str = (char *)s;
	j = 0;
	i = 0;
	count_word = ft_words(str, c);
	array = (char**)ft_memalloc(sizeof(char*) * (count_word + 1));
	if (!array)
		return (NULL);
	while (str[j] && i < count_word)
	{
		while (str[j] == c)
			j++;
		array[i] = ft_strsub(str, j, ft_len_word(str, j, c));
		while (str[j] && str[j] != c)
			j++;
		i++;
	}
	array[i] = NULL;
	return (array);
}
