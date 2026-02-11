/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexdecmi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:50:07 by msedeno-          #+#    #+#             */
/*   Updated: 2026/02/06 18:54:57 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexdecmi(unsigned long long int n)
{
	int	count;
	int	i;

	count = 0;
	if (n >= 16)
		count += ft_print_hexdecmi(n / 16);
	i = n % 16;
	count += ft_print_char("0123456789abcdef"[i]);
	return (count);
}
