
#include "includes/ft_printf.h"

void		ft_putnchar(char c, int size)
{
	int i;

	i = 0;
	while (i++ < size)
		write(1, &c, 1);
}

void	ft_printoctotorp(char c)
{
	ft_putchar('0');
	ft_putchar(c);
}