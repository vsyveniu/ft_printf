
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



int	ft_base(long long arg, long long base, int size)
{

	//printf("arg --->>> %lld\n", arg);
	while (arg > 0)
	{
		arg /= base;
		++size;
	}
	return (size);
}


int	ft_printdecimal(void *i, int val, int size)
{
	long long temp;
	//printf("i - > %d", i);
	temp = (long long)i;
	printf("%ld\n", temp); 
	 if ((int)i == 1 || (int)i == 0)
		size = 1;
	else if ((int)i == -1)
		size = 2;
	else if (temp < 0)
	{
		printf("picha\n");
		temp *= -1;
		size = ft_base(temp, 10, size);
		size++;
	}
	else
		size = ft_base(temp, 10, size);
	//printf("\nval - > %d\n"	, val);
	(val == 0) ? ft_putnbr((int)i) : 0;
	(val == 1) ? ft_putnbr((short)i) : 0;
	(val == 2) ? ft_putnbr((char)i) : 0;
	(val == 3) ? ft_putnbr((long long)i) : 0;
	(val == 4) ? ft_putnbr((long)i) : 0; //need putunsignednbr!!!!!!!!!!!!!!!!!!!
	//(val == 5) ? ft_putnbr((uintmax_t)i) : 0;
	(val == 6) ? ft_putnbr((size_t)i) : 0;
	return (size);
}


int	ft_unsbase(unsigned long long int arg, unsigned long long int base, int size)
{

	//unsigned long long int i;
//	printf("arg --->>> %llu\n", arg);
	//i = 1;
	//printf("%llu\n", arg);
	while (arg > 0)
	{
		arg /= base;
		size += 1;
	}
	//size = 42;
	return (size);
}

int		ft_printudecimal(void *i, int val, int size)
{
	//unsigned long long temp;
	//printf("i - > %d", i);
	//temp = (unsigned long long)i; 
	//if (temp == 42424242424242424)
	//	size = 10;
	//printf("%llu\n", temp);
    if ((int)i == 0 || (int)i == 1)
    {
    	//printf("picha\n");
		size = 1;
    }
	else
	{
		//printf("kurwa\n");
		size = ft_unsbase((unsigned long long int)i, 10, size);
	}
	//printf("-------->>>>>>>>> %d\n", val);
	(val == 0) ? ft_putunnbr((unsigned int)i) : 0;
	//(val == 1) ? ft_putnbr((short)i) : 0;
	//(val == 2) ? ft_putnbr((char)i) : 0;
	(val == 3) ? ft_putunnbr((unsigned long long)i) : 0;
	(val == 4) ? ft_putunnbr((unsigned long long)i) : 0;
	//(val == 5) ? ft_putnbr((uintmax_t)i) : 0;
	//(val == 6) ? ft_putnbr((size_t)i) : 0;

	return (size);
}
