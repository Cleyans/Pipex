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
void	child2_process(char *av[], char **env, pid_t *p_fd);
void    cmd_execute(char *av[], char **env);
void	child_process(char *av[], char **env, pid_t *p_fd);
void    ft_free(char **str);
char    *search_path(char *av[], char **env, char **cmd_split);



#endif