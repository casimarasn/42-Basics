/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:21:43 by msedeno-          #+#    #+#             */
/*   Updated: 2026/02/11 16:13:40 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipex_values(t_pipex *pipex)
{
	pipex->infile_fd = -1;
	pipex->outfile_fd = -1;
	pipex->pipe_fd[0] = -1;
	pipex->pipe_fd[1] = -1;
	pipex->env_paths = NULL;
	pipex->cmd1 = NULL;
	pipex->cmd2 = NULL;
	pipex->cmd1_av = NULL;
	pipex->cmd2_av = NULL;
	pipex->cmd1_path = NULL;
	pipex->cmd2_path = NULL;
	pipex->child1_pid = -1;
	pipex->child2_pid = -1;
	pipex->exit_status = 0;
}

char	*get_path_from_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

int	init_pipex(t_pipex *pipex, int ac, char **av, char **envp)
{
	char	*path_name;

	if (ac != 5)
	{
		error_message(av[0]);
		return (-1);
	}
	init_pipex_values(pipex);
	path_name = get_path_from_env(envp);
	if (!path_name || !*path_name)
		pipex->env_paths = NULL;
	else
		pipex->env_paths = ft_split(path_name, ':');
	if (setup_commands(pipex, av) == -1)
	{
		error_message(av[2]);
		free_array(pipex->env_paths);
		return (-1);
	}
	if (setup_files(pipex, av) == -1)
		return (-1);
	return (0);
}

int	launch_children(t_pipex *pipex, char **envp)
{
	pipex->child1_pid = fork();
	if (pipex->child1_pid == -1)
	{
		perror("fork failure");
		free_array(pipex->env_paths);
		return (1);
	}
	if (pipex->child1_pid == 0)
		child1_process(pipex, envp);
	pipex->child2_pid = fork();
	if (pipex->child2_pid == -1)
	{
		free_all(pipex);
		perror("fork failure");
		return (1);
	}
	if (pipex->child2_pid == 0)
		child2_process(pipex, envp);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (init_pipex(&pipex, ac, av, envp) == -1)
		return (1);
	if (pipe(pipex.pipe_fd) == -1)
	{
		perror("pipe failure");
		free_array(pipex.env_paths);
		return (1);
	}
	if (launch_children(&pipex, envp))
		return (1);
	return (father_process(&pipex));
}
