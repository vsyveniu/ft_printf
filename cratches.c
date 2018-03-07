
#include "includes/ft_printf.h"

void	ft_putcratch( char c1, char c2, int size)
{
		ft_putchar(c1);
		ft_putnchar(c2, size);
}

void	ft_putcratchv2(char c2, char c1, int size)
{
	ft_putnchar(c2, size);
	ft_putchar(c1);
}
void	ft_tcrutch(char c2, char c3, int size, int size2)
{
	ft_putnchar(' ', size);
	ft_putchar(c2);
	ft_putnchar(c3, size2);
}

void	ft_dcrutch(char c1, char c2, int size, int size2)
{
	
	ft_putnchar(c1, size);
	ft_putnchar(c2, size2);
}

void	ft_putdoublecratchhash(f_list *p, char c2, int size, int size2)
{
	
	ft_putnchar(' ', size);
	if((p->c == 'x' || p->c == 'X') && p->f_oct)
		ft_printhash(p->c);
	ft_putnchar(c2, size2);
}



