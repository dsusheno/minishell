/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 13:37:17 by dsusheno          #+#    #+#             */
/*   Updated: 2016/09/06 18:33:26 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lib.h"

void	ft_echo_1(t_gener *s_gen, char *line, int *i, int *quote)
{
	int c;

	c = 0;
	if (line[*i] == ' ' && *quote == 0)
	{
		while (line[*i] && line[*i] == ' ')
			*i = *i + 1;
		ft_putchar(' ');
	}
	if (line[*i] == '$')
	{
		*i = *i + 1;
		ft_param_of_env(s_gen, i, line, c);
		if (!line[*i])
		{
			ft_putchar('\n');
			return ;
		}
	}
	if (line[*i] != '\"' && line[*i] != '\\' && line[*i] != '$')
		ft_putchar(line[*i]);
}

void	ft_echo_2(char *line, int *i, int *quote)
{
	if (line[*i] == '\\')
	{
		if (*quote == 1)
			ft_putchar('\\');
		else
		{
			ft_putchar(line[*i + 1]);
			*i = *i + 1;
		}
	}
	if (line[*i] == '\"' && *quote == 0)
		*quote = 1;
	else if (line[*i] == '\"' && *quote == 1)
		*quote = 0;
	*i = *i + 1;
}

void	ft_echo(t_gener *s_gen, char *line)
{
	int i;
	int	quote;
	int	backslash;

	i = 4;
	quote = 0;
	backslash = 0;
	if (!ft_quotes(line))
		return ;
	if (line[i])
		while (line[i] != '\0' && line[i] == ' ')
			i++;
	if (ft_backslash_verif(s_gen, line))
	{
		while (line[i] != '\0')
		{
			ft_echo_1(s_gen, line, &i, &quote);
			ft_echo_2(line, &i, &quote);
		}
		ft_putchar('\n');
	}
}

int		echo(t_gener *s_gen)
{
	if (!ft_strncmp(s_gen->arg[0], "echo", 4))
	{
		if (!s_gen->arg[0][4])
		{
			ft_echo(s_gen, s_gen->cmd_line);
			return (1);
		}
		else
			return (0);
	}
	return (0);
}
