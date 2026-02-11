/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:52:39 by msedeno-          #+#    #+#             */
/*   Updated: 2026/02/11 16:18:56 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	count_qmarks(char *cmd)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (cmd && cmd[i])
	{
		if (cmd[i] == '\'')
			count++;
		i++;
	}
	return (count);
}

char	**split_ways(char *cmd)
{
	char	**chain;

	chain = NULL;
	if (count_qmarks(cmd) % 2)
	{
		chain = ft_split(cmd, '\'');
		if (!chain)
			return (NULL);
	}
	else
	{
		chain = ft_split(cmd, ' ');
		if (!chain)
			return (NULL);
	}
	return (chain);
}

int	setup_commands(t_pipex *pipex, char **av)
{
	if (!av[2] || !av[3] || !*av[2] || !*av[3])
		return (-1);
	pipex->cmd1 = av[2];
	pipex->cmd2 = av[3];
	pipex->cmd1_av = split_ways(av[2]);
	if (!pipex->cmd1_av || !pipex->cmd1_av[0])
	{
		if (pipex->cmd1_av)
			free_all(pipex);
		return (-1);
	}
	pipex->cmd2_av = split_ways(av[3]);
	if (!pipex->cmd2_av || !pipex->cmd2_av[0])
	{
		if (pipex->cmd2_av)
			free_all(pipex);
		return (-1);
	}
	return (0);
}

int	setup_files(t_pipex *pipex, char **av)
{
	pipex->infile_fd = open(av[1], O_RDONLY);
	if (pipex->infile_fd == -1)
		perror("open infile failure");
	pipex->outfile_fd = open(av[4], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (pipex->outfile_fd == -1)
	{
		perror("open outfile failure");
		return (-1);
	}
	return (0);
}

char	*find_command_path(char *cmd, char **env_paths)
{
	int		i;
	char	*tmp;
	char	*full_path;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		else
			return (NULL);
	}
	i = 0;
	while (env_paths && env_paths[i])
	{
		tmp = ft_strjoin(env_paths[i], "/");
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}
