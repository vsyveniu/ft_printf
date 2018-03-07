
#include "includes/ft_printf.h"


void	ft_printcocto(f_list *p, void *i, int val)
{
	if (p->c == 'o')
	{
		(val == 0) ? ft_putocto(p, (unsigned int)i) : 0;
		(val == 1) ? ft_putocto(p, (unsigned short)i) : 0;
		(val == 2) ? ft_puthhocto(p, (unsigned char)i) : 0;
		(val == 3) ? ft_putocto(p, (unsigned long long int)i) : 0;
		(val == 4) ? ft_putocto(p, (unsigned long long int)i) : 0;
		(val == 5) ? ft_putocto(p, (uintmax_t)i) : 0;
		(val == 6) ? ft_putocto(p, (size_t)i) : 0;
	}
	else if (p->c == 'O')
	{
		(val == 0) ? ft_putocto(p, (unsigned int)i) : 0;
		(val == 1) ? ft_putocto(p, (unsigned short)i) : 0;
		(val == 2) ? ft_putocto(p, (unsigned int)i) : 0;
		(val == 3) ? ft_putocto(p, (unsigned long long int)i) : 0;
		(val == 4) ? ft_putocto(p, (unsigned long long int)i) : 0;
		(val == 5) ? ft_putocto(p, (unsigned int)i) : 0;
		(val == 6) ? ft_putocto(p, (size_t)i) : 0;
	}
}

void	ft_printhex(char c,f_list *p, void *i, int val)
{
	(val == 0) ? ft_puthex(c, p, (unsigned int)i) : 0;
	(val == 1) ? ft_puthex(c, p, (unsigned short)i) : 0;
	(val == 2) ? ft_puthex(c, p, (unsigned char)i) : 0;
	(val == 3) ? ft_puthex(c, p, (unsigned long long int)i) : 0;
	(val == 4) ? ft_puthex(c, p, (unsigned long int)i) : 0;
	(val == 5) ? ft_puthex(c, p, (uintmax_t)i) : 0;
	(val == 6) ? ft_puthex(c, p, (size_t)i) : 0;
}


void	ft_printdecimal(f_list *p, void *i, int val)
{
	int temp;

	temp = (int)i;
	if ((int)i < 0)
		temp *= -1;
	(val == 0) ? ft_putnbr(p, temp) : 0;
	(val == 1) ? ft_putnbr(p, (short int )i) : 0;
	if (val == 2)
	{
		if (temp == -128)
			write(1, "-128", 4);
		else
		  	ft_putnbr(p, (char)i);
	}
	(val == 3) ? ft_putnbr(p, (long)i) : 0;
	if (val == 4)
	{ 
		if ((uintmax_t)i > 9223372036854775807)
			write (1, "-9223372036854775808", 20);
		else
			ft_putnbr(p, (long long)i);
	}
	(val == 5) ? ft_putunnbr((intmax_t)i) : 0;
	(val == 6) ? ft_putnbr(p, (ssize_t)i) : 0;
}

void	ft_printlongdecimal(f_list *p, void *i, int val)
{
	(val == 0) ? ft_putnbr(p, (long)i) : 0;
	(val == 1) ? ft_putnbr(p, (long)i) : 0;
	(val == 2) ? ft_putnbr(p, (long)i) : 0;
	(val == 3) ? ft_putnbr(p, (long)i) : 0;
	(val == 4) ? ft_putnbr(p, (long long)i) : 0;
	(val == 5) ? ft_putunnbr((uintmax_t)i) : 0;
	(val == 6) ? ft_putnbr(p, (ssize_t)i) : 0;
}




void	ft_printudecimal(f_list *p, void *i, int val)
{	
	if (p->c == 'u')
	{
		if ((int)i == 0 && p->prc && p->pr == 0)
			return ;
		(val == 0) ? ft_putunnbr((unsigned int)i) : 0;
		(val == 1) ? ft_putunnbr((unsigned short int)i) : 0;
		(val == 2) ? ft_putunnbr((unsigned char)i) : 0;
		(val == 3) ? ft_putunnbr((unsigned long long)i) : 0;
		(val == 4) ? ft_putunnbr((unsigned long long)i) : 0;
		(val == 5) ? ft_putunnbr((uintmax_t)i) : 0;
		(val == 6) ? ft_putunnbr((size_t)i) : 0;
	}
	else if (p->c == 'U' && !p->prc)
	{
		(val == 0) ? ft_putunnbr((unsigned long int)i) : 0;
		(val == 1) ? ft_putunnbr((unsigned long int)i) : 0;
		(val == 2) ? ft_putunnbr((unsigned long int)i) : 0;
		(val == 3) ? ft_putunnbr((unsigned long long)i) : 0;
		(val == 4) ? ft_putunnbr((unsigned long long)i) : 0;
		(val == 5) ? ft_putunnbr((uintmax_t)i) : 0;
		(val == 6) ? ft_putnbr(p, (size_t)i) : 0;
	}
}
