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

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


void	ft_parse(const char *format, f_list *p, int *index)
{
	(*index) += 1;
	//printf("\nbefore all->  %c\n", format[*index]);
	while (ft_isflag(format[*index]) == 1)
	{
		p = ft_getflag(format, p, index);
		(*index)++;
	}
	//printf("\nafter flags -> %c\n", format[*index]);
	//printf("\nbefore width -> %c\n", format[*index]);
	p->w = ft_getwidth(format, index);
	//printf("w -> %lu\n", p->w);
	//printf("\nafter w -> %c\n", format[*index]);
	//printf("\nbefore precision -> %c\n", format[*index]);
	p->pr = get_precision(format, index);
	//printf("prec -> %lu\n", p->pr);
	//printf("after pr -> %c\n", format[*index]);
	//while (ft_isdigit(format[*index]) == 1)
	//	(*index)++;
	p->justanothershittomanage = get_justanothershittomanage(format, index);
//	printf("justanotheshit -> %s\n", p->justanothershittomanage);
	//printf("\nafter shit -> %c\n", format[*index]);
	p->conversion = get_conversion(format, index);
	//printf("conversion ->    %c\n", p->conversion);
	//printf("\nafter conversion ->  %c\n", p->conversion);
	//printf("\nafter conversion ->  %c\n", format[*index]);
	//if (format[*index] == '%')
	//{
	//(*index)++;
	///if (format[*index] == '%')
	//{
	//	(*index)--;
	//printf("after all ->   %c\n", format[*index]);
	//}
	
	//}
	/*printf("\nafter all ->   %c\n", format[*index]);
	printf("\n--------------------\n");
	printf("\nf_oct   -> %c\n", p->f_oct);
	printf("\nf_plus  -> %c\n", p->f_plus);
	printf("\nf_minus -> %c\n", p->f_minus);
	printf("\nf_zero  -> %c\n", p->f_zero);
	printf("\nw   -> %d\n", p->w);
	printf("\nprec    -> %d\n", p->pr);
	printf("\nmod     -> %s\n", p->justanothershittomanage);
	printf("\nconvers -> %c\n", p->conversion);
	printf("\n--------------------\n");*/
}

int		printallshit(f_list *p, va_list args)
{
	int *arg;
	int	size;
	int printsize;
	int	val;

	val = 0;
	arg = va_arg(args, int *);
	//printf("fuck1\n");
	size = ft_getargsize(p, &arg); ///i have chancge it don't forget to change it back if it neeeded
	//	printf("fuck2\n");
	if (p->conversion == 'c' || p->conversion == 'C' || p->conversion == 's'
		|| p->conversion == 'S')
	{
		size = ft_handlestr(p, &arg, size);
		//printf("pichatest\n");
		printsize = ft_printstrsize(p, size);
		return (printsize);
	}
		//printf("fuck3\n");
	val = ft_checkmodifiers(p);
	//	printf("fuck4\n");
	ft_checkflag(p, &arg, size, val);
	//	printf("fuck5\n");
	printsize = ft_printsize(p, (unsigned long)size);
	//printf("prntsize ->   %d\n", printsize);
	return (printsize);
}	

int		ft_handleshit(const char *format, va_list args)
{
	int 		ret;
	int			i;
	f_list		*p;

	i = -1;
	if (!format)
		return (-1);
	ret = 0;
	//printf("\n%s\n",format);
	while (format[++i] != '\0')
	{
		//printf("\ni in while -> %d\n", i);
		if (format[i] == '%')
		{
			if(!(p = (f_list*)malloc(sizeof(f_list))))
				return (0);
			//printf("\nbrfore iteration ->  %c\n", format[i]);
			//i++;
			//printf("\nafter iteration ->  %c\n", format[i]);
			ft_parse(format, p, &i);
			//printf("\nafter ft_parse ->   %c\n", format[i]);
			if (format[i] == '%')
					i--;
			if (p->conversion != 0)
			{
				ret += printallshit(p, args);
			}
			p = NULL;
			free(p);
		//	printf("after parse-> %c\n", format[i]);
		}
		//printf("format i -> %d    ", i);
	//printf("\n%c\n",  format[i]);
	//printf("%c", format[i]);
	//ret++;	
	if (ft_checkispossibletoputthisbitchinchar(format, i) == 1)
	{
		ft_putchar(format[i]);
		ret++;
	}
	//printf("after parse-> %d\n", format[i + 1]);
	}
	
	return (ret);
}


int		ft_checkispossibletoputthisbitchinchar(const char *format, int i)
{
	//printf("\nformat ->  %c\n", format[i]);
	if (format[i - 1] != '%'){
		return (1);
	}
	if (format[i - 1] == '%' && format[i - 2] == '%')
		return (1);
	if (format[i - 1] == '%' && format[i + 1] == '\0')
		return (1);
	return (0);
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
	int ret;
	int	ret1;
	int test1;
	char test3;
	char *test;
	char *test2;
	test1 = 23242;
	test = "1234567890";
	test2 = "fu";
	test3 = 'l';

	printf("\n");
	printf("\n");

	ret = ft_printf("|%d %d|", 42, 42);
	ft_printf("\n|%d %d|\n", sizeof(42), sizeof(42));
	//ret = ft_printf("|%042d %s|", 42, "suck");
	printf("\n");
	ret1 = printf("|%d %d|", 42, 42);
	printf("\n|%d %d|\n", sizeof(42), sizeof(42));

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


//////////////test/////////


	printf("\n");
	printf("-----------  %s  -----------\n", "%%");
	printf("\n");

	ret = ft_printf("|%%|");
	printf("\n");
	ret1 = printf("|%%|");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s  -----------\n", "%5%");
	printf("\n");

	ret = ft_printf("|%5%|");
	printf("\n");
	ret1 = printf("|%5%|");

	printf("\n");
	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s  -----------\n", "%-5%");
	printf("\n");

	ret = ft_printf("|%-5%|");
	printf("\n");
	ret1 = printf("|%-5%|");

	printf("\n");
	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s  -----------\n", "%.0%");
	printf("\n");

	ret = ft_printf("|%.0%|");
	printf("\n");
	ret1 = printf("|%.0%|");

	printf("\n");
	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s  -----------\n", "%   %");
	printf("\n");

	ret = ft_printf("|%   %|", "test");
	printf("\n");
	ret1 = printf("|%   %|", "test");

	printf("\n");
	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s  -----------\n", "%x");
	printf("\n");

	ret = ft_printf("|%x|", 42);
	printf("\n");
	ret1 = printf("|%x|", 42);

	printf("\n");
	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s  -----------\n", "%X");
	printf("\n");

	ret = ft_printf("|%X|", 42);
	//ret = ft_printf("|%s%s|", "e", "t");
	printf("\n");
	ret1 = printf("|%X|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


 return (0);	
}
*/