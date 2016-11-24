/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 15:54:13 by dsusheno          #+#    #+#             */
/*   Updated: 2016/06/11 18:25:23 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_LIB_H
# define MINI_LIB_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "libft.h"
# include <dirent.h>

typedef struct		s_var
{
	int				num;
	int				count;
	int				i;
	int				k;
	int				save;
	int				acs;
	char			*copy;
	char			*point;
}					t_var;

typedef struct		s_env
{
	char			*path;
	struct s_env	*next;
}					t_env;

typedef struct		s_gener
{
	char			*cmd;
	char			*pwd;
	char			*copy;
	char			**tab_env;
	char			*cmd_line;
	char			*path;
	char			*path_g;
	char			**arg;
	char			*home;
	char			*oldpwd;
	int				nb_cmd;
	int				nb_space;
	t_env			*l_env;
}					t_gener;

void				str_to_wordtab(t_gener *s_gen);
void				arg_to_wordtab2(t_gener *s_gen, t_var *s_v);
void				path_verif(t_gener *s_gen);
char				*my_getenv(char *elem, t_gener *s_gen);
void				env_to_list(t_gener *s_gen, char **env);
void				ft_tilde(t_gener *s_gen);
void				start_env(t_gener *s_gen);
void				ft_unsetenv(t_gener *s_gen, char *elem);
int					ft_env(t_gener *s_gen);
int					ft_setenv(t_gener *s_gen);
void				ft_set(t_gener *s_gen);
void				ft_set_center(t_gener *s_gen, t_env *l_env, t_env *prew);
void				ft_env_disp(t_gener *s_gen);
void				ft_set_action(t_gener *s_gen, t_env *l_env);
int					ft_exit(t_gener *s_gen);
void				ft_init_str(t_gener *s_gen);
void				ft_add_env(t_gener *s_gen, char *elem, char *value);
void				ft_shlvl(t_gener *s_gen);
int					ex_verif(char *elem, t_gener *s_gen, int size);
void				env_to_tab(t_gener *s_gen);
void				env_to_list2(t_gener *s_gen, char **env, t_env **l_e);
void				env_to_list(t_gener *s_gen, char **env);
int					prog_verif(t_gener *s_gen);
int					ft_cd(t_gener *s_gen);
void				ft_cd_center1(t_gener *s_gen);
void				ft_cd_center2(t_gener *s_gen);
void				ft_cd_center3(t_gener *s_gen);
void				ft_oldpwd(t_gener *s_gen);
int					ft_env_iu(t_gener *s_gen);
void				ft_env_u(t_gener *s_gen, int i);
void				ft_env_i(t_gener *s_gen, int i);
void				ft_env_full(t_gener *s_gen, int i);
void				ft_env_void(t_gener *s_gen, int i);
int					ft_equal(char *str);
void				ft_env_i_par(t_gener *s_gen, int i);
void				ft_env_norm(t_gener *s_gen, int i);
void				ft_env_iu_center(t_gener *s_gen, int i);
void				path_verif_center(t_gener *s_gen, t_var *s_var);
void				line_end(t_gener *s_gen);
void				ft_cd_new(t_gener *s_gen);
void				ft_cd_old(t_gener *s_gen);
void				if_non_reg(t_gener *s_gen);
void				ft_deplace_env(t_gener *s_gen, int i);
void				ft_deplace_env_norm(t_gener *s_gen, int i);
void				ft_deplace_env_param(t_gener *s_gen, int i);
void				path_verif_for_env(t_gener *s_gen);
int					echo(t_gener *s_gen);
void				ft_echo(t_gener *s_gen, char *line);
void				ft_param_of_env(t_gener *s_gen, int *i, char *line, int c);
void				ft_match_echo(t_gener *s_gen, char *line1);
int					ft_quotes(char *line);
int					ft_backslash_verif(t_gener *s_gen, char *line);
int					ft_acs_fail(t_gener *s_gen, int i);

#endif
