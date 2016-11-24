/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 14:36:50 by dsusheno          #+#    #+#             */
/*   Updated: 2016/06/11 18:02:40 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lib.h"

void	ft_shlvl(t_gener *s_gen)
{
	t_env	*list;
	int		i;
	int		lvl;
	char	*lvl_ch;

	i = 0;
	list = s_gen->l_env;
	while (list != NULL && ft_strncmp(list->path, "SHLVL", 5))
		list = list->next;
	if (list != NULL)
	{
		while (list->path[i] != '=')
			i++;
		i++;
		lvl = ft_atoi(&list->path[i]);
		lvl++;
		free(list->path);
		lvl_ch = ft_itoa(lvl);
		list->path = ft_strjoin_char("SHLVL", lvl_ch, '=');
		free(lvl_ch);
	}
}

void	ft_tilde(t_gener *s_gen)
{
	int		i;
	char	*copy;
	char	*point;

	i = 0;
	copy = NULL;
	while (s_gen->arg[i] != NULL)
	{
		if (!ft_strncmp(s_gen->arg[i], "~", 1))
		{
			point = s_gen->arg[i];
			if (!s_gen->home)
				s_gen->home = ft_strdup("/");
			if (s_gen->arg[i][1])
			{
				copy = &s_gen->arg[i][1];
				s_gen->arg[i] = ft_strjoin(s_gen->home, copy);
			}
			else
				s_gen->arg[i] = ft_strdup(s_gen->home);
			free(point);
		}
		i++;
	}
}

int		ex_verif(char *elem, t_gener *s_gen, int size)
{
	t_env	*l_copy;
	int		i;

	i = 0;
	l_copy = s_gen->l_env;
	while (l_copy != NULL && ft_strncmp(l_copy->path, elem, size))
		l_copy = l_copy->next;
	if (l_copy == NULL)
		return (0);
	return (1);
}

void	ft_init_str(t_gener *s_gen)
{
	s_gen->cmd = NULL;
	s_gen->pwd = NULL;
	s_gen->copy = NULL;
	s_gen->cmd_line = NULL;
	s_gen->path = NULL;
	s_gen->path_g = NULL;
	s_gen->arg = NULL;
	s_gen->home = NULL;
	s_gen->oldpwd = NULL;
	s_gen->tab_env = NULL;
	s_gen->nb_cmd = 0;
	s_gen->nb_space = 0;
	s_gen->l_env = NULL;
	ft_oldpwd(s_gen);
}

void	start_env(t_gener *s_gen)
{
	if (ex_verif("HOME", s_gen, 4))
		s_gen->home = my_getenv("HOME", s_gen);
	else
		s_gen->home = NULL;
	if (ex_verif("PATH", s_gen, 4))
		s_gen->path_g = my_getenv("PATH", s_gen);
	else
		s_gen->path_g = "/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin";
	if (ex_verif("PWD", s_gen, 3))
		s_gen->pwd = my_getenv("PWD", s_gen);
	else
	{
		s_gen->pwd = malloc(sizeof(char) * 255);
		getcwd(s_gen->pwd, 255);
	}
	if (!ex_verif("SHLVL", s_gen, 5))
		ft_add_env(s_gen, "SHLVL", "1");
	else
		ft_shlvl(s_gen);
	if (ex_verif("SHELL", s_gen, 5))
		ft_unsetenv(s_gen, "SHELL");
}
