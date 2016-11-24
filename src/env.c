/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 19:01:27 by dsusheno          #+#    #+#             */
/*   Updated: 2016/06/11 17:44:16 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lib.h"

void	ft_env_disp(t_gener *s_gen)
{
	t_env	*l_env;

	l_env = s_gen->l_env;
	while (l_env != NULL)
	{
		ft_putstrn(l_env->path);
		l_env = l_env->next;
	}
}

void	ft_add_env(t_gener *s_gen, char *elem, char *value)
{
	t_env *list;

	if (!s_gen->l_env)
	{
		s_gen->l_env = malloc(sizeof(t_env));
		s_gen->l_env->path = NULL;
		s_gen->l_env->next = NULL;
	}
	list = s_gen->l_env;
	while (list->next != NULL)
		list = list->next;
	if (list->path == NULL)
		list->path = ft_strjoin_char(elem, value, '=');
	else
	{
		list->next = malloc(sizeof(t_env));
		list = list->next;
		list->path = ft_strjoin_char(elem, value, '=');
		list->next = NULL;
	}
}

int		ft_env_center(t_gener *s_gen, int i)
{
	if (!ft_strncmp(s_gen->arg[0], "env", 3) && !s_gen->arg[0][3])
	{
		if (s_gen->arg[1] == NULL || (!ft_strncmp(s_gen->arg[1], "--", 2)
			&& !s_gen->arg[1][2] && !s_gen->arg[2]))
		{
			ft_env_disp(s_gen);
			return (1);
		}
		else if ((!ft_strncmp(s_gen->arg[1], "-", 1)
			&& !s_gen->arg[1][1] && !s_gen->arg[2]))
			return (1);
	}
	else if (!ft_strncmp(s_gen->arg[0], "unsetenv", 8) && !s_gen->arg[0][8])
	{
		while (s_gen->arg[i] != NULL)
		{
			ft_unsetenv(s_gen, s_gen->arg[i]);
			i++;
		}
		return (1);
	}
	else if (ft_setenv(s_gen))
		return (1);
	return (0);
}

int		ft_env(t_gener *s_gen)
{
	int i;

	i = 1;
	return (ft_env_center(s_gen, i));
}
