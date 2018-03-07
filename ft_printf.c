/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:13:01 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/01/10 14:13:05 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>



void	ft_deepparse(const char *f, int *i, f_list *p)
{
	(*i)++;
	while (f[*i] != '\0')
	{
		if(ft_isflag(f[*i]) == 1)
			p = ft_getflag(f[*i], p);
		if (ft_ismod(f[*i]) == 1)
			p->m = get_mod(f, i);
		if (f[*i] >= '1' && f[*i] <= '9' && f[*i - 1] != '.' && p->w == 0)
		{
			p->w = ft_getwidth(f, i);
			while (ft_isdigit(f[*i]) == 1)
				(*i)++;	
		}
		if (f[*i] == '.')
			ft_parseprec(f, i, p);
		if (ft_isconv(f[*i]) == 1)
		{
			p->c = get_conversion(f, i);
			(*i)++;
			break ;
		}
	(*i)++;	
	}
}


int		ft_parse(const char *f, int *i, va_list args)
{	
	int		ret;
	f_list	*p;


	ret = 0;
	if(!(p = (f_list*)malloc(sizeof(f_list))))
		return (0);
	p->w = 0;
	p->pr = 0;
	p->prc = 0;
	p->m = 0;
	p->crutchmark = 0;
	p->c = 0;
	ft_deepparse(f, i, p);
	ret = printallshit(p, args);
	free(p);
	return(ret);
}


int		printallshit(f_list *p, va_list args)
{
	void *arg;
	int	size;
	int printsize;

	arg = va_arg(args, void *);
	size = ft_getargsize(p, arg); 
	if (p->c == 'c' || p->c == 'C' || p->c == 's'
		|| p->c == 'S')
	{

		ft_handlestr(p, &arg, size);
		printsize = ft_printstrsize(p, arg, size);
		return (printsize);
	}

	ft_deepprint(p, arg, size);
	printsize = ft_printsize(p, size);
	return (printsize);
}	


int		ft_handleshit(const char *f, va_list args)
{
	int			ret;
	int			start;
	int 		i;
	int 		len;

	ret = 0;
	start = 0;
	i = 0;
	len = ft_strlen(f);
	while (f[i] != '\0' && i <= len)
	{
		if (f[i] == '%')
		{	
			ft_putnnnstr(f, start, i);
			ret += ft_parse(f, &i, args);
			start = i;
		}
		else if (f[i] != '\0')
		{
			ret++;
			i++;
		}
	}
	ft_putnnnstr(f, start, len);
	return (ret);
}

int 	ft_printf(const char *format, ... )
{
	va_list		args;
	int			returnvalue;

	va_start(args, format);
	returnvalue = ft_handleshit(format, args);
	va_end(args);	
	return (returnvalue);
}
/*
int		main()
{
	int ret1 = 0;
	int ret = 0;



	printf("\n");


	ret = ft_printf("{%d}", -2147483649);
	printf("\n");
	ret1 = printf("{%d}", -2147483649);
	//ret = ft_printf("a%ob%oc%od", 0, 55555, 100000);
	printf("\n");

	printf("\ncustom -> %d\n", ret);
	printf("\norigin -> %d\n", ret1);


 return (0);	
}	
*/