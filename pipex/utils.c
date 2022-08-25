/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 12:48:40 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/08/25 18:31:20 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

char	*join_path(char **paths, char *cmd)
{
	char	*full_path;
	char	*tmp_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		tmp_path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tmp_path, cmd);
		free(tmp_path);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	ft_free(paths);
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*full_path;
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i];
			break ;
		}
			i++;
	}
	if (!path)
		return (0);
	paths = ft_split(path + 5, ':');
	full_path = join_path(paths, cmd);
	if (full_path)
		return (full_path);
	free(full_path);
	return (0);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	i = 0;
	cmd = ft_split(argv, ' ');
	if (cmd[0] == NULL)
	{
		execve("", cmd, envp);
		return ;
	}
	else if (ft_strchr(cmd[0], '/') != 0)
	{
		execve(cmd[0], cmd, envp);
		return ;
	}
	else if (envp[0])
	{
		path = find_path(cmd[0], envp);
		if (!path)
			ft_free(cmd);
		execve(path, cmd, envp);
	}
}
