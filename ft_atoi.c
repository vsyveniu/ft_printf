/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:21:37 by vsyveniu          #+#    #+#             */
/*   Updated: 2017/11/06 10:23:34 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static	int		ft_isspace(const char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' ||
		c == '\v' || c == '\f')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int				ft_atoi(const char *str)
{
	long			i;
	unsigned long	r;
	long			sign;

	i = 0;
	r = 0;
	sign = 1;
	while (*str != '\0' && ft_isspace(str[i]))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
	{
		r = r * 10 + (str[i] - 48);
		i++;
	}
	if (r > 9223372036854775807 && sign < 0)
		return (0);
	if (r > 9223372036854775807)
		return (-1);
	return (r * sign);
}
