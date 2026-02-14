/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:02:14 by msedeno-          #+#    #+#             */
/*   Updated: 2026/02/12 15:35:26 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unsigned(unsigned int n)
{
	long	num;
	int		count;

	num = n;
	count = 0;
	if (num == 0)
	{
		count += ft_print_char('0');
		return (count);
	}
	if (num > 9)
	{
		count += ft_print_unsigned(num / 10);
		count += ft_print_char((num % 10) + '0');
	}
	else
		count += ft_print_char(num + '0');
	return (count);
}
