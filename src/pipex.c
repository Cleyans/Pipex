/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:56:01 by brclemen          #+#    #+#             */
/*   Updated: 2024/04/04 12:08:18 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child2_process(char *av[], char **env, int *p_fd)
{
	int	fd;

	close(p_fd[1]);
	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		perror("Error");
		close(p_fd[0]);
		exit(-1);
	}
	dup2(fd, STDOUT);
	close(fd);
	dup2(p_fd[0], STDIN);
	close(p_fd[0]);
	cmd_execute(env, av[3]);
}

void	child_process(char *av[], char **env, int *p_fd)
{
	int	fd;

	close(p_fd[0]);
	fd = open(av[1], O_RDONLY, 0777);
	if (fd == -1)
	{
		perror("Error");
		close(p_fd[1]);
		exit(-1);
	}
	dup2(fd, STDIN);
	close(fd);
	dup2(p_fd[1], STDOUT);
	close(p_fd[1]);
	cmd_execute(env, av[2]);
}

void	waiting_process(pid_t id, pid_t id2)
{
	if (waitpid(id, NULL, 0) == -1)
	{
		perror("Error");
		exit(-1);
	}
	if (waitpid(id2, NULL, 0) == -1)
	{
		perror("Error");
		exit(-1);
	}
}

void	not_enough_line(int *p_fd, pid_t id, pid_t id2)
{
	close(p_fd[0]);
	close(p_fd[1]);
	waiting_process(id, id2);
}
// [0] == READ [1] == WRITE

int	main(int ac, char *av[], char **env)
{
	int		p_fd[2];
	pid_t	p_id;
	pid_t	p_id2;

	if (ac == 5 && verif_errors(av, env) == 0)
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
		not_enough_line(p_fd, p_id, p_id2);
	}
	else
		error(1);
	return (0);
}
