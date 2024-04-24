/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:40:53 by brclemen          #+#    #+#             */
/*   Updated: 2024/04/24 06:50:23 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	only_space(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	verif_cmd(char *cmd, char **env)
{
	if ((!*env || ft_strcmp(env[0], "LD_LIBRARY_PATH=/usr/lib/debug") == 0)
		&& (access(cmd, F_OK) != 0))
	{
		ft_putstr_fd("Error: Path cannot be found.\n", 2);
		return (-1);
	}
	if (cmd == NULL)
	{
		ft_putstr_fd("Error: command not found:", 2);
		ft_putstr_fd(cmd, 2);
		write(2, "\n", 1);
		return (-1);
	}
	if (only_space(cmd) == 1)
	{
		ft_putstr_fd("Error: command not found: ", 2);
		ft_putstr_fd(cmd, 2);
		write(2, "\n", 1);
		return (-1);
	}
	return (0);
}

int	verif_errors(char *av[], char **env)
{
	if ((!*env || ft_strcmp(env[0], "LD_LIBRARY_PATH=/usr/lib/debug") == 0)
		&& (access(av[2], F_OK) != 0 && access(av[3], F_OK) != 0))
	{
		ft_putstr_fd("Error : the env is empty and none of the \
commands are absolute paths.\n", 2);
		exit(-1);
	}
	return (0);
}
