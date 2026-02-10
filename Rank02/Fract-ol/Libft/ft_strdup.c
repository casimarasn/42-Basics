/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:11:17 by msedeno-       #  #+#    #+#             */
/*   Updated: 2026/02/10 17:36:46 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*clone;
	size_t	i;
	size_t	slen;

	slen = ft_strlen(s);
	clone = (char *)malloc ((slen + 1) * sizeof(char));
	if (!clone)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		clone[i] = (char)s[i];
		i++;
	}
	clone[i] = '\0';
	return (clone);
}
