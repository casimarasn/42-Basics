/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:54:57 by msedeno-       #  #+#    #+#             */
/*   Updated: 2026/02/10 17:36:30 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*a;
	size_t			i;

	i = 0;
	a = s;
	while (i < n)
	{
		a[i] = c;
		i++;
	}
	s = (void *) a;
	return (s);
}
