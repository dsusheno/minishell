/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 13:50:21 by dsusheno          #+#    #+#             */
/*   Updated: 2016/07/06 14:11:21 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lib.h"

int		prog_verif(t_gener *s_gen)
{
	int			acs;

	acs = 0;
	if (s_gen->cmd)
		free(s_gen->cmd);
	s_gen->cmd = NULL;
	if (!ft_strncmp(s_gen->arg[0], "/", 1) ||
			!ft_strncmp(s_gen->arg[0], "..", 2) ||
			!ft_strncmp(s_gen->arg[0], ".", 1))
	{
		s_gen->cmd = ft_strdup(s_gen->arg[0]);
		acs = access(s_gen->cmd, F_OK);
		if (acs == -1)
		{
			ft_putstr("minishell: no such file or directory: ");
			ft_putstrn(s_gen->cmd);
		}
		else
			if_non_reg(s_gen);
		return (1);
	}
	return (0);
}

void	path_verif_center(t_gener *s_gen, t_var *s_var)
{
	while (s_var->copy[s_var->i] != '\0')
	{
		while (s_var->copy[s_var->i] != ':' && s_var->copy[s_var->i] != '\0')
			s_var->i++;
		if (s_var->copy[s_var->i] == ':')
		{
			s_var->point = &s_var->copy[s_var->i + 1];
			s_var->copy[s_var->i] = '\0';
			s_gen->cmd = ft_strjoin_char(s_var->copy, s_gen->arg[0], '/');
			s_var->acs = access(s_gen->cmd, F_OK);
			if (s_var->acs == 0)
				break ;
			free(s_gen->cmd);
			s_gen->cmd = NULL;
			s_var->i = 0;
			s_var->copy = s_var->point;
		}
		else
		{
			s_gen->cmd = ft_strjoin_char(s_var->copy, s_gen->arg[0], '/');
			s_var->acs = access(s_gen->cmd, F_OK);
		}
	}
}

void	path_verif(t_gener *s_gen)
{
	t_var	s_var;

	s_var.i = 0;
	s_var.point = s_gen->path;
	s_var.copy = s_gen->path;
	s_var.acs = -1;
	path_verif_center(s_gen, &s_var);
	if (s_var.acs == -1)
	{
		ft_putstr("minishell: command not found: ");
		ft_putstrn(s_gen->arg[0]);
	}
}

void	path_verif_for_env(t_gener *s_gen)
{
	t_var	s_var;

	s_var.i = 0;
	s_var.point = s_gen->path;
	s_var.copy = s_gen->path;
	s_var.acs = -1;
	path_verif_center(s_gen, &s_var);
}

char	*my_getenv(char *elem, t_gener *s_gen)
{
	t_env	*l_copy;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(elem);
	l_copy = s_gen->l_env;
	while (l_copy != NULL && ft_strncmp(l_copy->path, elem, size))
		l_copy = l_copy->next;
	if (l_copy == NULL)
		return (NULL);
	while (l_copy->path[i] != '=')
		i++;
	i++;
	s_gen->copy = ft_strdup(&l_copy->path[i]);
	return (s_gen->copy);
}
