/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:38:27 by vsyveniu          #+#    #+#             */
/*   Updated: 2017/11/02 16:30:00 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*str;

	len = ft_strlen(src);
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
	{
		return (NULL);
	}
	else
	{
		i = 0;
		while (i < len)
		{
			str[i] = src[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
}
