/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:31:03 by msedeno-          #+#    #+#             */
/*   Updated: 2026/02/12 15:40:18 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*copy;

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
	ft_strlcpy(copy, s + start, len + 1);
	return (copy);
}
