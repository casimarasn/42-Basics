/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexdecma.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:02:11 by msedeno-          #+#    #+#             */
/*   Updated: 2026/02/06 18:56:44 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexdecma(unsigned long long n)
{
	int	count;
	int	i;

	count = 0;
	if (n >= 16)
		count += ft_print_hexdecma(n / 16);
	i = n % 16;
	count += ft_print_char("0123456789ABCDEF"[i]);
	return (count);
}
