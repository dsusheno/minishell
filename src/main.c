/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 15:53:14 by dsusheno          #+#    #+#             */
/*   Updated: 2016/07/06 14:26:14 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lib.h"

int		verif_line(t_gener *s_gen)
{
	int	i;
	int ver;

	i = 0;
	ver = 0;
	while (s_gen->cmd_line[i] != '\0' && s_gen->cmd_line[i] != ';')
	{
		if (s_gen->cmd_line[i] == '\t')
			s_gen->cmd_line[i] = ' ';
		if (s_gen->cmd_line[i] != ' ')
			ver = 1;
		i++;
	}
	return (ver);
}

int		ft_exit(t_gener *s_gen)
{
	int		e;

	e = 0;
	if (!ft_strncmp(s_gen->arg[0], "exit", 4)
			&& s_gen->arg[0][4] == '\0')
	{
		if (s_gen->arg[1] && s_gen->arg[2])
		{
			ft_putstrn("exit: too many arguments");
			return (0);
		}
		if (!s_gen->arg[1])
			exit(0);
		if (s_gen->arg[1] && !s_gen->arg[2])
		{
			e = ft_atoi(s_gen->arg[1]);
			exit(e);
		}
	}
	return (1);
}

void	ft_free(t_gener *s_gen)
{
	if (s_gen->path)
		free(s_gen->path);
	s_gen->path = NULL;
	if (s_gen->arg)
		ft_free_tab(s_gen->arg);
	s_gen->arg = NULL;
	if (s_gen->tab_env)
		ft_free_tab(s_gen->tab_env);
	s_gen->tab_env = NULL;
}

void	main_center(t_gener *s_gen)
{
	int			f;

	line_end(s_gen);
	str_to_wordtab(s_gen);
	ft_tilde(s_gen);
	if (ex_verif("PATH", s_gen, 4))
		s_gen->path = my_getenv("PATH", s_gen);
	else
		s_gen->path = ft_strdup(s_gen->path_g);
	env_to_tab(s_gen);
	if (!ft_cd(s_gen) && !ft_env(s_gen) && !echo(s_gen) && ft_exit(s_gen))
	{
		if (!ft_env_iu(s_gen))
			if (!prog_verif(s_gen))
				path_verif(s_gen);
		if (s_gen->cmd && ft_strncmp(s_gen->cmd, "/usr/bin/env", 12))
		{
			f = fork();
			if (!f)
				if (execve(s_gen->cmd, s_gen->arg, s_gen->tab_env) == -1)
					exit(0);
			wait(0);
		}
	}
	ft_free(s_gen);
}

int		main(int argc, char **argv, char **env)
{
	t_gener		s_gen;

	argc = 0;
	argv = NULL;
	ft_init_str(&s_gen);
	env_to_list(&s_gen, env);
	start_env(&s_gen);
	while (42)
	{
		ft_putstr("ds_shell$> ");
		get_next_line(0, &(s_gen.cmd_line));
		if (s_gen.cmd_line == NULL)
		{
			ft_putstrn("exit");
			break ;
		}
		if (verif_line(&s_gen))
			main_center(&s_gen);
		if (s_gen.cmd_line)
			free(s_gen.cmd_line);
	}
	return (0);
}
