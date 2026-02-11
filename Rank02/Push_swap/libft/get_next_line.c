/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:48:04 by msedeno-          #+#    #+#             */
/*   Updated: 2025/10/14 17:38:17 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free_memory(char *buffer, char *stash)
{
	if (buffer)
		free(buffer);
	if (stash)
		free(stash);
	return (NULL);
}

char	*ft_read_file(int fd, char *stash)
{
	ssize_t	bytes;
	char	*buffer;

	if (!stash)
		stash = ft_strdup("");
	buffer = (char *) malloc ((BUFFER_SIZE + 1) * sizeof (char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && ft_strchr(stash, '\n') == NULL)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (ft_free_memory(buffer, stash));
		buffer[bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (ft_free_memory(buffer, NULL));
	}
	free (buffer);
	return (stash);
}

char	*ft_reset_line(char *stash)
{
	int		i;
	char	*aux;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	if (stash[i] == '\0')
	{
		free (stash);
		stash = NULL;
		return (NULL);
	}
	aux = ft_substr(stash, i, ft_strlen(stash) - i);
	if (!aux)
		return (NULL);
	free (stash);
	stash = aux;
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
	{
		stash = NULL;
		return (NULL);
	}
	stash = ft_read_file (fd, stash);
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_substr(stash, 0, ft_strchr(stash, '\n') - stash + 1);
	if (!line)
		return (NULL);
	stash = ft_reset_line(stash);
	return (line);
}
