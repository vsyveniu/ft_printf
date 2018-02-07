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
	void *arg;
	int	size;
	int printsize;
	int	val;

	val = 0;
	arg = va_arg(args, void *);
	if(arg != NULL)
		size = ft_getargsize(p, &arg); ///i have chancge it don't forget to change it back if it neeeded
	//	printf("fuck2\n");
	//printf("picha\n");
	if (p->conversion == 'c' || p->conversion == 'C' || p->conversion == 's'
		|| p->conversion == 'S')
	{
		size = ft_handlestr(p, &arg, size);
	//		printf("pichatest\n");
		printsize = ft_printstrsize(p, size);
		return (printsize);
	}
		//printf("fuck3\n");
	val = ft_checkmodifiers(p);
	//	printf("fuck4\n");
	size = ft_checkflag(p, arg, size, val);
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
	int len;

	i = -1;
	if (!format)
		return (-1);
	len = ft_strlen(format);	
	ret = 0;
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			if(!(p = (f_list*)malloc(sizeof(f_list))))
				return (0);
			ft_parse(format, p, &i);
			if (format[i] == '%')
					i--;
			if (p->conversion != 0)
			{
				ret += printallshit(p, args);
			}
			p = NULL;
			free(p);
		}
	if (ft_checkispossibletoputthisbitchinchar(format, i) == 1 && i < len)
	{
		if(format != 0)
		{
			ft_putchar(format[i]);
			ret++;
		}
	}
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
	int ret1;
	int ret;


	printf("\n");
	printf("\n");

	ret = ft_printf("|%s %s %s %c %d|", "suck ", "fuck ", "picha ", 'f', 42);
	//ft_printf("\n|%d %d|\n", sizeof(42), sizeof(42));
	//ret = ft_printf("|%042d %s|", 42, "suck");
	printf("\n");
	ret1 = printf("|%s %s %s %c %d|", "suck ", "fuck ", "picha ", 'f', 42);
	//ret1 = printf("|%d|", 2147483647);
	//printf("\n|%d %d|\n", sizeof(42), sizeof(42));

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


//////////////test %%%%%%%%%%/////////


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




	printf("\n");
	printf("-----------  %s  -----------\n", "abc");
	printf("\n");

	ret = ft_printf("|%s|", "abc");
	printf("\n");
	ret1 = printf("|%s|", "abc");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s  -----------\n", "this is a string");
	printf("\n");

	ret = ft_printf("|%s|", "this is a string");
	printf("\n");
	ret1 = printf("|%s|", "this is a string");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s  -----------\n", "n");
	printf("\n");

	ret = ft_printf("|Line Feed %s|", "\\n");
	printf("\n");
	ret1 = printf("|Line Feed %s|", "\\n");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s  -----------\n", ".2s");
	printf("\n");

	ret = ft_printf("|%.2s is a string|", "");
	printf("\n");
	ret1 = printf("|%.2s is a string|", "");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s  -----------\n", "-.2s");
	printf("\n");

	ret = ft_printf("|%-.2s is a string|", "this");
	printf("\n");
	ret1 = printf("|%-.2s is a string|", "this");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s  -----------\n", "-5.2s");
	printf("\n");

	ret = ft_printf("|%-5.2s is a string|", "");
	printf("\n");
	ret1 = printf("|%-5.2s is a string|", "");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------   %s  -----------\n", "double s");
	printf("\n");

	ret = ft_printf("|%s %s|", "this", "is");
	printf("\n");
	ret1 = printf("|%s %s|", "this", "is");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s  -----------\n", "triple s");
	printf("\n");

	ret = ft_printf("|%s %s %s|", "this", "is", "a");
	printf("\n");
	ret1 = printf("|%s %s %s|", "this", "is", "a");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s  -----------\n", "multi s");
	printf("\n");

	ret = ft_printf("|%s %s %s %s|", "this", "is", "a", "multi");
	printf("\n");
	ret1 = printf("|%s %s %s %s|", "this", "is", "a", "multi");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s -----------\n", "multifuck s");
	printf("\n");

	ret = ft_printf("|%s%s%s%s|", "this", "is", "a", "multi");
	printf("\n");
	ret1 = printf("|%s%s%s%s|", "this", "is", "a", "multi");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s 	-----------\n", "null");
	printf("\n");

	ret = ft_printf("|@moulitest: %s|", NULL);
	printf("\n");
	ret1 = printf("|@moulitest: %s|", NULL);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	
	printf("\n");
	printf("-----------  %s 	-----------\n", "this");
	printf("\n");

	ret = ft_printf("|%10s is a string|", "this");
	printf("\n");
	ret1 = printf("|%10s is a string|", "this");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "5.2");
	printf("\n");

	ret = ft_printf("|%5.2s is a string|", "this");
	printf("\n");
	ret1 = printf("|%5.2s is a string|", "this");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "-5.2");
	printf("\n");

	ret = ft_printf("|%-5.2s is a string|", "this");
	printf("\n");
	ret1 = printf("|%-5.2s is a string|", "this");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "-5.2");
	printf("\n");

	ret = ft_printf("|%-5.2s is a string|", "");
	printf("\n");
	ret1 = printf("|%-5.2s is a string|", "");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s 	-----------\n", "-5.2");
	printf("\n");

	
	printf("\n");
	printf("-----------  %s 	-----------\n", "-5.2");
	printf("\n");

	ret = ft_printf("|%-5.2s is a string|", "this");
	printf("\n");
	ret1 = printf("|%-5.2s is a string|", "this");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "5");
	printf("\n");

	ret = ft_printf("|%-5c|", 42);
	printf("\n");
	ret1 = printf("|%-5c|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "d");
	printf("\n");

	ret = ft_printf("|%d|", -1);
	printf("\n");
	ret1 = printf("|%d|", -1);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "d");
	printf("\n");

	ret = ft_printf("|%d|", 4254);
	printf("\n");
	ret1 = printf("|%d|", 4254);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);
 return (0);	
}	
*/