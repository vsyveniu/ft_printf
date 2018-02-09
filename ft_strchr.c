/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:40:55 by vsyveniu          #+#    #+#             */
/*   Updated: 2017/11/06 13:45:43 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_strchr(const char *str, int symbol)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)symbol)
		{
			return ((char*)&str[i]);
		}
		i++;
	}
	if ((char)symbol == '\0')
	{
		return ((char*)&str[i]);
	}
	return (NULL);
}
