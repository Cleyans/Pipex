/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:40:53 by brclemen          #+#    #+#             */
/*   Updated: 2024/04/03 23:27:53 by brclemen         ###   ########.fr       */
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
	if (!*env)
		return (1); 
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
