/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/18 14:04:24 by cyuzbas       #+#    #+#                 */
/*   Updated: 2022/08/18 19:30:21 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct t_data
{
	int		fd[2];
	int		pid;

	char	*infile;
	char	*outfile;
	char	*cmd1;
	char	*cmd2;

	int		fd_infile;
	int		fd_outfile;

	char	**path1;
	char	**path2;
	char	**envp;
}			t_data;

#endif