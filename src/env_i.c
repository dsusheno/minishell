/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 16:59:10 by dsusheno          #+#    #+#             */
/*   Updated: 2016/06/11 17:49:25 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lib.h"

void	if_non_reg(t_gener *s_gen)
{
	struct stat s_stat;

	lstat(s_gen->cmd, &s_stat);
	if (!S_ISREG(s_stat.st_mode))
	{
		ft_putstr("minishell: permission denied: ");
		ft_putstrn(s_gen->cmd);
	}
}

int		ft_equal(char *str)
{
	int i;
	int	eq;

	i = 0;
	eq = 0;
	while (str[i])
	{
		if (str[i] == '=')
			eq++;
		i++;
	}
	return (eq);
}

void	ft_env_i_par(t_gener *s_gen, int i)
{
	char	**tab;

	tab = NULL;
	if (s_gen->cmd)
		free(s_gen->cmd);
	s_gen->cmd = NULL;
	s_gen->cmd = ft_strdup(s_gen->arg[i + 3]);
	tab = (char **)malloc(sizeof(char *) * 2);
	tab[1] = NULL;
	tab[0] = ft_strdup(s_gen->arg[i + 2]);
	if (s_gen->tab_env)
		ft_free_tab(s_gen->tab_env);
	s_gen->tab_env = tab;
	ft_deplace_env_param(s_gen, i);
	if (ft_strncmp(s_gen->arg[0], "/", 1) &&
			ft_strncmp(s_gen->arg[0], "..", 2) &&
			ft_strncmp(s_gen->arg[0], ".", 1))
	{
		if (s_gen->cmd)
			free(s_gen->cmd);
		s_gen->cmd = NULL;
		path_verif_for_env(s_gen);
	}
	ft_acs_fail(s_gen, i);
}

void	ft_env_i(t_gener *s_gen, int i)
{
	if (s_gen->arg[i + 1] && s_gen->arg[i + 2])
	{
		if (ft_equal(s_gen->arg[i + 2]) && !s_gen->arg[i + 3])
			ft_putstrn(s_gen->arg[i + 2]);
		else if (ft_equal(s_gen->arg[i + 2]))
			ft_env_i_par(s_gen, i);
		else
			ft_env_void(s_gen, i);
	}
}
