
#include "includes/ft_printf.h"

void	ft_putunnbr(uintmax_t n)
{
	uintmax_t	i;

	i = (uintmax_t)n;
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