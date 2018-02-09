
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

void	ft_printhex(char c, void *i, int val)
{
	(val == 0) ? ft_puthex(c, (unsigned int)i) : 0;
	(val == 1) ? ft_puthex(c, (unsigned short)i) : 0;
	(val == 2) ? ft_puthex(c, (char)i) : 0;
	(val == 3) ? ft_puthex(c, (unsigned long long int)i) : 0;
	(val == 4) ? ft_puthex(c, (unsigned long int)i) : 0;
	(val == 5) ? ft_puthex(c, (uintmax_t)i) : 0;
	(val == 6) ? ft_puthex(c, (size_t)i) : 0;
}






void	ft_printdecimal(void *i, int val)
{

	(val == 0) ? ft_putnbr((int)i) : 0;
	(val == 1) ? ft_putnbr((short)i) : 0;
	(val == 2) ? ft_putnbr((char)i) : 0;
	(val == 3) ? ft_putnbr((long long)i) : 0;
	(val == 4) ? ft_putnbr((long)i) : 0; //need putunsignednbr!!!!!!!!!!!!!!!!!!!
	//(val == 5) ? ft_putnbr((uintmax_t)i) : 0;
	(val == 6) ? ft_putnbr((size_t)i) : 0;
}




void	ft_printudecimal(void *i, int val)
{
	//unsigned long long temp;
	//printf("i - > %d", i);
	//temp = (unsigned long long)i; 
	//if (temp == 42424242424242424)
	//	size = 10;
	//printf("%llu\n", temp);
	//printf("-------->>>>>>>>> %d\n", val);
	(val == 0) ? ft_putunnbr((unsigned int)i) : 0;
	(val == 1) ? ft_putunnbr((unsigned short)i) : 0;
	(val == 3) ? ft_putunnbr((unsigned long long)i) : 0;
	(val == 4) ? ft_putunnbr((unsigned long long)i) : 0;
	(val == 5) ? ft_putunnbr((uintmax_t)i) : 0;
	//(val == 6) ? ft_putnbr((size_t)i) : 0;

}
