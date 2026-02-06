/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:48:04 by msedeno-          #+#    #+#             */
/*   Updated: 2025/06/09 20:00:30 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_free_memory(char *buffer, char *stash)
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
	static char	*stash[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
	{
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = ft_read_file (fd, stash[fd]);
	if (!stash[fd] || stash[fd][0] == '\0')
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = ft_substr(stash[fd], 0, ft_strchr(stash[fd], '\n') - stash[fd] + 1);
	if (!line)
		return (NULL);
	stash[fd] = ft_reset_line(stash[fd]);
	return (line);
}
