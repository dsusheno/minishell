/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 16:58:55 by dsusheno          #+#    #+#             */
/*   Updated: 2016/06/11 17:53:09 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lib.h"

void	ft_env_void(t_gener *s_gen, int i)
{
	int acs;

	acs = 1;
	if (s_gen->cmd)
		free(s_gen->cmd);
	s_gen->cmd = NULL;
	s_gen->cmd = ft_strdup(s_gen->arg[i + 2]);
	ft_deplace_env(s_gen, i);
	if (ft_strncmp(s_gen->arg[0], "/", 1) &&
			ft_strncmp(s_gen->arg[0], "..", 2) &&
			ft_strncmp(s_gen->arg[0], ".", 1))
	{
		if (s_gen->cmd)
			free(s_gen->cmd);
		s_gen->cmd = NULL;
		path_verif_for_env(s_gen);
	}
	acs = access(s_gen->cmd, F_OK);
	if (!ft_acs_fail(s_gen, i))
		if_non_reg(s_gen);
	if (s_gen->tab_env)
		ft_free_tab(s_gen->tab_env);
	s_gen->tab_env = NULL;
}

void	ft_env_full(t_gener *s_gen, int i)
{
	if (s_gen->cmd)
		free(s_gen->cmd);
	s_gen->cmd = NULL;
	s_gen->cmd = ft_strdup(s_gen->arg[i + 2]);
	ft_deplace_env(s_gen, i);
	if (ft_strncmp(s_gen->arg[0], "/", 1) &&
			ft_strncmp(s_gen->arg[0], "..", 2) &&
			ft_strncmp(s_gen->arg[0], ".", 1))
	{
		if (s_gen->cmd)
			free(s_gen->cmd);
		s_gen->cmd = NULL;
		path_verif_for_env(s_gen);
	}
	if (!ft_acs_fail(s_gen, i))
		if_non_reg(s_gen);
}

void	ft_env_norm(t_gener *s_gen, int i)
{
	int acs;

	acs = 0;
	if (s_gen->cmd)
		free(s_gen->cmd);
	s_gen->cmd = NULL;
	s_gen->cmd = ft_strdup(s_gen->arg[i + 1]);
	ft_deplace_env_norm(s_gen, i);
	if (ft_strncmp(s_gen->arg[0], "/", 1) &&
			ft_strncmp(s_gen->arg[0], "..", 2) &&
			ft_strncmp(s_gen->arg[0], ".", 1))
	{
		if (s_gen->cmd)
			free(s_gen->cmd);
		s_gen->cmd = NULL;
		path_verif_for_env(s_gen);
	}
	if (!ft_acs_fail(s_gen, i))
		if_non_reg(s_gen);
}

void	ft_env_iu_center(t_gener *s_gen, int i)
{
	if (!s_gen->arg[i + 1])
	{
		ft_env_disp(s_gen);
		s_gen->cmd = NULL;
	}
	else if (!ft_strncmp(s_gen->arg[i + 1], "--", 2) && !s_gen->arg[i + 1][2])
		ft_env_full(s_gen, i);
	else if (!ft_strncmp(s_gen->arg[i + 1], "-i", 2) && !s_gen->arg[i + 1][2])
		ft_env_i(s_gen, i);
	else if (!ft_strncmp(s_gen->arg[i + 1], "-", 1) && !s_gen->arg[i + 1][1])
		ft_env_void(s_gen, i);
	else if (ft_strncmp(s_gen->arg[i + 1], "-", 1))
		ft_env_norm(s_gen, i);
	else if (!ft_strncmp(s_gen->arg[i + 1], "-", 1))
	{
		if (s_gen->cmd)
			free(s_gen->cmd);
		s_gen->cmd = NULL;
		ft_putstr("env: illegal option -- ");
		ft_putchar(s_gen->arg[i + 1][1]);
		ft_putchar('\n');
		ft_putstrn("usage: env [-i|--|-] [name=value ...]"
				" [utility [argument ...]]");
	}
}

int		ft_env_iu(t_gener *s_gen)
{
	int		i;

	i = 0;
	while (!ft_strncmp(s_gen->arg[i], "env", 3) && !s_gen->arg[i][3])
	{
		if (s_gen->arg[i + 1])
		{
			if ((!ft_strncmp(s_gen->arg[i + 1], "env", 3)
						&& !s_gen->arg[i + 1][3]))
				i++;
			else
				break ;
		}
		else
			break ;
	}
	if (!ft_strncmp(s_gen->arg[i], "env", 3) && !s_gen->arg[i][3])
	{
		ft_env_iu_center(s_gen, i);
		return (1);
	}
	return (0);
}
