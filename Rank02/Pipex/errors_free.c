/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:06:17 by msedeno-          #+#    #+#             */
/*   Updated: 2026/02/11 16:11:44 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_message(const char *prog)
{
	const char	*part1;
	const char	*part2;

	part1 = "err: missing argument:";
	part2 = " infile \"cmd1\" \"cmd2\" outfile\n";
	write(2, part1, 22);
	write(2, prog, ft_strlen(prog));
	write(2, part2, 30);
}

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

void	free_all(t_pipex *pipex)
{
	if (pipex->env_paths)
		free_array(pipex->env_paths);
	if (pipex->cmd1_av)
		free_array(pipex->cmd1_av);
	if (pipex->cmd2_av)
		free_array(pipex->cmd2_av);
	if (pipex->cmd1_path)
		free(pipex->cmd1_path);
	if (pipex->cmd2_path)
		free(pipex->cmd2_path);
}
