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

 int	verif_errors(char *av[])
{
	int	i;
	int	j;

	j = -1;
	i = -1;
	if (!av[3][0] || !av[4][0])
		return (1);
	if (only_space(av[3]) == 1 || only_space(av[4]) == 1)
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