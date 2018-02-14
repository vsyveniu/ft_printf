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


/*void 	ft_postparse(char *format, char *crutch, char *crutchpr, f_list *p)
{
	int i;

	i = 0;
	p->mod = 0;
	p->pr = 0;
	p->w = 0;
	while(format[i++] != '\0')
	{
		while (ft_isflag(format[i]) == 1)
		{
			p = ft_getflag(format[i], p);
			i++;
		}
		if(format[i] == 'h' || format[i] == 'l' || format[i] == 'j'
			|| format[i] == 'z')
		{
			p->mod = get_mod(format, i); 
		}
		if (format[i] >= '0' && format[i] <= '9' && format[i - 1] != '.')
			p->w = ft_atoi(crutch);
		if (format[i] == '.' && format[i + 1] >= '0' && format[i + 1] <= '9')
			p->pr = ft_atoi(crutchpr);
		if (ft_isconv(format[i]) == 1)
			p->conversion = get_conversion(format[i]);
	}
}

char 	*ft_parsecrutchw(char *temp)
{
	int i;
	int k;2
	int j;
	char *temp2;

	i = 0;
	j = 0;
	k = 0;
	while (temp[i++] != '\0')
	{
		if (temp[i] >= '1' && temp[i] <= '9')
		{
			j = i;
			break ;
		}
	}
	while ( temp[i] != '\0' && temp[i] >= '0' && temp[i] <= '9')
		i++;

	temp2 = ft_strsub(temp, j, i - j);
 return(temp2);
}


char 	*ft_parsecrutchpr(char *temp)
{
	int i;
	int k;
	int j;
	char *temp2;

	i = 0;
	j = 0;
	k = 0;
	while (temp[i++] != '\0')
	{
		if (temp[i] == '.')
		{
			i += 1;
			j = i;
			break ;
		}
	}
	while (temp[i] != '\0' && temp[i] >= '0' && temp[i] <= '9')
		i++;

	temp2 = ft_strsub(temp, j, i - j);
 return(temp2);
}
*/

int		ft_parse(char *f, int *i, va_list args)
{	
	int ret;
	f_list	*p;

	ret = 0;


	if(!(p = (f_list*)malloc(sizeof(f_list))))
		return (0);
	p->w = 0;
	p->pr = 0;
	p->mod = 0;


	//ret = printallshit(p, args);
	/*int t;
	int j;
	int ret;
	char *temp;
	char *crutchw;
	char *crutchpr;

	t = (*(int*)i);
	j = 0;
	//printf("\n%d\n", t);
	while (format[t++] != '\0')
	{
		if (ft_isconv(format[t]) == 1)
			break ;
	}
	temp = ft_strsub(format, (*(int*)i), (t + 1) - (*(int*)i));
	//printf("\n----------%s-----------   \n", temp);
	//printf("\n%d\n", t);
	//ret = (t) - (*(int*)i);
	ret = t;
	crutchw = ft_parsecrutchw(temp);
	crutchpr = ft_parsecrutchpr(temp);
	ft_postparse(temp,crutchw, crutchpr, p);
	//temp = NULL;
	free(temp);
//	printf("\n------------------------------->>>>>>>>>>> %s\n", temp);
	//temp = ft_strsub()
	//printf("-------->>>>>>>>>pichaaa!\n");
	//printf("-------->>>>>>>>> format %s\n", format);
	//printf("|||||||||||%d\n", (*(int*)i));
	//while (format[i] != '\0')
	//{
		//while (ft_isconv)
//	i++;
//	}*/
	//printf("\nbefore all->  %c\n", f[*i]);
	//write(1, "fuck", 4);
	(*i)++;
	while (f[*i] != '\0')
	{
		//printf("------------------->>>>>>>>>>>>>>>>  %c\n", f[*i]);
		if(ft_isflag(f[*i]) == 1)
			p = ft_getflag(f[*i], p);
		if (ft_ismod(f[*i]) == 1)
			p->mod = get_mod(f, i);
		if (f[*i] >= '1' && f[*i] <= '9' && f[*i - 1] != '.' && p->w == 0)
		{
			p->w = ft_getwidth(f, i);
			while (ft_isdigit(f[*i]) == 1)
				(*i)++;
			
		}
		if (f[*i] == '.' && ft_isdigit(f[*i + 1]) == 1)
		{
			(*i)++;
			//printf("--------------->>>>>>>>>> %c\n", f[*i]);
			p->pr = get_precision(f, i);
			while (ft_isdigit(f[*i]) == 1)
				(*i)++;
		}
		if (ft_isconv(f[*i]) == 1)
		{
			p->conversion = get_conversion(f, i);
			break ;
		}
		(*i)++;	
	}
	ret = printallshit(p, args);
	/*while (ft_isflag(f[*i]) == 1)
	{
		p = ft_getflag(f[*i], p);
		(*i)++;
	}
	
		
		if (f[*i] == 'h' )
		{
			p->mod = get_mod(f, i);
		}
		if (ft_isdigit(f[*i]) == 1 && f[*i - 1] != '.')
		{
			p->w = ft_getwidth(f, i);
		}
		if (f[*i] == '.' && ft_isdigit(f[*i + 1]) == 1)
		{
			p->pr = get_precision(f, i);
		}
		if (ft_isconv(f[*i]) == 1)
		{
			p->conversion = get_conversion(f, i);
		}*/
	//printf("-------------->>>>>> %c\n", f[*i]);
	//printf("\nafter flags -> %c\n", format[*index]);
	//printf("\nbefore width -> %c\n", format[*index]);
	//p->w = ft_getwidth(f, i);
	//printf("w -> %lu\n", p->w);
	//printf("\nafter w -> %c\n", format[*index]);
	//printf("\nbefore precision -> %c\n", format[*index]);
	//p->pr = get_precision(f, i);
	//printf("------------>>>>>>>> %c\n", format[*index]);
	//printf("prec -> %lu\n", p->pr);
	//printf("after pr -> %c\n", format[*index]);
	//while (ft_isdigit(format[*index]) == 1)
	//	(*index)++;
//	p->mod = get_mod(format, i);
//	printf("justanotheshit -> %s\n", p->mod);
	//printf("\nafter shit -> %c\n", format[*index]);
	//p->conversion = get_conversion(f, i);/*
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
	//printf("\nafter all ->   %c\n", format[*index]);

	//(*index)++;
	//printf("----------->>>%c\n", format[*index]);
	/*if (ft_isconv(format[*index] == 0))
	{
		printf("----------||||||||||||||||||picha\n");
			p = ft_getflag(format, p, index);
			if ((format[*index] >= 0 && format[*index] <= 9) && format[*index - 1] != '.')
				p->w = ft_getwidth(format, index);
			if (format[*index] == '.')
			{
				//(*index)++;
				p->pr = get_precision(format, index);
			}
			if (ft_ismod(format[*index]) == 1 && p->mod == 0)
				p->mod = get_mod(format, index);
		//	(*index)++;
	}
	 if (ft_isconv(format[*index]) == 1)
		{
			p->conversion = get_conversion(format, index);
			//(*index)++;
		}
	printf("------------>>>>>>> fff %c\n", format[*index]);
	//(*index)++;
		//printf("\nconvers -> %c\n", p->conversion);
	*/	
		/*printf("\n--------------------\n");
	printf("\nf_oct   -> %c\n", p->f_oct);
	printf("\nf_plus  -> %c\n", p->f_plus);
	printf("\nf_minus -> %c\n", p->f_minus);
	printf("\nf_zero  -> %c\n", p->f_zero);
	printf("\nw   -> %d\n", p->w);
	printf("\nprec    -> %d\n", p->pr);
	printf("\nmod     -> %d\n", p->mod);
	printf("\nconvers -> %c\n", p->conversion);
	printf("\n--------------------\n");
	//printf("\nconvers -> %c\n", p->conversion);*/
	//printf("\nret in parse--------------->>>>>>>>>> %d\n", ret);*/



	return(ret - 1);
}

int		ft_ismod(char c)
{
	if (c == 'h' || c == 'l' || c == 'z'
		|| c == 'j')
	{
		return (1);
	}

	return (0);	
}


int		ft_isconv(char c)
{
	if (c == 's' || c == 'S' || c == 'd' 
		|| c == 'd' || c == 'D' || c == 'i'
		|| c == 'o' || c == 'O' || c == 'u'
		|| c == 'U' || c == 'x' || c == 'X'
		|| c == 'c' || c == 'C' || c == 'b'
		|| c == 'r' || c == 'k' || c == 'f'
		|| c == '%' || c == 'p'){
		return(1);
	}
	else
		return(0);
}


int		printallshit(f_list *p, va_list args)
{
	void *arg;
	int	size;
	int printsize;

	arg = va_arg(args, void *);
	size = ft_getargsize(p, arg); ///i have chancge it don't forget to change it back if it neeeded
	//	printf("fuck2\n");
	//printf("picha\n");
	//printf("\nsiex in allshit ------------+++++++++= %d\n", size);
	if (p->conversion == 'c' || p->conversion == 'C' || p->conversion == 's'
		|| p->conversion == 'S')
	{

		ft_handlestr(p, &arg, size);
	//		printf("pichatest\n");
		printsize = ft_printstrsize(p, arg, size);
		return (printsize);
	}
		//printf("fuck3\n");
	//val = ft_checkmodifiers(p);
	//	printf("fuck4\n");
	ft_checkflag(p, arg, size);
	//	printf("fuck5\n");
	//printf("\nsiex in allshit ------------+++++++++= %d\n", size);
	printsize = ft_printsize(p,arg,size);
	//printf("\nsiex in allshit ------------+++++++++= %d\n", printsize);
	//printf("prntsize ->   %d\n", printsize);
	return (printsize);
}	

void	ft_putnnstr(char *str, int start)
{
	while (str[start] != '\0')
	{
		ft_putchar(str[start]);
		start++;
	}
}

void	ft_putnnnstr(char *str, int start, int end)
{
	while(start < end)
	{
		ft_putchar(str[start]);
		start++;
	}
}

int		ft_handleshit(const char *format, va_list args)
{
	int			ret;
	int			start;
	int 		i;
	char 		*f;
	int 		len;

	ret = 0;
	f = (char*)format;
	start = 0;
	i = 0;
	len = ft_strlen(format);
	while (f[i] != '\0' && i <= len)
	{
		if (f[i] == '%')
		{	
			ft_putnnnstr(f, start, i);
			ret += ft_parse(f, &i, args);
			start = i + 1;
		}
		else if (f[i] != '\0' && i <= len)
		{
			ret++;
			i++;
		}	
	}
	ft_putnnnstr(f, start, len);
	return (ret);
}

/*int		ft_isitpossible(const char *format, int i)
{
	while(format[i] != '%')
	{
		if(format[i])
	i--;	
	}

	return(1);
}*/


int		ft_checkispossibletoputthisbitchinchar(const char *format, int i)
{
	if (format[i - 1] != '%')
		return (1);
	if (format[i - 1] == '%' && format[i - 2] == '%')
		return (1);
	//if (format[i - 1] == '%' && format[i + 1] == '\0')
	//	return (1);
	//if (format[i - 1] == '%' && ft_isconv(format[i]) == 1)
	//	return (0);
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

	ret = ft_printf("|%u|", 4294967296);
	printf("\n");
	ret1 = printf("|%u|",   4294967296);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "5u");
	printf("\n");

	ret = ft_printf("|%5u|", 4294967295);
	printf("\n");
	ret1 = printf("|%5u|",   4294967295);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "15u");
	printf("\n");

	ret = ft_printf("|%15u|", 4294967295);
	printf("\n");
	ret1 = printf("|%15u|",   4294967295);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s 	-----------\n", "d");
	printf("\n");

	ret = ft_printf("|%-15u|", 4294967295);
	printf("\n");
	ret1 = printf("|%-15u|",   4294967295);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s 	-----------\n", "d");
	printf("\n");

	ret = ft_printf("|%015u|", 4294967295);
	printf("\n");
	ret1 = printf("|%015u|",   4294967295);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s 	-----------\n", " u");
	printf("\n");

	ret = ft_printf("|% u|", 4294967295);
	printf("\n");
	ret1 = printf("|% u|",   4294967295);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "lu");
	printf("\n");

	ret = ft_printf("|%lu|", 4294967296);
	printf("\n");
	ret1 = printf("|%lu|",   4294967296);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s 	-----------\n", "ju");
	printf("\n");

	ret = ft_printf("|%ju|", 4999999999);
	printf("\n");
	ret1 = printf("|%ju|",   4999999999);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s 	-----------\n", "ju");
	printf("\n");

	ret = ft_printf("|%ju|", 4294967296);
	printf("\n");
	ret1 = printf("|%ju|",   4294967296);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s 	-----------\n", "hu");
	printf("\n");

	ret = ft_printf("|%hU|", 4294967296);
	printf("\n");
	ret1 = printf("|%hU|",   4294967296);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "hu");
	printf("\n");

	ret = ft_printf("|@moulitest: %#.x %#.0x|", 0, 0);
	printf("\n");
	ret1 = printf("|@moulitest: %#.x %#.0x|", 0, 0);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "hu");
	printf("\n");

	ret = ft_printf("|%.x|", 0);
	printf("\n");
	ret1 = printf("|%.x|", 0);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "010x");
	printf("\n");

	ret = ft_printf("|%d|", -1);
	printf("\n");
	ret1 = printf("|%d|", -1);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);




	printf("\n");
	printf("-----------  %s 	-----------\n", "010x");
	printf("\n");

	ret = ft_printf("|%d|", -4242);
	printf("\n");
	ret1 = printf("|%d|", -4242);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);




	printf("\n");
	printf("-----------  %s 	-----------\n", "010x");
	printf("\n");

	ret = ft_printf("|%d|", 42);
	printf("\n");
	ret1 = printf("|%d|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "010x");
	printf("\n");

	ret = ft_printf("|%+d|", 42);
	printf("\n");
	ret1 = printf("|%+d|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "010x");
	printf("\n");

	ret = ft_printf("|%+d|", 0);
	printf("\n");
	ret1 = printf("|%+d|", 0);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "010x");
	printf("\n");

	ret = ft_printf("|% +d|", 42);
	printf("\n");
	ret1 = printf("|% +d|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s 	-----------\n", "010x");
	printf("\n");

	ret = ft_printf("|%+ d|", 42);
	printf("\n");
	ret1 = printf("|%+ d|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "010x");
	printf("\n");

	ret = ft_printf("|% +d|", -42);
	printf("\n");
	ret1 = printf("|% +d|", -42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s 	-----------\n", "010x");
	printf("\n");

	ret = ft_printf("|% ++d|", 42);
	printf("\n");
	ret1 = printf("|% ++d|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "010x");
	printf("\n");

	ret = ft_printf("|% ++d|", -42);
	printf("\n");
	ret1 = printf("|% ++d|", -42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s 	-----------\n", "++ d");
	printf("\n");

	ret = ft_printf("|%++ d|", 42);
	printf("\n");
	ret1 = printf("|%++ d|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "++ d");
	printf("\n");

	ret = ft_printf("|%++ d|", -42);
	printf("\n");
	ret1 = printf("|%++ d|", -42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "0d");
	printf("\n");

	ret = ft_printf("|%0d|", -42);
	printf("\n");
	ret1 = printf("|%0d|", -42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "00d");
	printf("\n");

	ret = ft_printf("|%00d|", -42);
	printf("\n");
	ret1 = printf("|%00d|", -42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "05d");
	printf("\n");

	ret = ft_printf("|%05d|", -42);
	printf("\n");
	ret1 = printf("|%05d|", -42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "05d");
	printf("\n");

	ret = ft_printf("|%05d|", 42);
	printf("\n");
	ret1 = printf("|%05d|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "0+5d");
	printf("\n");

	ret = ft_printf("|%0+5d|", 42);
	printf("\n");
	ret1 = printf("|%0+5d|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "0+5d");
	printf("\n");

	ret = ft_printf("|%0+5d|", -42);
	printf("\n");
	ret1 = printf("|%0+5d|", -42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "5d");
	printf("\n");

	ret = ft_printf("|%5d|", 42);
	printf("\n");
	ret1 = printf("|%5d|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);




	printf("\n");
	printf("-----------  %s 	-----------\n", "05d");
	printf("\n");

	ret = ft_printf("|%05d|", -42);
	printf("\n");
	ret1 = printf("|%05d|", -42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


		printf("\n");
	printf("-----------  %s 	-----------\n", "0+5d");
	printf("\n");

	ret = ft_printf("|%0+5d|", -42);
	printf("\n");
	ret1 = printf("|%0+5d|", -42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


		printf("\n");
	printf("-----------  %s 	-----------\n", "-05d");
	printf("\n");

	ret = ft_printf("|%-05d|", 42);
	printf("\n");
	ret1 = printf("|%-05d|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


		printf("\n");
	printf("-----------  %s 	-----------\n", "-5d");
	printf("\n");

	ret = ft_printf("|%-5d|", -42);
	printf("\n");
	ret1 = printf("|%-5d|", -42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);




		printf("\n");
	printf("-----------  %s 	-----------\n", "-05d");
	printf("\n");

	ret = ft_printf("|%-05d|", -42);
	printf("\n");
	ret1 = printf("|%-05d|", -42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



		printf("\n");
	printf("-----------  %s 	-----------\n", "hd");
	printf("\n");

	ret = ft_printf("|%hd|", 32768);
	printf("\n");
	ret1 = printf("|%hd|", 32768);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);




		printf("\n");
	printf("-----------  %s 	-----------\n", "hhd");
	printf("\n");

	ret = ft_printf("|%hhd|", 128);
	printf("\n");
	ret1 = printf("|%hhd|", 128);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


		printf("\n");
	printf("-----------  %s 	-----------\n", "ld");
	printf("\n");

	ret = ft_printf("|%ld|", -2147483648);
	printf("\n");
	ret1 = printf("|%ld|", -2147483648);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



		printf("\n");
	printf("-----------  %s 	-----------\n", "x");
	printf("\n");

	ret = ft_printf("|%x|", -42);
	printf("\n");
	ret1 = printf("|%x|", -42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


		printf("\n");
	printf("-----------  %s 	-----------\n", "-10x");
	printf("\n");

	ret = ft_printf("|%-10x|", -42);
	printf("\n");
	ret1 = printf("|%-10x|", -42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



		printf("\n");
	printf("-----------  %s 	-----------\n", "-10x");
	printf("\n");

	ret = ft_printf("|%d|", -2147483648);
	printf("\n");
	ret1 = printf("|%d|", -2147483648);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", " d");
	printf("\n");

	ret = ft_printf("|% d|", 42);
	printf("\n");
	ret1 = printf("|% d|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "%d %d");
	printf("\n");

	ret = ft_printf("|%d %d|", 1, -2);
	printf("\n");
	ret1 = printf("|%d %d|", 1, -2);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "%d");
	printf("\n");

	ret = ft_printf("|%d|", -1);
	printf("\n");
	ret1 = printf("|%d|", -1);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);




	printf("\n");
	printf("-----------  %s 	-----------\n", "%d");
	printf("\n");

	ret = ft_printf("|%d|", -4242);
	printf("\n");
	ret1 = printf("|%d|", -4242);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);




	printf("\n");
	printf("-----------  %s 	-----------\n", "% d");
	printf("\n");

	ret = ft_printf("|% d|", -42);
	printf("\n");
	ret1 = printf("|% d|", -42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "%+d");
	printf("\n");

	ret = ft_printf("|%+d|", 0);
	printf("\n");
	ret1 = printf("|%+d|", 0);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "%5d");
	printf("\n");

	ret = ft_printf("|%5d|", -42);
	printf("\n");
	ret1 = printf("|%5d|", -42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "%0+5d");
	printf("\n");

	ret = ft_printf("|%0+5d|", -42);
	printf("\n");
	ret1 = printf("|%0+5d|", -42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);




	printf("\n");
	printf("-----------  %s 	-----------\n", "%-5d");
	printf("\n");

	ret = ft_printf("|%-5d|", -42);
	printf("\n");
	ret1 = printf("|%-5d|", -42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



		printf("\n");
	printf("-----------  %s 	-----------\n", "%5d");
	printf("\n");

	ret = ft_printf("|%5d|", 42);
	printf("\n");
	ret1 = printf("|%5d|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "%10X");
	printf("\n");

	ret = ft_printf("|%10X|", -42);
	printf("\n");
	ret1 = printf("|%10X|", -42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "%5.2X");
	printf("\n");

	ret = ft_printf("|%5.2X|", 5427);
	printf("\n");
	ret1 = printf("|%5.2X|", 5427);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


		printf("\n");
	printf("-----------  %s 	-----------\n", "%#ll");
	printf("\n");

	ret = ft_printf("|%#llx|", 9223372036854775807);
	printf("\n");
	ret1 = printf("|%#llx|", 9223372036854775807);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



		printf("\n");
	printf("-----------  %s 	-----------\n", "%#");
	printf("\n");

	ret = ft_printf("|%#x|", 0);
	printf("\n");
	ret1 = printf("|%#x|", 0);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



		printf("\n");
	printf("-----------  %s 	-----------\n", "%#8");
	printf("\n");

	ret = ft_printf("|%#8x|", 0);
	printf("\n");
	ret1 = printf("|%#8x|", 0);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



		printf("\n");
	printf("-----------  %s 	-----------\n", "%#8");
	printf("\n");

	ret = ft_printf("|%#8x|", 42);
	printf("\n");
	ret1 = printf("|%#8x|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


			printf("\n");
	printf("-----------  %s 	-----------\n", "%#08");
	printf("\n");

	ret = ft_printf("|%#08x|", 42);
	printf("\n");
	ret1 = printf("|%#08x|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


			printf("\n");
	printf("-----------  %s 	-----------\n", "%#-08");
	printf("\n");

	ret = ft_printf("|%#-08x|", 42);
	printf("\n");
	ret1 = printf("|%#-08x|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



			printf("\n");
	printf("-----------  %s 	-----------\n", "%#.");
	printf("\n");

	ret = ft_printf("|%#.x|", 42);
	printf("\n");
	ret1 = printf("|%#.x|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



			printf("\n");
	printf("-----------  %s 	-----------\n", "%10x");
	printf("\n");

	ret = ft_printf("|%10x|", 42);
	printf("\n");
	ret1 = printf("|%10x|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



			printf("\n");
	printf("-----------  %s 	-----------\n", "%-15x");
	printf("\n");

	ret = ft_printf("|%-15x|", 42);
	printf("\n");
	ret1 = printf("|%-15x|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


		printf("\n");
	printf("-----------  %s 	-----------\n", "%5.2x");
	printf("\n");

	ret = ft_printf("|%5.2x|", 42);
	printf("\n");
	ret1 = printf("|%5.2x|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


		printf("\n");
	printf("-----------  %s 	-----------\n", "%010X");
	printf("\n");

	ret = ft_printf("|%010X|", 542);
	printf("\n");
	ret1 = printf("|%010X|", 542);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s 	-----------\n", "%2X");
	printf("\n");

	ret = ft_printf("|%2x|", 542);
	printf("\n");
	ret1 = printf("|%2x|", 542);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s 	-----------\n", "%.2X");
	printf("\n");

	ret = ft_printf("|%.2x|", 542);
	printf("\n");
	ret1 = printf("|%.2x|", 542);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);




	printf("\n");
	printf("-----------  %s 	-----------\n", "%#X");
	printf("\n");

	ret = ft_printf("|%#x|", 542);
	printf("\n");
	ret1 = printf("|%#x|", 542);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "%%");
	printf("\n");

	ret = ft_printf("|%%|");
	printf("\n");
	ret1 = printf("|%%|");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "%5%");
	printf("\n");

	ret = ft_printf("|%5%|");
	printf("\n");
	ret1 = printf("|%5%|");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "%-5%");
	printf("\n");

	ret = ft_printf("|%-5%|");
	printf("\n");
	ret1 = printf("|%-5%|");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "%.0%");
	printf("\n");

	ret = ft_printf("|%.0%|");
	printf("\n");
	ret1 = printf("|%.0%|");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "%%");
	printf("\n");

	ret = ft_printf("|%%|", "test");
	printf("\n");
	ret1 = printf("|%%|", "test");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s 	-----------\n", "%%");
	printf("\n");

	ret = ft_printf("|% %|", "test");
	printf("\n");
	ret1 = printf("|% %|", "test");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



		printf("\n");
	printf("-----------  %s 	-----------\n", "%%");
	printf("\n");

	ret = ft_printf("|% %|", "test");
	printf("\n");
	ret1 = printf("|% %|", "test");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);




		printf("\n");
	printf("-----------  %s 	-----------\n", "u");
	printf("\n");

	ret = ft_printf("|%u|", 4294967295);
	printf("\n");
	ret1 = printf("|%u|", 4294967295);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


		printf("\n");
	printf("-----------  %s 	-----------\n", "u");
	printf("\n");

	ret = ft_printf("|%ld|", -2147483648);
	printf("\n");
	ret1 = printf("|%ld|", -2147483648);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

		printf("\n");
	printf("-----------  %s 	-----------\n", "u");
	printf("\n");

	ret = ft_printf("|%ld|", 2147483648);
	printf("\n");
	ret1 = printf("|%ld|", 2147483648);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


		printf("\n");
	printf("-----------  %s 	-----------\n", "u");
	printf("\n");

	ret = ft_printf("|%lld|", 9223372036854775807);
	printf("\n");
	ret1 = printf("|%lld|", 9223372036854775807);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);





	///////////////////////////////////////////////////////////////////////////////////////////////////////////
		printf("\n");
	printf("-----------  %s 	-----------\n", "#llx");
	printf("\n");

	ret = ft_printf("|%#llx|", 9223372036854775807);
	printf("\n");
	ret1 = printf("|%#llx|", 9223372036854775807);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "#x");
	printf("\n");

	ret = ft_printf("|%#x|", 0);
	printf("\n");
	ret1 = printf("|%#x|", 0);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "%.2s");
	printf("\n");

	ret = ft_printf("|%.2s is a string|", "this");
	printf("\n");
	ret1 = printf("|%.2s is a string|", "this");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	/////////////////////////////////////////////////////////////////////




	printf("\n");
	printf("-----------  %s 	-----------\n", "%-.2s");
	printf("\n");

	ret = ft_printf("|%-.2s is a string|", "this");
	printf("\n");
	ret1 = printf("|%-.2s is a string|", "this");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "%s NULL");
	printf("\n");

	ret = ft_printf("|@moulitest: %s|", NULL);
	printf("\n");
	ret1 = printf("|@moulitest: %s|", NULL);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


		printf("\n");
	printf("-----------  %s 	-----------\n", "%s  %s NULL");
	printf("\n");

	ret = ft_printf("|%s %s|", NULL, "string");
	printf("\n");
	ret1 = printf("|%s %s|", NULL, "string");

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


		printf("\n");
	printf("-----------  %s 	-----------\n", "%#6o");
	printf("\n");

	ret = ft_printf("|%#6o|", 2500);
	printf("\n");
	ret1 = printf("|%#6o|", 2500);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s 	-----------\n", "%-#6o");
	printf("\n");

	ret = ft_printf("|%-#6o|", 2500);
	printf("\n");
	ret1 = printf("|%-#6o|", 2500);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



///////////////////////////////////////////////////////////////////////////////////
	printf("\n");
	printf("-----------  %s 	-----------\n", "%-05o");
	printf("\n");

	ret = ft_printf("|%-05o|", 2500);
	printf("\n");
	ret1 = printf("|%-05o|", 2500);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "%-10.5o");
	printf("\n");

	ret = ft_printf("|%-10.5o|", 2500);
	printf("\n");
	ret1 = printf("|%-10.5o|", 2500);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "%d");
	printf("\n");

	ret = ft_printf("|%d|", -2147483648);
	printf("\n");
	ret1 = printf("|%d|", -2147483648);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s 	-----------\n", "%d");
	printf("\n");

	ret = ft_printf("|%ld|", 2147483648);
	printf("\n");
	ret1 = printf("|%ld|", 2147483648);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s 	-----------\n", "%#x");
	printf("\n");

	ret = ft_printf("|%#x|", 0);
	printf("\n");
	ret1 = printf("|%#x|", 0);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



		printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s 	-----------\n", "%-#6o");
	printf("\n");

	ret = ft_printf("|%-#6o|", 2500);
	printf("\n");
	ret1 = printf("|%-#6o|", 2500);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);




//////////////////////////////////////////////////////////

	printf("\n");
	printf("-----------  %s 	-----------\n", "%+d");
	printf("\n");

	ret = ft_printf("|%+d|", 0);
	printf("\n");
	ret1 = printf("|%+d|", 0);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "%-05d");
	printf("\n");

	ret = ft_printf("|%-05d|", 42);
	printf("\n");
	ret1 = printf("|%-05d|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "%-05d");
	printf("\n");

	ret = ft_printf("|%-05d|", -42);
	printf("\n");
	ret1 = printf("|%-05d|", -42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "%hd");
	printf("\n");

	ret = ft_printf("|%hd|", 32768);
	printf("\n");
	ret1 = printf("|%hd|", 32768);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "%hhd");
	printf("\n");

	ret = ft_printf("|%hhd|", 128);
	printf("\n");
	ret1 = printf("|%hhd|", 128);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s 	-----------\n", "%hhd");
	printf("\n");

	ret = ft_printf("|%hhd|", -128);
	printf("\n");
	ret1 = printf("|%hhd|", -128);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s 	-----------\n", "%ld");
	printf("\n");

	ret = ft_printf("|%ld|", 2147483648);
	printf("\n");
	ret1 = printf("|%ld|", 2147483648);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "%ld");
	printf("\n");

	ret = ft_printf("|%ld|", -2147483648);
	printf("\n");
	ret1 = printf("|%ld|", -2147483648);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "%#-08x");
	printf("\n");

	ret = ft_printf("|%#-08x|", 42);
	printf("\n");
	ret1 = printf("|%#-08x|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "%-05o");
	printf("\n");

	ret = ft_printf("|%-05o|", 2500);
	printf("\n");
	ret1 = printf("|%-05o|", 2500);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

////////////////////////////-----------------------------------------------
	printf("\n");
	printf("-----------  %s 	-----------\n", "%jd");
	printf("\n");

	ret = ft_printf("|%jd|", 9223372036854775807);
	printf("\n");
	ret1 = printf("|%jd|", 9223372036854775807);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "%jd");
	printf("\n");

	ret = ft_printf("|%jd|", -9223372036854775807);
	printf("\n");
	ret1 = printf("|%jd|", -9223372036854775807);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "%zd");
	printf("\n");

	ret = ft_printf("|%zd|", 4294967295);
	printf("\n");
	ret1 = printf("|%zd|", 4294967295);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s 	-----------\n", "%zd");
	printf("\n");

	ret = ft_printf("|%zd|", 4294967296);
	printf("\n");
	ret1 = printf("|%zd|", 4294967296);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s 	-----------\n", "%zd");
	printf("\n");

	ret = ft_printf("|%zd|", -1);
	printf("\n");
	ret1 = printf("|%zd|", -1);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "%4.15d");
	printf("\n");

	ret = ft_printf("|%4.15d|", 42);
	printf("\n");
	ret1 = printf("|%4.15d|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "%10.5d");
	printf("\n");

	ret = ft_printf("|%10.5d|", 4242);
	printf("\n");
	ret1 = printf("|%10.5d|", 4242);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "%-10.5d");
	printf("\n");

	ret = ft_printf("|%-10.5d|", 4242);
	printf("\n");
	ret1 = printf("|%-10.5d|", 4242);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "%-10.5d");
	printf("\n");

	ret = ft_printf("|% 10.5d|", 4242);
	printf("\n");
	ret1 = printf("|% 10.5d|", 4242);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "%+10.5d");
	printf("\n");

	ret = ft_printf("|%+10.5d|", 4242);
	printf("\n");
	ret1 = printf("|%+10.5d|", 4242);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "%-+10.5d");
	printf("\n");

	ret = ft_printf("|%-+10.5d|", 4242);
	printf("\n");
	ret1 = printf("|%-+10.5d|", 4242);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "%03.2d");
	printf("\n");

	ret = ft_printf("|%03.2d|", 0);
	printf("\n");
	ret1 = printf("|%03.2d|", 0);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "%03.2d");
	printf("\n");

	ret = ft_printf("|%03.2d|", 1);
	printf("\n");
	ret1 = printf("|%03.2d|", 1);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "%.10d");
	printf("\n");

	ret = ft_printf("|@moulitest : %.10d|", -42);
	printf("\n");
	ret1 = printf("|@moulitest : %.10d|", -42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "%.d %.0d");
	printf("\n");

	ret = ft_printf("|@moulitest : %.d %.0d|", 0, 0);
	printf("\n");
	ret1 = printf("|@moulitest : %.d %.0d|", 0, 0);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "%5.d %5.0d");
	printf("\n");

	ret = ft_printf("|@moulitest : %5.d %5.0d|", 0, 0);
	printf("\n");
	ret1 = printf("|@moulitest : %5.d %5.0d|", 0, 0);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "u");
	printf("\n");

	ret = ft_printf("|%u|", -1);
	printf("\n");
	ret1 = printf("|%u|", -1);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "u");
	printf("\n");

	ret = ft_printf("|%u|", 4294967296);
	printf("\n");
	ret1 = printf("|%u|", 4294967296);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "15u");
	printf("\n");

	ret = ft_printf("|%15u|", 4294967295);
	printf("\n");
	ret1 = printf("|%15u|", 4294967295);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "15u");
	printf("\n");

	ret = ft_printf("|%-15u|", 4294967295);
	printf("\n");
	ret1 = printf("|%-15u|", 4294967295);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "015u");
	printf("\n");

	ret = ft_printf("|%015u|", 4294967295);
	printf("\n");
	ret1 = printf("|%015u|", 4294967295);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", " u");
	printf("\n");

	ret = ft_printf("|% u|", 4294967295);
	printf("\n");
	ret1 = printf("|% u|", 4294967295);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "+u");
	printf("\n");

	ret = ft_printf("|%+u|", 4294967295);
	printf("\n");
	ret1 = printf("|%+u|", 4294967295);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "hU");
	printf("\n");

	ret = ft_printf("|%hU|", 4294967296);
	printf("\n");
	ret1 = printf("|%hU|", 4294967296);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s 	-----------\n", "U");
	printf("\n");

	ret = ft_printf("|%U|", 4294967296);
	printf("\n");
	ret1 = printf("|%U|", 4294967296);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "U");
	printf("\n");

	ret = ft_printf("|%042.5d % d|", -4242, -56);
	printf("\n");
	ret1 = printf("|%42.5d % d|", -4242, -56);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "U");
	printf("\n");

	ret = ft_printf("%X%X%X%X%X", 1, 100, 999, 42, 999988888);
	printf("\n");
	ret1 = printf("%X%X%X%X%X",  1, 100, 999, 42, 999988888);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

*/
/*	printf("\n");
	printf("-----------  %s 	-----------\n", "U");
	printf("\n");

	//ret = ft_printf("%2d %2d%D%D% d %d%d\n", 42, 52, 62, 72 , 82, 92, 102);
	ret = ft_printf("%2s %s%s%s% s sssoooo pichakurwa---------->>>>>> %s%s%s%s", " 42 ", "52 ", "62 ", "72 " , "82 ", "92 ", "102 ", "picha ", "kurwa");
	//printf("\n%p\n", 42424242);
	printf("\n");
	ret1 = printf("|%8d|",  42);

	printf("\n");



	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



	printf("\n");
	printf("-----------  %s 	-----------\n", "U");
	printf("\n");

	ret = ft_printf("%+d picha? %s%c %c", 42, "kurwa!", 'j', 'j');
	printf("\n");
	ret1 = printf("%+d picha? %s%c %c", 42, "kurwa!", 'j', 'j');

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


	printf("\n");
	printf("-----------  %s 	-----------\n", "U");
	printf("\n");

	ret = ft_printf("%2d %2.3d%d", 42, 52 ,62);
	printf("\n");
	ret1 = printf("|%+h8-----  - + 000-----++++++6+++++.3+++000000   hd|", 424242);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



		printf("\n");
	printf("-----------  %s 	-----------\n", "U");
	printf("\n");
 
	ret = ft_printf("%jx", 4294967295);
	printf("\n");
	ret1 =   printf("%jx", 4294967295);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


		printf("\n");
	printf("-----------  %s 	-----------\n", "U");
	printf("\n");
 
	ret = ft_printf("%llx",  9223372036854775807);
	printf("\n");
	ret1 =   printf("%llx",  9223372036854775807);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);


		printf("\n");
	printf("-----------  %s 	-----------\n", "d");
	printf("\n");
 
	ret = ft_printf("@moulitest: %s", NULL);
	printf("\n");
	ret1 =   printf("@moulitest: %s", NULL);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

	printf("\n");
	printf("-----------  %s 	-----------\n", "d");
	printf("\n");
 
	ret = ft_printf("@moulitest: %c", 0);
	printf("\n");
	ret1 =   printf("@moulitest: %c", 0);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);



 return (0);	
}	
*/