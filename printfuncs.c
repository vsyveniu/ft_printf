
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

void	ft_printcocto(void *i, int val)
{
	(val == 0) ? ft_putocto((unsigned int)i) : 0;
	(val == 1) ? ft_putocto((unsigned short)i) : 0;
	(val == 2) ? ft_putocto((char)i) : 0;
	(val == 3) ? ft_putocto((unsigned long long int)i) : 0;
	(val == 4) ? ft_putocto((unsigned long long int)i) : 0;
	(val == 5) ? ft_putocto((unsigned int)i) : 0;
	(val == 6) ? ft_putocto((size_t)i) : 0;
}

void	ft_printhex(char c,f_list *p, void *i, int val)
{
	(val == 0) ? ft_puthex(c, p, (unsigned int)i) : 0;
	(val == 1) ? ft_puthex(c, p, (unsigned short)i) : 0;
	(val == 2) ? ft_puthex(c, p, (char)i) : 0;
	(val == 3) ? ft_puthex(c, p, (unsigned long long int)i) : 0;
	(val == 4) ? ft_puthex(c, p, (unsigned long int)i) : 0;
	(val == 5) ? ft_puthex(c, p, (uintmax_t)i) : 0;
	(val == 6) ? ft_puthex(c, p, (size_t)i) : 0;
}


void	ft_printpointer(void *i)
{
	ft_putchar('0');
	ft_putchar('x');
	ft_putpoint(i);
}

void	ft_printdecimal(void *i, int val)
{
	int temp;
	//printf("------------>>>>>>>>>%d\n", val);
	temp = (int)i;
	if ((int)i < 0)/////////////////this isa very weak crutch and it will fuck me many times int the future
		temp *= -1;
	//printf("------------->>>>>>>>>>>> %d <<<<<<<<<<<<<<<------------", (int)i);
	(val == 0) ? ft_putnbr(temp) : 0;
	(val == 1) ? ft_putnbr((short int )i) : 0;
	if (val == 2)
	{
		if (temp == -128)
			write(1, "-128", 4);
		else
		   	ft_putnbr((char)i);
	}
	(val == 3) ? ft_putnbr((long)i) : 0;
	(val == 4) ? ft_putunnbr((long long)i) : 0; //need putunsignednbr!!!!!!!!!!!!!!!!!!!
	(val == 5) ? ft_putnbr((intmax_t)i) : 0;
	(val == 6) ? ft_putnbr((size_t)i) : 0;
}

void	ft_printlongdecimal(void *i, int val)
{
	(val == 0) ? ft_putnbr((long)i) : 0;
	(val == 3) ? ft_putnbr((long)i) : 0;
	(val == 4) ? ft_putnbr((long long)i) : 0; //need putunsignednbr!!!!!!!!!!!!!!!!!!!
	(val == 5) ? ft_putnbr((unsigned long long int )i) : 0;
	(val == 6) ? ft_putnbr((size_t)i) : 0;
}




void	ft_printudecimal(void *i, int val)
{
	(val == 0) ? ft_putunnbr((unsigned int)i) : 0;
	(val == 1) ? ft_putunnbr((unsigned short)i) : 0;
	(val == 3) ? ft_putunnbr((unsigned long long)i) : 0;
	(val == 4) ? ft_putunnbr((unsigned long long)i) : 0;
	(val == 5) ? ft_putunnbr((uintmax_t)i) : 0;
	//(val == 6) ? ft_putnbr((size_t)i) : 0;

}

void	ft_printnotvalid(void *i, int *index)
{
	char *c;

	c = (char*)i;


	printf("%c\n", c[*index]);
}

