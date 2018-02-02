
#include "ft_printf.h"


void	ft_printpercent()
{
	ft_putchar('%');
}

void	ft_handledigits(f_list *params, int arg, int val)
{
	if (params->conversion == 'd' || params->conversion == 'i')
		ft_printdecimal((int)arg, val);
	if (params->conversion == 'u' || params->conversion == 'U')
		ft_printudecimal((unsigned int)arg, val);
	if (params->conversion == '%')
		ft_printpercent();
	if (params->conversion == 'x' || params->conversion == 'X')
		ft_printhex(params->conversion, (int)arg, val);
	if (params->conversion == 'o' || params->conversion == 'O')
		ft_printcocto((int)arg, val);
	if (params->conversion == 'b')
		ft_printbinary((int)arg, val);
//	if (params->conversion == 'k')
//		ft_printdate((int)arg);
//	if (params->conversion == 'r')
//		ft_printnonprintable((int)arg);
}
