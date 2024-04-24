/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:32:20 by brclemen          #+#    #+#             */
/*   Updated: 2024/04/24 06:50:40 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error(int status, char *cmd_error)
{
	if (status == 1)
	{
		ft_putstr_fd("Error: command not found: ", 2);
		ft_putstr_fd(cmd_error, 2);
		write(2, "\n", 1);
		exit(-1);
	}
	if (status == 0)
	{
		ft_putstr_fd("Error: command not found: ", 2);
		ft_putstr_fd(cmd_error, 2);
		write(2, "\n", 1);
		exit(-1);
	}
}

void	cmd_execute(char **env, char *cmd)
{
	char	**cmd_split;
	char	*cmd_exe;

	cmd_split = ft_split(cmd, ' ');
	if (access(cmd, F_OK) == 0)
		execve(cmd, cmd_split, env);
	cmd_exe = search_path(env, cmd_split[0]);
	if (!cmd_exe)
	{
		ft_free(cmd_split);
		error(0, cmd);
	}
	if (execve(cmd_exe, cmd_split, env) == -1)
	{
		error(0, cmd);
	}
}

char	*search_path(char **env, char *cmd_split)
{
	int			i;
	char		**paths;
	char		*cmd_final;
	char		*cmd_join;

	i = 0;
	while (env[i] && ft_strnstr(env[i], "PATH", 4) == NULL)
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		cmd_join = ft_strjoin_pipex(paths[i], "/");
		cmd_final = ft_strjoin_pipex(cmd_join, cmd_split);
		free(cmd_join);
		if (access(cmd_final, F_OK) == 0)
		{
			ft_free(paths);
			return (cmd_final);
		}
		free(cmd_final);
		i++;
	}
	ft_free(paths);
	return (NULL);
}
