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
	p->negmark = 0;
	p->conversion = 0;


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
			p->pr = get_precision(f, i);
			while (ft_isdigit(f[*i]) == 1)
				(*i)++;
		}
		if (ft_isconv(f[*i]) == 1)
		{
			p->conversion = get_conversion(f, i);
			break ;
		}
		else if (ft_isconv(f[*i]) == 0 && ft_isflag(f[*i]) == 0 && ft_isdigit(f[*i]) == 0)
		{
			if(p->f_minus)
			{
				write(1, &f[*i], 1);
			}
			else
				(*i)--;
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
	//printf("\nconvers -> %c\n", p->conversion)
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
		else if (f[i] != '\0')
		{
			ret++;
			i++;
		}	
	}
	ft_putnnnstr(f, start, len);
	return (ret);
}
/*
int		ft_isitpossible(const char *format, int i)
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

int		main()
{
	int ret1;
	int ret;
/*
	
	

*/


	printf("\n");
	printf("-----------  %s 	-----------\n", " 08.10");
	printf("\n");
 
	ret = ft_printf("{%010d}", -42);
	//ret = ft_printf("a%ob%oc%od", 0, 55555, 100000);
	printf("\n");
	ret1 =   printf("{%010d}", -42);
	//ret1 =   printf("a%ob%oc%od", 0, 55555, 100000);
	//ret1 =   printf("|%x|", 42);

	printf("\n");

	printf("\n");
	printf("custom -> %d\n", ret);
	printf("origin -> %d\n", ret1);

 return (0);	
}	
