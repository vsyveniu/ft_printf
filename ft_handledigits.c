
#include "includes/ft_printf.h"


void	ft_printpercent()
{
	write(1, "%", 1);
}

void	ft_handledigits(f_list *params, void *arg, int val)
{
	//printf("--------->>>>>>>>>  %d", size);
	if (params->conversion == 'd' || params->conversion == 'i')
		ft_printdecimal(arg, val);
	if (params->conversion == 'u' || params->conversion == 'U')
		ft_printudecimal(arg, val);
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
