
#include "ft_printf.h"


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

void	ft_printcocto(int i, int val)
{
	(val == 0) ? ft_putocto(i) : 0;
	(val == 1) ? ft_putocto((short)i) : 0;
	(val == 2) ? ft_putocto((char)i) : 0;
	(val == 3) ? ft_putocto((unsigned long)i) : 0;
	(val == 4) ? ft_putocto((long)i) : 0;
	//(val == 5) ? ft_putocto(c, (uintmax_t)i) : 0;
	(val == 6) ? ft_putocto((size_t)i) : 0;
}

void	ft_printhex(char c, int i, int val)
{
	(val == 0) ? ft_puthex(c, i) : 0;
	(val == 1) ? ft_puthex(c, (short)i) : 0;
	(val == 2) ? ft_puthex(c, (char)i) : 0;
	(val == 3) ? ft_puthex(c, (unsigned long)i) : 0;
	(val == 4) ? ft_puthex(c, (long)i) : 0;
	//(val == 5) ? ft_puthex(c, (uintmax_t)i) : 0;
	(val == 6) ? ft_puthex(c, (size_t)i) : 0;
}


int	ft_printdecimal(void *i, int val, int size)
{
	//printf("i - > %d", i);
	int j;
	int systembase;

	j = 1;
	systembase = 10;
	
	if (val == 0)
	{	
		if ((int)i == 2147483647)
			size = 10;
		else
		{
			while (j < ((int)i))
			{
				j *= systembase;
				++size;
			}
		}
	}

	//printf("\nval - > %d\n"	, val);
	//printf("%llu\n", (unsigned long long)i);
	(val == 0) ? ft_putnbr((int)i) : 0;
	(val == 1) ? ft_putnbr((short)i) : 0;
	(val == 2) ? ft_putnbr((char)i) : 0;
	(val == 3) ? ft_putnbr((signed long long)i) : 0;
	//(val == 4) ? ft_putnbr((unsigned long long)i) : 0; //need putunsignednbr!!!!!!!!!!!!!!!!!!!
	//(val == 5) ? ft_putnbr((uintmax_t)i) : 0;
	(val == 6) ? ft_putnbr((size_t)i) : 0;

	return (size);
}

void	ft_printudecimal(void *i, int val)
{

//printf("-------->>>>>>>>> %d\n", val);
	(val == 0) ? ft_putnbr((unsigned int)i) : 0;
	//(val == 1) ? ft_putnbr((short)i) : 0;
	//(val == 2) ? ft_putnbr((char)i) : 0;
	(val == 3) ? ft_putunnbr((unsigned long long)i) : 0;
	(val == 4) ? ft_putunnbr((unsigned long long)i) : 0;
	//(val == 5) ? ft_putnbr((uintmax_t)i) : 0;
	(val == 6) ? ft_putnbr((size_t)i) : 0;
}
