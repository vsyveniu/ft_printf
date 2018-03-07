
#include "includes/ft_printf.h"


void	ft_printpercent()
{	write(1, "%", 1);
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
//	if (p->c == 'k')
//		ft_printdate((int)arg);
//	if (p->c == 'r')
//		ft_printnonprintable((int)arg);
}
