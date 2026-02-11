/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:47:23 by msedeno-       #  #+#    #+#             */
/*   Updated: 2026/02/10 17:35:35 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static int	ft_countdigit(int num)
{
	int	result;

	result = 0;
	if (num <= 0)
		result++;
	while (num != 0)
	{
		num /= 10;
		result++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*result;

	len = ft_countdigit(n);
	result = (char *)malloc (sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (n == 0)
		result[0] = '0';
	sign = 1;
	if (n < 0)
	{
		result[0] = '-';
		sign = -1;
	}
	while (n != 0)
	{
		len--;
		result [len] = (n % 10) * sign + '0';
		n /= 10;
	}
	return (result);
}
