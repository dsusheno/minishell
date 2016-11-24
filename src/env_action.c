/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 17:01:02 by dsusheno          #+#    #+#             */
/*   Updated: 2016/06/11 17:48:33 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lib.h"

void	ft_unsetenv(t_gener *s_gen, char *elem)
{
	t_env	*l_env;
	t_env	*prew;
	int		size;
	int		i;

	size = ft_strlen(elem);
	l_env = s_gen->l_env;
	prew = NULL;
	i = 1;
	while (l_env && ft_strncmp(l_env->path, elem, size))
	{
		prew = l_env;
		l_env = l_env->next;
		i++;
	}
	if (l_env)
	{
		if (prew != NULL)
			prew->next = l_env->next;
		free(l_env->path);
		l_env->path = NULL;
		free(l_env);
		if (i == 1)
			s_gen->l_env = s_gen->l_env->next;
	}
}

void	ft_set_action(t_gener *s_gen, t_env *l_env)
{
	if (s_gen->arg[2])
		l_env->path = ft_strjoin_char(s_gen->arg[1], s_gen->arg[2], '=');
	else
		l_env->path = ft_strjoin(s_gen->arg[1], "=");
}

void	ft_set_center(t_gener *s_gen, t_env *l_env, t_env *prew)
{
	if (l_env)
	{
		free(l_env->path);
		ft_set_action(s_gen, l_env);
	}
	else
	{
		if (prew)
		{
			prew->next = malloc(sizeof(t_env));
			l_env = prew->next;
		}
		else
		{
			s_gen->l_env = malloc(sizeof(t_env));
			l_env = s_gen->l_env;
		}
		ft_set_action(s_gen, l_env);
		l_env->next = NULL;
	}
}

void	ft_set(t_gener *s_gen)
{
	t_env	*l_env;
	t_env	*prew;
	int		size;

	l_env = s_gen->l_env;
	prew = NULL;
	size = ft_strlen(s_gen->arg[1]);
	while (l_env && ft_strncmp(l_env->path, s_gen->arg[1], size))
	{
		prew = l_env;
		l_env = l_env->next;
	}
	ft_set_center(s_gen, l_env, prew);
}

int		ft_setenv(t_gener *s_gen)
{
	if (!ft_strncmp(s_gen->arg[0], "setenv", 6) && !s_gen->arg[0][6])
	{
		if (s_gen->arg[1] && s_gen->arg[2] && s_gen->arg[3])
		{
			ft_putstrn("setenv: Too many arguments.");
			return (1);
		}
		if (!s_gen->arg[1])
		{
			ft_env_disp(s_gen);
			return (1);
		}
		if (s_gen->arg[1])
		{
			ft_set(s_gen);
			return (1);
		}
	}
	return (0);
}
