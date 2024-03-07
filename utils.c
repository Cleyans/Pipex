/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:32:20 by brclemen          #+#    #+#             */
/*   Updated: 2024/03/07 15:37:02 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	error(int status)
{
	if (status == 1)
		ft_putstr_fd("ERROR : Five args needed.\n", 1);
	else if (status == 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}

void	cmd_execute(char **env, char *cmd, int fd)
{
	char	**cmd_split;
	char	*cmd_exe;
	int		i;

	i = 0;
	cmd_split = ft_split(cmd, ' ');
	cmd_exe = search_path(env, cmd_split[0]);
	if (!cmd_exe)
	{
		ft_free(cmd_split);
		error(0);
	}
	if (execve(cmd_exe, cmd_split, env) == -1)
		error(0);
}

char	*search_path(char **env, char *cmd_split)
{
	int			i;
	char		**paths;
	char		*cmd_final;
	char		*cmd_join;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == NULL)
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
