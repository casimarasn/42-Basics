/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 22:01:12 by casimarasn        #+#    #+#             */
/*   Updated: 2026/02/14 20:57:20 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/inc/libft.h"

typedef struct s_pipex
{
	int		infile_fd;
	int		outfile_fd;
	int		pipe_fd[2];
	char	**env_paths;
	char	*cmd1;
	char	*cmd2;
	char	**cmd1_av;
	char	**cmd2_av;
	char	*cmd1_path;
	char	*cmd2_path;
	pid_t	child1_pid;
	pid_t	child2_pid;
	int		exit_status;
}			t_pipex;

// ./errors_free.c

/**
 * @brief Prints the usage error message to stderr.
 * @param prog The name of the program (argv[0]).
 */
void	error_message(const char *prog);

/**
 * @brief Frees a NULL-terminated array of strings.
 * @param array The array to be freed.
 */
void	free_array(char **array);

/**
 * @brief Frees all allocated memory in the t_pipex structure.
 * @param pipex Pointer to the main structure.
 */
void	free_all(t_pipex *pipex);

// ./pipex.c

/**
 * @brief Initializes all fields of the t_pipex structure to default values.
 * Sets FDs and PIDs to -1 and pointers to NULL to prevent memory issues.
 * @param pipex Pointer to the main structure.
 */
void	init_pipex_values(t_pipex *pipex);

/**
 * @brief Searches and extracts the PATH variable from the environment.
 * @param envp Environment variables array.
 * @return Pointer to the string after "PATH=" or NULL if not found.
 */
char	*get_path_from_env(char **envp);

/**
 * @brief Orchestrates the initialization phase.
 * Validates arguments, sets up paths, commands, and file descriptors.
 * @return 0 on success, -1 on critical error.
 */
int		init_pipex(t_pipex *pipex, int ac, char **av, char **envp);

/**
 * @brief Creates child processes using fork and assigns their logic.
 * @param envp Environment variables for execve.
 * @return 0 on success, 1 on fork failure.
 */
int		launch_children(t_pipex *pipex, char **envp);

/**
 * @brief Main entry point. Handles the pipe creation and program flow.
 */
int		main(int ac, char **av, char **envp);

// ./process.c

/**
 * @brief Parent process logic. Closes FDs and waits for children.
 * @return The exit status of the second child.
 */
int		father_process(t_pipex *pipex);

/**
 * @brief Child 1 logic. Redirects infile to stdin and pipe to stdout.
 */
void	child1_process(t_pipex *pipex, char **envp);

/**
 * @brief Child 2 logic. Redirects pipe to stdin and stdout to outfile.
 */
void	child2_process(t_pipex *pipex, char **envp);

// ./setup.c

/**
 * @brief Counts the number of single quotes in a command string.
 * Used to determine if the command contains arguments wrapped in quotes.
 * @param cmd The command string to analyze.
 * @return The total count of single quote characters.
 */
int		count_qmarks(char *cmd);

/**
 * @brief Selects the splitting strategy for command arguments.
 * If single quotes are detected, it splits by quote; otherwise, by spaces.
 * @param cmd The raw command string from argv.
 * @return A NULL-terminated array of strings (arguments).
 */
char	**split_ways(char *cmd);

/**
 * @brief Sets up command arguments and validates they are not empty.
 * @param pipex Pointer to the main structure.
 * @param av Command line arguments.
 * @return 0 on success, -1 if commands are invalid or empty.
 */
int		setup_commands(t_pipex *pipex, char **av);

/**
 * @brief Opens input and output files with appropriate permissions.
 * Mimics shell behavior by allowing execution even if infile fails.
 * @param pipex Pointer to the main structure.
 * @param av Command line arguments (av[1] for infile, av[4] for outfile).
 * @return 0 on success, -1 only if the output file cannot be created.
 */
int		setup_files(t_pipex *pipex, char **av);

/**
 * @brief Locates the absolute path of a command binary.
 * Checks for direct paths first, then searches through the PATH directories.
 * @param cmd The command name (e.g., "ls").
 * @param env_paths Array of directories from the PATH variable.
 * @return An allocated string with the full path, or NULL if not found.
 */
char	*find_command_path(char *cmd, char **env_paths);

#endif