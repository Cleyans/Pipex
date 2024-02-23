/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:35:26 by brclemen          #+#    #+#             */
/*   Updated: 2024/02/23 11:37:21 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
void	child2_process(char *av[], char **env, int *p_fd);
void	cmd_execute(char **env, char *cmd, int fd);
void	child_process(char *av[], char **env, int *p_fd);
void	ft_free(char **str);
void	error(void);
char	*search_path(char **env, char *cmd_split);

#endif
