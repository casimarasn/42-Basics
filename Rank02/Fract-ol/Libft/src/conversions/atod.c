/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:28:11 by casimarasn        #+#    #+#             */
/*   Updated: 2026/02/14 14:28:09 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*skip_ws_sign(const char *s, int *sign)
{
	*sign = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == 0)
	{
		ft_putstr_fd("err:wrong type of number\n", 2);
		exit(EXIT_FAILURE);
	}
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			*sign = -1;
		s++;
	}
	return (s);
}

static double	parse_fraction(const char *s, t_atod *atod)
{
	atod->frac = 0.0;
	atod->base = 1.0;
	if (*s != '.')
		return (0.0);
	s++;
	while (ft_isdigit(*s))
	{
		atod->frac = atod->frac * 10.0 + (*s - '0');
		atod->base *= 10.0;
		s++;
	}
	return (atod->frac / atod->base);
}

double	ft_atod(const char *s, t_atod *atod)
{
	int	sign;

	sign = 1;
	atod->val = 0.0;
	atod->frac = 0.0;
	atod->point = 0;
	if (!s)
		return (0.0);
	atod->paki = skip_ws_sign(s, &sign);
	while (ft_isdigit(*atod->paki))
		atod->val = atod->val * 10.0 + (*atod->paki++ - '0');
	if (*atod->paki == '.')
	{
		atod->frac = parse_fraction(atod->paki, atod);
		atod->point = 1;
	}
	while ((*atod->paki == '.' && atod->point == 1) || ft_isdigit(*atod->paki))
		atod->paki++;
	if (*atod->paki != '\0')
	{
		ft_putstr_fd("err:wrong type of number\n", 2);
		exit (EXIT_FAILURE);
	}
	return (sign * (atod->val + atod->frac));
}
