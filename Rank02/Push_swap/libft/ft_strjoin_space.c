/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:45:15 by casimarasn        #+#    #+#             */
/*   Updated: 2025/10/13 20:45:35 by casimarasn       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_space(char const *s1, char const *s2)
{
	char	*s;
	size_t	len1;
	size_t	len2;
	size_t	tlen;

	len1 = ft_strlen (s1);
	len2 = ft_strlen (s2);
	tlen = len1 + 1 + len2 + 1;
	s = (char *)malloc(tlen);
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, len1 + 1);
	s[len1] = ' ';
	s[len1 + 1] = '\0';
	ft_strlcat(s, s2, tlen);
	return (s);
}
