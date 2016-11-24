/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 14:39:21 by dsusheno          #+#    #+#             */
/*   Updated: 2016/06/11 18:36:57 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lib.h"

void	env_to_list2(t_gener *s_gen, char **env, t_env **l_e)
{
	t_env	*l_prew;
	int		i;

	i = 0;
	l_prew = NULL;
	while (env[i] != NULL)
	{
		*l_e = malloc(sizeof(t_env));
		if (i > 0)
			l_prew->next = *l_e;
		if (i == 0)
		{
			l_prew = *l_e;
			s_gen->l_env = *l_e;
		}
		(*l_e)->path = ft_strdup(env[i]);
		l_prew = *l_e;
		i++;
	}
}

void	env_to_list(t_gener *s_gen, char **env)
{
	t_env	*l_e;
	char	*pwd;

	l_e = NULL;
	pwd = NULL;
	if (*env)
		env_to_list2(s_gen, env, &l_e);
	else
	{
		l_e = malloc(sizeof(t_env));
		s_gen->l_env = l_e;
		pwd = malloc(255);
		getcwd(pwd, 255);
		l_e->path = ft_strjoin_char("PWD", pwd, '=');
		free(pwd);
	}
	l_e->next = NULL;
}

void	env_to_tab(t_gener *s_gen)
{
	char	**tab;
	t_env	*list;
	int		size;
	int		i;

	list = s_gen->l_env;
	i = 0;
	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	list = s_gen->l_env;
	tab = (char **)malloc(sizeof(char *) * (size + 1));
	while (list)
	{
		tab[i] = ft_strdup(list->path);
		i++;
		list = list->next;
	}
	tab[i] = NULL;
	s_gen->tab_env = tab;
}
