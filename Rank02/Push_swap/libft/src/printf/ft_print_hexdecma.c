/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexdecma.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:38:32 by msedeno-          #+#    #+#             */
/*   Updated: 2026/02/12 15:38:38 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hexdecma(unsigned long long n)
{
	int		count;
	int		i;
	char	*str;

	str = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_print_hexdecma(n / 16);
	i = n % 16;
	count += ft_print_char(str[i]);
	return (count);
}
