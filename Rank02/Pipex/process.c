/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:30:04 by msedeno-          #+#    #+#             */
/*   Updated: 2026/02/11 16:13:00 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	father_process(t_pipex *pipex)
{
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	if (pipex->infile_fd != -1)
		close(pipex->infile_fd);
	if (pipex->outfile_fd != -1)
		close(pipex->outfile_fd);
	waitpid(pipex->child1_pid, NULL, 0);
	waitpid(pipex->child2_pid, &pipex->exit_status, 0);
	free_all(pipex);
	return (WEXITSTATUS(pipex->exit_status));
}

void	child1_process(t_pipex *pipex, char **envp)
{

	if (pipex->infile_fd != -1)
		dup2(pipex->infile_fd, STDIN_FILENO);
	dup2(pipex->pipe_fd[1], STDOUT_FILENO);
	close (pipex->pipe_fd[0]);
	close ((pipex-> pipe_fd[1]));
	if (pipex->infile_fd != -1)
		close(pipex->infile_fd);
	if (pipex->outfile_fd != -1)
		close(pipex->outfile_fd);
	pipex->cmd1_path = find_command_path(pipex->cmd1_av[0], pipex->env_paths);
	if (!pipex->cmd1_path)
	{
		perror("command not found");
		free_all(pipex);
		exit(127);
	}
	execve(pipex->cmd1_path, pipex->cmd1_av, envp);
	free_all(pipex);
	perror("execve failure");
	exit(127);
}

void	child2_process(t_pipex *pipex, char **envp)
{

	if (dup2(pipex->pipe_fd[0], STDIN_FILENO) == -1)
		exit(1);
	if (dup2(pipex->outfile_fd, STDOUT_FILENO) == -1)
		exit(1);
	if (pipex->pipe_fd[1] != -1)
		close(pipex->pipe_fd[1]);
	if (pipex->pipe_fd[0] != -1)
		close(pipex->pipe_fd[0]);
	if (pipex->infile_fd != -1)
		close(pipex->infile_fd);
	if (pipex->outfile_fd != -1)
		close(pipex->outfile_fd);
	pipex->cmd2_path = find_command_path(pipex->cmd2_av[0], pipex->env_paths);
	if (!pipex->cmd2_path)
	{
		perror("command not found");
		free_all(pipex);
		exit(127);
	}
	execve(pipex->cmd2_path, pipex->cmd2_av, envp);
	free_all(pipex);
	perror("execve failure");
	exit(127);
}
