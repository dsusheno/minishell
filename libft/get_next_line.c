/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 17:58:42 by dsusheno          #+#    #+#             */
/*   Updated: 2016/01/24 14:24:36 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_end_f(char **s, char **line)
{
	*line = ft_strdup(*s);
	free(*s);
	*s = NULL;
	if (*line[0] == '\0')
	{
		free(*line);
		*line = NULL;
		return (0);
	}
	return (1);
}

static int	ft_nl_be(char **s, char **line)
{
	char	*t;
	char	*tmp;

	tmp = *s;
	t = ft_strchr(*s, '\n');
	if (t == NULL)
		return (0);
	*t = '\0';
	*line = ft_strdup(*s);
	*s = ft_strdup(t + 1);
	free(tmp);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static char	*s[99];
	char		buf[BUFF_SIZE + 1];
	int			r;

	if (fd < 0 || !line || fd > 99)
		return (-1);
	if (s[fd] && ft_nl_be(&(s[fd]), line))
		return (1);
	while ((r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] = '\0';
		s[fd] = (s[fd] ? ft_strjoin_free(s[fd], buf, 1) : ft_strdup(buf));
		if (ft_nl_be(&(s[fd]), line))
			return (1);
	}
	if (s[fd] && r >= 0)
		return (ft_end_f(&(s[fd]), line));
	return (r > 0 ? 1 : r);
}
