/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:39:06 by msedeno-          #+#    #+#             */
/*   Updated: 2026/02/12 15:39:12 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_nbr(int n)
{
	long int	num;
	int			count;

	num = n;
	count = 0;
	if (num < 0)
	{
		count += ft_print_char('-');
		num = -num;
	}
	if (num > 9)
	{
		count += ft_print_nbr(num / 10);
		count += ft_print_char((num % 10) + '0');
	}
	else
		count += ft_print_char(num + '0');
	return (count);
}
