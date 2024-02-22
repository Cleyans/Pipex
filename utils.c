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

void    cmd_execute(char **env, char *cmd)
{
    char **cmd_split;
    char *cmd_exe;
    cmd_split = ft_split(cmd, ' ');
    cmd_exe = search_path(env, cmd_split[0]);
    printf("%s\n", cmd_exe);
    if (execve(cmd_exe, cmd_split, env) == -1)
    {
        ft_printf("*******************************\n");
        ft_printf("* ERROR : Command not found ! *\n");
        ft_printf("*******************************\n");
        exit(-1);
    }
}

// A fonction to get the path of the ENV variable.
// all the paths possible in this variable.
// put the path and the slash and join the path.
// verif with the access fonction if it is the good path or not.

char *search_path(char **env, char *cmd_split)
{
    int i;
    char    **paths;
    char *cmd_final;
    char *cmd_join;

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
