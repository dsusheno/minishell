/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 16:46:32 by dsusheno          #+#    #+#             */
/*   Updated: 2016/06/11 17:54:24 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lib.h"

void	ft_cd_center3(t_gener *s_gen)
{
	DIR		*dir;

	if (access(s_gen->arg[1], F_OK) == 0)
	{
		if ((dir = opendir(s_gen->arg[1])))
		{
			ft_cd_old(s_gen);
			chdir(s_gen->arg[1]);
			ft_cd_new(s_gen);
			closedir(dir);
		}
		else
		{
			ft_putstr("cd: not a directory: ");
			ft_putstrn(s_gen->arg[1]);
		}
	}
	else
	{
		ft_putstr(s_gen->arg[1]);
		ft_putstrn(": No such file or directory.");
	}
}

void	ft_cd_center2(t_gener *s_gen)
{
	char	*old_copy;

	old_copy = NULL;
	if (s_gen->arg[1][0] == '-' && !s_gen->arg[1][1])
	{
		if (s_gen->oldpwd)
		{
			old_copy = ft_strdup(s_gen->oldpwd);
			ft_oldpwd(s_gen);
			chdir(old_copy);
			free(old_copy);
		}
	}
	else
		ft_cd_center3(s_gen);
}

void	ft_cd_center1(t_gener *s_gen)
{
	if (s_gen->arg[1] != NULL && s_gen->arg[2] != NULL)
	{
		ft_putstr("cd: Too many arguments. ");
		ft_putstrn("Usage: cd [-|<dir>].");
	}
	else if (s_gen->arg[1] == NULL)
	{
		if (s_gen->home)
		{
			ft_cd_old(s_gen);
			chdir(s_gen->home);
			ft_cd_new(s_gen);
		}
		else
			ft_putstrn("cd: No home directory.");
	}
	else
		ft_cd_center2(s_gen);
}

int		ft_cd(t_gener *s_gen)
{
	int		i;

	i = 0;
	if (ex_verif("HOME", s_gen, 4))
	{
		if (s_gen->home)
			free(s_gen->home);
		s_gen->home = NULL;
		s_gen->home = my_getenv("HOME", s_gen);
	}
	if ((!ft_strncmp(s_gen->arg[0], "cd", 2) ||
		!ft_strncmp(s_gen->arg[0], "CD", 2)) && !s_gen->arg[0][2])
	{
		ft_cd_center1(s_gen);
		return (1);
	}
	return (0);
}
