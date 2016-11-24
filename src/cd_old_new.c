/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_old_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 16:48:00 by dsusheno          #+#    #+#             */
/*   Updated: 2016/06/11 17:47:59 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lib.h"

void	ft_cd_old(t_gener *s_gen)
{
	t_env	*list;
	char	*buf;

	list = s_gen->l_env;
	buf = NULL;
	ft_oldpwd(s_gen);
	if (ex_verif("OLDPWD", s_gen, 6))
	{
		while (ft_strncmp(list->path, "OLDPWD", 6))
			list = list->next;
		free(list->path);
		list->path = NULL;
		buf = malloc(sizeof(char) * 256);
		getcwd(buf, 255);
		list->path = ft_strjoin_char("OLDPWD", buf, '=');
		free(buf);
	}
}

void	ft_oldpwd(t_gener *s_gen)
{
	char	*buf;

	buf = NULL;
	buf = malloc(sizeof(char) * 256);
	getcwd(buf, 255);
	if (s_gen->oldpwd)
		free(s_gen->oldpwd);
	s_gen->oldpwd = ft_strdup(buf);
	free(buf);
}

void	ft_cd_new(t_gener *s_gen)
{
	t_env	*list;
	char	*buf;

	list = s_gen->l_env;
	buf = NULL;
	buf = malloc(sizeof(char) * 256);
	getcwd(buf, 255);
	if (ex_verif("PWD", s_gen, 3))
	{
		while (ft_strncmp(list->path, "PWD", 3))
			list = list->next;
		free(list->path);
		list->path = NULL;
		list->path = ft_strjoin_char("PWD", buf, '=');
	}
	else
	{
		while (list->next)
			list = list->next;
		list->next = malloc(sizeof(t_env));
		list = list->next;
		list->next = NULL;
		list->path = ft_strjoin_char("PWD", buf, '=');
	}
	free(buf);
}
