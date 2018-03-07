
#include "includes/ft_printf.h"


void	ft_handlepos1(f_list *p, int size)
{
	(p->w && !p->pr && p->w >= size && !p->f_l && !p->f_oct 
	&& p->n != 0) ? ft_putnchar(' ', p->w - size) : 0;
	(p->w && !p->pr && p->w >= size && !p->f_l && !p->f_oct 
	&& p->n == 0) ? ft_putnchar(' ', p->w - size) : 0; 
	(p->w && !p->pr && p->w >= size && !p->f_l 
	&& p->f_oct) ? ft_putnchar(' ', p->w - size) : 0; 
	(p->pr && !p->w && p->pr >= size) ? ft_putnchar('0', p->pr - size) : 0;
	(p->w && p->pr && p->w > p->pr && p->pr > size 
	&& !p->f_l) ? ft_dcrutch(' ', '0', p->w - p->pr, p->pr - size) : 0;
	(p->w && p->pr && p->w > p->pr && p->pr > size 
	&& p->f_l) ? ft_putnchar('0', p->pr - size) : 0;
	(p->w && p->pr && p->w > p->pr 
	&& p->pr < size) ? ft_putnchar(' ', p->w - size) : 0; 
	(p->w && p->pr && p->pr > p->w 
	&& !p->f_oct) ? ft_putnchar('0', p->pr - size) : 0;
	(p->w && p->pr && p->w == p->pr 
	&& !p->f_oct) ? ft_putnchar('0', p->pr - size) : 0;
}

void	ft_handlepos2(f_list *p, int size)
{
	(p->w && !p->pr && p->w >= size 
	&& p->f_plus) ? ft_putcratchv2(' ', '+', p->w - size - 1) : 0;
	(p->pr && !p->w && p->pr >= size 
	&& p->f_plus) ? ft_putcratch('+', '0', p->pr - size) : 0;
	(p->pr && !p->w && p->pr < size && p->f_plus) ? ft_putchar('+') : 0;
	(p->w && p->pr && p->w > p->pr && p->pr > size 
	&& !p->f_l) ? ft_tcrutch('+', '0',p->w - p->pr - 1, p->pr - size) : 0;
	(p->w && p->pr && p->w > p->pr && p->pr > size 
	&& p->f_l) ? ft_putcratch('+', '0', p->pr - size) : 0;
	(p->w && p->pr && p->w > p->pr 
	&& p->pr < size) ? ft_putcratchv2(' ', '+', p->w - size - 1) : 0;
	(p->w && p->pr && p->pr > p->w ) ? ft_putcratch('+','0',p->pr - size) : 0;
	(p->w && p->pr && p->w == p->pr ) ? ft_putcratch('+','0',p->pr - size) : 0;
}

void	ft_handlepos3(f_list *p, int size)
{
	(p->w && !p->pr && p->w >= size 
	&& p->f_zero) ? ft_putnchar('0', p->w - size) : 0;
	(p->pr && !p->w && p->pr >= size 
	&& p->f_zero) ? ft_putnchar('0', p->pr - size) : 0;
	(p->w && p->pr && p->w > p->pr && p->pr > size) ? 
	ft_dcrutch(' ','0',p->w - p->pr, p->pr - size) : 0;
	(p->w && p->pr && p->w > p->pr && p->pr < size 
	&& !p->f_l) ? ft_putnchar(' ', p->w - size) : 0;
	(p->w && p->pr && p->pr > p->w ) ? ft_putnchar('0', p->pr - size) : 0;
	(p->w && p->pr && p->w == p->pr ) ? ft_putnchar('0',p->pr - size) : 0;
}

void	ft_handlepos4(f_list *p, int size)
{
	(p->w && !p->pr 
	&& p->w >= size) ? ft_putcratch('+','0', p->w - size - 1) : 0;
	(p->pr && !p->w 
	&& p->pr >= size) ? ft_putcratch('+', '0', p->pr - size) : 0;
	(p->w && p->pr && p->w > p->pr && p->pr > size) ?
	ft_tcrutch('+','0',p->w - p->pr - 1, p->pr - size) : 0;
	(p->w && p->pr && p->w > p->pr 
	&& p->pr < size) ? ft_putcratchv2(' ','+', p->w - size - 1) : 0;
	(p->w && p->pr && p->pr > p->w) ? ft_putcratch('+', '0', p->pr - size) : 0;
	(p->w && !p->pr && p->w < size) ? ft_putcratch('+', '0', p->pr - size) : 0;
	(p->w && p->pr && p->w == p->pr) ? ft_putcratch('+','0',p->pr - size) : 0;
}

void	ft_handlepos5(f_list *p, int size)
{
	(p->w && !p->pr && p->w >= size && !p->f_zero 
	&& !p->f_oct) ? ft_putcratch(' ',' ', p->w - size - 1) : 0;
	(p->w && !p->pr && p->w >= size 
	&& p->f_zero) ? ft_putcratch(' ','0', p->w - size - 1) : 0;
	(p->w && !p->pr && p->w < size 
	&& p->f_zero) ? ft_putcratch(' ','0', p->w - size - 1) : 0;
	(p->pr && !p->w 
	&& p->pr >= size) ? ft_putcratch(' ', '0', p->pr - size) : 0;
	(p->w && p->pr && p->w > p->pr && p->pr > size) ?
	 ft_tcrutch(' ','0',p->w - p->pr - 1, p->pr - size) : 0;
	(p->w && p->pr && p->w > p->pr && p->pr < size) ? 
	ft_putcratch(' ',' ', p->w - size - 1) : 0;
	(p->w && p->pr && p->pr > p->w) ? ft_putcratch(' ', '0', p->pr - size) : 0;
	(p->w && p->pr && p->w == p->pr) ? ft_putcratch(' ','0',p->pr - size) : 0;
	(!p->w && p->pr && p->pr < size) ? ft_putchar (' '): 0;
}
