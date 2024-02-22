#include "pipex.h"

// A free fonction maybe.

void    ft_free(char **str)
{
    int i;
    
    i = 0;
    while (str[i++])
        free(str[i]);
    free(str);
} 

// cmd if the command have a blank split it in a varable
// cmd usefull while using exceve
// now the cmd split have two commands if has an exemple (ls -l)
// searching the path through the env variable.

void    cmd_execute(char *av[], char **env)
{
    char **cmd_split;
    char *cmd_exe;
    cmd_split = ft_split(av[2], ' ');
    cmd_exe = search_path(av, env, cmd_split);
    if (execve(cmd_exe, av, env) == -1)
    {
        ft_printf("*****************************");
        ft_printf("ERROR : Command not found !");
        ft_printf("*****************************");
    }
    free(cmd_exe);
}

// A fonction to get the path of the ENV variable.
// all the paths possible in this variable.
// put the path and the slash and join the path.
// verif with the access fonction if it is the good path or not.

char *search_path(char *av[], char **env, char **cmd_split)
{
    int i;
    char    **paths;
    char *cmd_final;

    i = 0;
    while (ft_strnstr(env[i], "PATH", 4) == NULL)
        i++;
    paths = ft_split(env[i] + 5, ':');
    i = 0;
    while (paths[i])
    {
        cmd_final = ft_strjoin(paths[i], "/");
        cmd_final = ft_strjoin(cmd_final, *cmd_split);
        if (access(cmd_final, F_OK) == 0)
        {
            free(cmd_final);
            ft_free(paths);
            return (cmd_final);
        }
        free(cmd_final);
    }
    ft_free(paths);
    return (NULL);
}
