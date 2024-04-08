/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:40:53 by brclemen          #+#    #+#             */
/*   Updated: 2024/04/08 19:40:24 by brclemen         ###   ########.fr       */
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

int	verif_errors(char *av[], char **env)
{
	if (!av[2] || !av[3])
		return (1);
	if ((!*env || ft_strcmp(env[0], "LD_LIBRARY_PATH=/usr/lib/debug") == 0)
		&& (access(av[2], F_OK) == -1 || access(av[3], F_OK) == -1))
	{
		ft_putstr_fd("Error : the env is empty and both of the \
commands are not absolute paths.\n", 2);
		exit(-1);
	}
	if (only_space(av[2]) == 1 || only_space(av[3]) == 1)
		return (1);
	return (0);
}

int	verif_cmd(char *cmd_split)
{
	if (cmd_split == NULL)
	{
		free(cmd_split);
		return (-1);
	}
	return (0);
}
