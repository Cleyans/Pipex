/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:56:01 by brclemen          #+#    #+#             */
/*   Updated: 2024/02/23 14:02:58 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child2_process(char *av[], char **env, int *p_fd)
{
	int	fd;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(fd);
	close(p_fd[0]);
	close(p_fd[1]);
	cmd_execute(env, av[3], fd);
}

void	child_process(char *av[], char **env, int *p_fd)
{
	int	fd;

	fd = open(av[1], O_RDONLY, 0777);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(fd);
	close(p_fd[1]);
	close(p_fd[0]);
	cmd_execute(env, av[2], fd);
}

void	waiting_process(pid_t id, pid_t id2)
{
	waitpid(id, NULL, 0);
	waitpid(id2, NULL, 0);
}

void	ft_error_args(void)
{
	ft_putstr_fd("ERROR : Five args needed.\n", 1);
}

int	main(int ac, char *av[], char **env)
{
	int		p_fd[2];
	pid_t	p_id;
	pid_t	p_id2;

	if (ac == 5)
	{
		if (pipe(p_fd) == -1)
			exit (-1);
		p_id = fork();
		if (p_id == -1)
			exit (-1);
		else if (p_id == 0)
			child_process(av, env, p_fd);
		p_id2 = fork();
		if (p_id2 == -1)
			exit (-1);
		else if (p_id2 == 0)
			child2_process(av, env, p_fd);
		close(p_fd[0]);
		close(p_fd[1]);
		waiting_process(p_id, p_id2);
	}
	else
		ft_error_args();
	return (0);
}
