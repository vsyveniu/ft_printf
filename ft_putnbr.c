/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:03:37 by vsyveniu          #+#    #+#             */
/*   Updated: 2017/11/06 13:42:14 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_putnbr(f_list *p, intmax_t n)
{
	intmax_t	i;

	i = (intmax_t)n;
	if (n == 0 && p->prcrutch)
		return ;
	if (n < 0)
	{
		i = (intmax_t)(-n);
		ft_putchar('-');
	}
	if (i > 9)
	{
		ft_putnbr(p, i / 10);
		ft_putnbr(p, i % 10);
	}
	else
	{
		ft_putchar(i + '0');
	}
}
