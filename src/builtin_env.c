#include "minishell.h"

int		builtin_env(char **av, char ***env_p)
{
	(void)env_p;
	ft_printf("builtin: %s\n", av[0]);
	return (0);
}
