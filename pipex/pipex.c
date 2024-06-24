/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:33:00 by hehuang           #+#    #+#             */
/*   Updated: 2024/06/24 19:01:51 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	./pipex file1	cmd1	|	cmd2 >	file2
//  ./pipex infile	"ls -l"		"wc -l"	outfile

#include "pipex.h"
#include "libft/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while ((s1[i] || s2[i]) && s1[i] == s2[i] && i < n - 1)
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

size_t	ft_strlen(const char *s)
{
	int	res;

	res = 0;
	while (s[res])
		res ++;
	return (res);
}

char	*ft_get_env(char	*name, char	**envp)
{
	int	i;
	int	n_len;
	int	env_len;

	i = -1;
	n_len = ft_strlen(name);
	while (envp[++i])
	{
		env_len = ft_strlen(envp[i]);
		if (env_len > n_len && envp[i][n_len] == '='
			&& !ft_strncmp(name, envp[i], n_len))
		{
			return (envp[i] + n_len + 1);
		}
	}
	return (NULL);
}

char	*ft_get_path(char	*cmd, char	**envp)
{
	char	**paths;
	int		i;

	i = -1;
	paths = ft_split(ft_get_env("PATH", envp), ';');
	while (paths[++i])
	{

	}
}

void	main_process(char	*path, int *fds)
{
	int	fd;

	fd = open(path, O_RDONLY, 0444);
	dup2(fds[0], fd);
}

int	main(int argc, char **argv, char **envp)
{
	int		fds[2];
	pid_t	pid;

	argc --;
	argv ++;
	(void)envp;
	if (pipe(fds) == -1)
		printf("no\n");
	else
	{
		printf("yes\n");
	}
	pid = fork();
	if (pid == -1)
		printf("no\n");
	else
		printf("yes\n");
	if (pid == 0)
		printf("child\n");
	else
		printf("parent\n");
	//while (*envp)
		//printf("%s\n",*envp++);
	//printf("%s\n", ft_get_env("PATH", envp));
	return (0);
}
