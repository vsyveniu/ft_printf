
#include "includes/ft_printf.h"


void	ft_printbinary(int i, int val)
{
	(val == 0) ? ft_putbinary(i) : 0;
	(val == 1) ? ft_putbinary((short)i) : 0;
	(val == 2) ? ft_putbinary((char)i) : 0;
	(val == 3) ? ft_putbinary((unsigned long)i) : 0;
	(val == 4) ? ft_putbinary((long)i) : 0;
	//(val == 5) ? ft_puthex(c, (uintmax_t)i) : 0;
	(val == 6) ? ft_putbinary((size_t)i) : 0;
}

void	ft_printcocto(f_list *p, void *i, int val)
{
	if (p->conversion == 'o')
	{
		(val == 0) ? ft_putocto(p, (unsigned int)i) : 0;
		(val == 1) ? ft_putocto(p, (unsigned short)i) : 0;
		(val == 2) ? ft_puthhocto(p, (unsigned char)i) : 0;
		(val == 3) ? ft_putocto(p, (unsigned long long int)i) : 0;
		(val == 4) ? ft_putocto(p, (unsigned long long int)i) : 0;
		(val == 5) ? ft_putocto(p, (uintmax_t)i) : 0;
		(val == 6) ? ft_putocto(p, (size_t)i) : 0;
	}
	else if (p->conversion == 'O')
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


void	ft_printpointer(void *i, f_list *p)
{
	ft_putpoint(i, p);
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
	(val == 4) ? ft_putnbr(p, (long long)i) : 0; //need putunsignednbr!!!!!!!!!!!!!!!!!!!
	(val == 5) ? ft_putunnbr((uintmax_t)i) : 0;
	(val == 6) ? ft_putnbr(p, (ssize_t)i) : 0;
}




void	ft_printudecimal(f_list *p, void *i, int val)
{	
	if (p->conversion == 'u')
	{
		if ((int)i == 0 && p->prcrutch && p->pr == 0)
			return ;
		(val == 0) ? ft_putunnbr((unsigned int)i) : 0;
		(val == 1) ? ft_putunnbr((unsigned short int)i) : 0;
		(val == 2) ? ft_putunnbr((unsigned char)i) : 0;
		(val == 3) ? ft_putunnbr((unsigned long long)i) : 0;
		(val == 4) ? ft_putunnbr((unsigned long long)i) : 0;
		(val == 5) ? ft_putunnbr((uintmax_t)i) : 0;
		(val == 6) ? ft_putunnbr((size_t)i) : 0;
	}
	else if (p->conversion == 'U' && !p->prcrutch)
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

void	ft_printnotvalid(void *i, int *index)
{
	char *c;

	c = (char*)i;


	printf("%c\n", c[*index]);
}
/*
val = 0;
	if ( p->mod && ft_strcmp(p->mod, "h") == 0)
		return(val = 1);
	if (p->mod && ft_strcmp(p->mod, "hh") == 0)
		return(val = 2);
	if (p->mod && ft_strcmp(p->mod, "l") == 0)
		return(val = 3);
	if (p->mod && ft_strcmp(p->mod, "ll") == 0)
		return(val = 4);
	if (p->mod && ft_strcmp(p->mod, "j") == 0)
		return(val = 5);
	if (p->mod && ft_strcmp(p->mod, "z") == 0)
		return(val = 6);
	return(val);*/