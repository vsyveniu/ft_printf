
#include "includes/ft_printf.h"

void	ft_putcratch( char c1, char c2, int size)
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
	if((p->conversion == 'x' || p->conversion == 'X') && p->f_oct)
		ft_printhash(p->conversion);
	ft_putnchar(c2, size2);
}

void	ft_printhash(char c)
{
	ft_putchar('0');
	ft_putchar(c);
}
void 	ft_crutchforhash(f_list *p, char c, int size)
{
	ft_printhash(p->conversion);
	ft_putnchar(c, size);
}

void 	ft_crutchforhashv2(f_list *p, char c, int size)
{
	ft_putnchar(c, size);
	ft_printhash(p->conversion);
	
}

void 	ft_crutchforhashleft(f_list *p, char c, int size)
{
	ft_printhash(p->conversion);
	ft_putnchar(c, size);
}