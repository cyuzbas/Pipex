/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/18 14:04:24 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/08/26 16:07:31 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct t_data
{
	int		fd[2];
	int		child_1;
	int		child_2;

	char	*infile;
	char	*outfile;
	char	*cmd1;
	char	*cmd2;

	int		fd_infile;
	int		fd_outfile;

	char	**envp;
}			t_data;

int		main(int argc, char **argv, char **envp);
void	pipex(t_data *data);
void	child_process(t_data *data);
void	parent_process(t_data *data);
void	ft_error(char *str);

void	ft_free(char **paths);
char	*join_path(char **paths, char *cmd);
char	*find_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);

#endif