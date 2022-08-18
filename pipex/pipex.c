/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/10 15:50:52 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/08/18 19:42:25 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	ft_error(char *str)
// {
// 	ft_putendl_fd (str, 1);
// 	exit(EXIT_FAILURE);
// }

void	child_process(t_data *data)
{
	data->fd_infile = open(data->infile, O_RDONLY);
	if (data->fd_infile == -1)
	{
		perror("Error opening input file");
		close(data->fd[1]);
		exit(EXIT_FAILURE);
	}
	dup2(data->fd_infile, STDIN_FILENO);
	dup2(data->fd[1], STDOUT_FILENO);
	close(data->fd[0]);
//	close(data->fd[1])
	close(data->fd_infile);
//execve function for each possible path

	exit(EXIT_FAILURE);
}

void	parent_process(t_data *data)
{
	int	count;

	waitpid(data->pid, NULL, 0);
	data->fd_outfile = open(data->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (data->fd_outfile == -1)
	{
		perror("Error opening output file");
		close(data->fd[0]);
		exit(EXIT_FAILURE);
	}
	dup2(data->fd_outfile, STDOUT_FILENO);
	dup2(data->fd[0], STDIN_FILENO);
	close(data->fd[1]);
//	close(data->fd[0]);
	close(data->fd_outfile);
// execve function for each possible path
	exit(EXIT_FAILURE);
}

void	pipex(t_data *data)
{
	if (pipe(data->fd) == -1)
		return (perror("Pipe Error"));
	data->pid = fork();
	if (data->pid == -1)
		return (perror("Fork Error"));
	if (data->pid == 0)
		child_process(data);
	else
		parent_process(data);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		fd[2];

	if (argc != 5)
	{
		printf("Usage: ./pipex file1 cmd1 cmd2 file2");
		exit(EXIT_FAILURE);
	}
	data.infile = argv[1];
	data.cmd1 = argv[2];
	data.cmd2 = argv[3];
	data.outfile = argv[4];
	data.envp = envp;
	pipex(&data);
	return (0);
}
