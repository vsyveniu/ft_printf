
#include "includes/ft_printf.h"


void	ft_printpercent()
{	
	write(1, "%", 1);
}

void	ft_printpointer(void *i, f_list *p)
{
	ft_putpoint(i, p);
}

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

void	ft_printhash(char c)
{
	if (c == 'x' || c == 'X')
	{
		ft_putchar('0');
		ft_putchar(c);
	}
	else if (c == 'p')
		write(1, "0x", 2);
	else if (c == 'o' || c == 'O')
		ft_putchar('0');
}


void	ft_handledigits(f_list *p, void *arg, int val)
{
	if ((p->c == 'd' || p->c == 'i'))
		ft_printdecimal(p, arg, val);
	if (p->c == 'D')
		ft_printlongdecimal(p, arg, val);
	if (p->c == 'u' || p->c == 'U')
		ft_printudecimal(p, arg, val);
	if (p->c == '%')
		ft_printpercent();
	if (p->c == 'x' || p->c == 'X')
		ft_printhex(p->c, p, arg, val);
	if (p->c == 'o' || p->c == 'O')
		ft_printcocto(p, arg, val);
	if (p->c == 'b')
		ft_printbinary((int)arg, val);
	if (p->c == 'p')
		ft_printpointer(arg, p);
}
