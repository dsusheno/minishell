/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_param2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 18:54:59 by dsusheno          #+#    #+#             */
/*   Updated: 2016/09/06 19:16:50 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lib.h"

void	ft_deplace_env(t_gener *s_gen, int i)
{
	free(s_gen->arg[i + 1]);
	s_gen->arg[i + 1] = NULL;
	while (s_gen->arg[i + 2])
	{
		if (s_gen->arg[i])
		{
			free(s_gen->arg[i]);
			s_gen->arg[i] = NULL;
		}
		s_gen->arg[i] = ft_strdup(s_gen->arg[i + 2]);
		i++;
	}
	free(s_gen->arg[i]);
	free(s_gen->arg[i + 1]);
	s_gen->arg[i] = NULL;
	s_gen->arg[i + 1] = NULL;
}

void	ft_deplace_env_param(t_gener *s_gen, int i)
{
	free(s_gen->arg[i + 1]);
	s_gen->arg[i + 1] = NULL;
	free(s_gen->arg[i + 2]);
	s_gen->arg[i + 2] = NULL;
	while (s_gen->arg[i + 3])
	{
		if (s_gen->arg[i])
		{
			free(s_gen->arg[i]);
			s_gen->arg[i] = NULL;
		}
		s_gen->arg[i] = ft_strdup(s_gen->arg[i + 3]);
		i++;
	}
	free(s_gen->arg[i]);
	free(s_gen->arg[i + 1]);
	free(s_gen->arg[i + 2]);
	s_gen->arg[i] = NULL;
	s_gen->arg[i + 1] = NULL;
	s_gen->arg[i + 2] = NULL;
}

void	ft_deplace_env_norm(t_gener *s_gen, int i)
{
	while (s_gen->arg[i + 1])
	{
		if (s_gen->arg[i])
		{
			free(s_gen->arg[i]);
			s_gen->arg[i] = NULL;
		}
		s_gen->arg[i] = ft_strdup(s_gen->arg[i + 1]);
		i++;
	}
	free(s_gen->arg[i]);
	s_gen->arg[i] = NULL;
}

int		ft_acs_fail(t_gener *s_gen, int i)
{
	int	acs;

	acs = access(s_gen->cmd, F_OK);
	if (acs == -1)
	{
		ft_putstr("env: ");
		ft_putstr(s_gen->arg[i]);
		ft_putstrn(": No such file or directory");
		return (1);
	}
	return (0);
}
