/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:35:26 by brclemen          #+#    #+#             */
/*   Updated: 2024/03/22 11:58:58 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define STDOUT 1
# define STDIN 0

/*
************************************************
                    INCLUDES                   
************************************************
*/

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <string.h>
# include <fcntl.h>  
# include <sys/wait.h>
# include <stdio.h>
# include "Libft/libft.h"

/*
************************************************
                    FONCTIONS                      
************************************************
*/
void	waiting_process(pid_t id, pid_t id2);
void	not_enough_line(int *p_fd, pid_t id, pid_t id2);
void	child2_process(char *av[], char **env, int *p_fd);
void	cmd_execute(char **env, char *cmd);
void	child_process(char *av[], char **env, int *p_fd);
void	ft_free(char **str);
void	error(int status);
char	*search_path(char **env, char *cmd_split);
int		verif_cmd(char *cmd_split);

#endif
