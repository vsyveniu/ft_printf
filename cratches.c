
#include "ft_printf.h"

void	ft_putcratch(char c1, char c2, int size)
{
	ft_putchar(c1);
	ft_putnchar(c2, size);
}

void	ft_putcratchv2(char c1, char c2, int size)
{
	ft_putnchar(c2, size);
	ft_putchar(c1);
}
void	ft_puttriplecratch(char c2, char c3, int size, int size2)
{
	ft_putnchar(' ', size);
	ft_putchar(c2);
	ft_putnchar(c3, size2);
}

void	ft_putdoublecratch(f_list *p, char c2, int size, int size2)
{
	
	ft_putnchar(' ', size);
	if(p->conversion == 'x' || p->conversion == 'X')
		ft_printhash(p->conversion);
	ft_putnchar(c2, size2);
}

void	ft_printhash(char c)
{
	ft_putchar('0');
	ft_putchar(c);
}