/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 16:45:13 by dsusheno          #+#    #+#             */
/*   Updated: 2016/06/11 18:03:13 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lib.h"

void	line_end(t_gener *s_gen)
{
	int	i;

	i = 0;
	while (s_gen->cmd_line[i] != '\0' && s_gen->cmd_line[i] != ';')
		i++;
	i--;
	while (s_gen->cmd_line[i] == ' ')
	{
		s_gen->cmd_line[i] = '\0';
		i--;
	}
}

void	arg_to_wordtab2(t_gener *s_gen, t_var *s_v)
{
	while (s_gen->cmd_line[s_v->i] == ' ')
		s_v->i++;
	s_v->save = s_v->i;
	while (s_gen->cmd_line[s_v->i] != ' ' && s_gen->cmd_line[s_v->i]
			&& s_gen->cmd_line[s_v->i] != ';')
	{
		s_v->count++;
		s_v->i++;
	}
	s_gen->arg[s_v->num] = malloc(sizeof(char) * (s_v->count + 1));
	s_gen->arg[s_v->num][s_v->count] = '\0';
	while (s_v->k < s_v->count)
	{
		s_gen->arg[s_v->num][s_v->k] = s_gen->cmd_line[s_v->save];
		s_v->k++;
		s_v->save++;
	}
}

void	arg_to_wordtab(t_gener *s_gen)
{
	t_var	s_v;

	s_v.num = 0;
	s_v.i = 0;
	s_v.k = 0;
	s_v.count = 0;
	while (s_gen->cmd_line[s_v.i] != '\0' && s_gen->cmd_line[s_v.i] != ';')
	{
		arg_to_wordtab2(s_gen, &s_v);
		s_v.num++;
		s_v.count = 0;
		s_v.k = 0;
	}
}

void	str_to_wordtab(t_gener *s_gen)
{
	int		i;
	int		space;
	int		nb_arg;

	i = 0;
	space = 0;
	nb_arg = 1;
	while (s_gen->cmd_line[i] == ' ')
		i++;
	while (s_gen->cmd_line[i] != '\0' && s_gen->cmd_line[i] != ';')
	{
		if (s_gen->cmd_line[i] == ' ')
		{
			while (s_gen->cmd_line[i] == ' ')
				i++;
			space++;
		}
		i++;
	}
	s_gen->arg = (char **)malloc(sizeof(char *) * (space + 2));
	s_gen->arg[space + 1] = NULL;
	arg_to_wordtab(s_gen);
}
