/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:33:00 by hehuang           #+#    #+#             */
/*   Updated: 2024/09/06 18:58:02 by hehuang          ###   ########.fr       */
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
	char	*exec;
	int		i;

	i = -1;
	paths = ft_split(ft_get_env("PATH", envp), ':');
	while (paths[++i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		exec = ft_strjoin(paths[i], cmd);
		if (access(exec, F_OK | X_OK) == 0)
		{
			free(paths);
			return (exec);
		}
		free (exec);
	}
	free(paths);
	return (NULL);
}

void	process_one(char	*path, int *fds, char *cmd, char **envp)
{
	int		infile;
	char	**cmd_arg;

	cmd_arg = ft_split(cmd, ' ');
	printf("%s ,%s\n", ft_get_path(cmd_arg[0], envp), cmd);
	infile = open(path, O_RDONLY);
	if (infile == -1 )
		printf("error infile\n");
	dup2(infile, STDIN_FILENO);
	dup2(fds[1], STDOUT_FILENO);
	close(fds[0]);
	close(infile);
	execve(ft_get_path(cmd_arg[0], envp), cmd_arg, envp);
//free if execve fail
}
void	process_two(char	*path, int *fds, char *cmd, char **envp)
{
	int		outfile;
	char	**cmd_arg;

	cmd_arg = ft_split(cmd, ' ');
	printf("%s ,%s\n", ft_get_path(cmd_arg[0], envp), cmd);
	outfile = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		printf("error outfile\n");
	dup2(fds[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	close(fds[1]);
	execve(ft_get_path(cmd_arg[0], envp), cmd_arg, envp);
//free if execve fail
}

int	main(int argc, char **argv, char **envp)
{
	int		fds[2];
	pid_t	pid;

	argc --;
	argv ++;
	(void)envp;
	if (pipe(fds) == -1)
		printf("pipe error\n");
	pid = fork();
	if (pid == -1)
		printf("fork error\n");
	if (pid == 0)
		process_one(argv[0], fds, argv[1], envp);
	else
		process_two(argv[argc - 1], fds, argv[2], envp);
	return (0);
}
