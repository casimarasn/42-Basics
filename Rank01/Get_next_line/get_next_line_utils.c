/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:48:47 by msedeno-          #+#    #+#             */
/*   Updated: 2025/06/07 18:11:04 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *s1)
{
	char			*clone;
	unsigned int	i;

	clone = (char *) malloc(ft_strlen(s1) + 1);
	if (!clone)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		clone[i] = s1[i];
		i++;
	}
	clone[i] = '\0';
	return (clone);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*copy;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen (s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	copy = (char *) malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s [start + i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*res;

	res = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free (s1);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
