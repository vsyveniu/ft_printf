
#include "ft_printf.h"

void	ft_putunnbr(unsigned long long n)
{
	unsigned long long	i;

	i = (unsigned long long)n;
	//if (n < 0)
	//{
	//	i = (signed long long)(-n);
	//	ft_putchar('-');
	//}
	if (i > 9)
	{
		ft_putunnbr(i / 10);
		ft_putunnbr(i % 10);
	}
	else
	{
		ft_putchar(i + '0');
	}
}