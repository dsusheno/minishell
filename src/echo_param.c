/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 18:30:22 by dsusheno          #+#    #+#             */
/*   Updated: 2016/09/06 18:34:39 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lib.h"

int		ft_quotes(char *line)
{
	int i;
	int nb_quote;

	i = 0;
	nb_quote = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\"')
		{
			if (line[i - 1] == '\\' && nb_quote % 2)
				nb_quote++;
			else if (line[i - 1] != '\\')
				nb_quote++;
		}
		i++;
	}
	if (nb_quote % 2)
	{
		ft_putstrn("Unmatched \".");
		return (0);
	}
	return (1);
}

void	ft_param_of_env(t_gener *s_gen, int *i, char *line, int c)
{
	int dif;
	int t;
	int sym;

	t = 0;
	c = *i;
	dif = 0;
	sym = 0;
	while (line[c] != ' ' && line[c] != '\0')
		c++;
	dif = c - *i;
	while (s_gen->tab_env[t])
	{
		if (!ft_strncmp(&line[*i], s_gen->tab_env[t], dif))
		{
			while (s_gen->tab_env[t][sym] != '=')
				sym++;
			sym++;
			ft_putstr(&s_gen->tab_env[t][sym]);
			*i = c;
			return ;
		}
		t++;
	}
	*i = c;
}

int		ft_backslash_verif(t_gener *s_gen, char *line)
{
	int i;
	int backslash;

	i = 0;
	backslash = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '\\')
			backslash = 0;
		else
			backslash++;
		i++;
	}
	if (backslash % 2 && line[i - 1] == '\\')
	{
		ft_putstr("? ");
		ft_match_echo(s_gen, line);
		return (0);
	}
	return (1);
}

void	ft_match_echo(t_gener *s_gen, char *line1)
{
	char	*line2;
	char	*line3;
	int		i;

	i = 0;
	get_next_line(0, &line2);
	if (*line2)
	{
		line3 = ft_strjoin(line1, line2);
		ft_echo(s_gen, line3);
		free(line3);
	}
	else
	{
		while (line1[i] != '\0')
			i++;
		line1[i - 1] = '\0';
		ft_echo(s_gen, line1);
	}
	free(line2);
}
