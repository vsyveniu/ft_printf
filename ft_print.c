
#include "ft_printf.h"


void	ft_handlepos(f_list *p, int size)
{
	(p->f_plus) ? size += 1 : 0;
	(p->w && p->pr && p->w < p->pr && p->f_zero && p->f_plus) ? ft_putcratch('+','0',p->pr - size) : 0;
	(p->w && p->pr && p->w > p->pr && !p->f_plus && !p->f_zero && !p->f_minus) ? ft_putdoublecratch(p, '0', p->w - p->pr, p->pr - size) : 0;
	(p->w && p->pr && p->w > p->pr && p->f_plus && !p->f_zero) ? ft_puttriplecratch('+', '0', p->w - p->pr - 1, p->pr - size + 1) : 0;
	(p->w && p->pr && p->w > p->pr && !p->f_plus && p->f_zero && !p->f_minus) ? ft_putdoublecratch(p, '0', p->w - p->pr, p->pr - size) : 0;
	(p->w && p->pr && p->w > p->pr && p->f_zero && p->f_minus) ? ft_putnchar('0', p->w - p->pr - 1) : 0; 
	(p->w && p->pr && p->w > p->pr && p->f_minus && !p->f_zero) ? ft_putnchar('0', p->w - p->pr) : 0;
	(p->w && p->pr && p->w < p->pr && p->f_zero && !p->f_plus) ? ft_putnchar('0',p->pr - size ) : 0;
	(p->w && p->pr && p->w < p->pr && !p->f_plus && !p->f_zero) ? ft_putnchar('0', p->pr - size) : 0;
	(p->w && p->pr && p->w < p->pr && p->f_plus && !p->f_zero) ? ft_putcratch('+', '0', p->pr - size + 1) : 0;
	(p->w && p->pr && p->w > p->pr && p->f_plus && p->f_zero && !p->f_minus) ? ft_puttriplecratch('+', '0', p->w - p->pr - 1, p->pr - size + 1) : 0; 
	(!p->w && p->pr && p->f_plus) ? ft_putcratch('+','0', p->pr - size): 0;
	(p->w && !p->pr && p->f_zero) ? ft_putnchar('0', p->w - size) : 0;
	(!p->w && p->pr) ? ft_putnchar('0', p->pr - size): 0;	
	(p->w && p->conversion == '%' && !p->f_minus) ? ft_putnchar(' ', p->w - size - 1) : 0;
	(p->w && !p->pr && !p->f_zero && !p->f_minus && p->conversion != '%') ? ft_putnchar(' ', p->w - size) : 0;
	(p->f_plus && !p->f_zero && !p->pr) ? ft_putchar('+') : 0;
}

void	ft_handleneg(f_list *p, int size)
{
	//(p->ispos == 2) ? size += 1 : 0;
	//(p->w && p->pr && p->w > p->pr && p->f_zero && !p->f_minus) ? ft_puttriplecratch('-', '0', p->w - p->pr - 1, p->pr - size + 1) : 0; 
	//(p->w && p->pr && p->w > p->pr && p->f_zero && p->f_minus) ? ft_putcratch('-', '0', p->w - 1 - p->pr)  : 0;
	//(p->w && p->pr && p->w > p->pr && !p->f_zero && !p->f_minus) ? ft_puttriplecratch('-', '0', p->pr - size, p->w - p->pr) : 0;
	//(p->w && p->pr && p->w > p->pr && !p->f_zero && p->f_minus) ? ft_putcratch('-', '0', p->w - p->pr) : 0;
	//(p->w && p->pr && p->w < p->pr) ? ft_putcratch('-','0',p->pr - size + 1) : 0;
	//(p->w && !p->pr && p->f_zero) ? ft_putcratch('-','0',p->w - size) : 0;
	//(!p->w && p->pr && !p->f_zero && !p->f_minus) ? ft_putcratch('-','0',p->pr - size + 1) : 0;
	//(!p->w && p->pr && !p->f_zero &&  p->f_minus) ? ft_putcratch('-','0',p->pr - size + 1) : 0;
	(p->w && !p->pr && !p->f_zero && !p->f_minus) ? ft_putnchar(' ', p->w - size ) : 0;
	(p->w && !p->pr && !p->f_zero) ? ft_putchar('-') : 0;
	//(!p->w && !p->pr) ? ft_putchar('-') : 0;//there is a fucking bug for

}

int	ft_handleright(f_list *p, int size)
{
	if (p->ispos == 1)
		ft_handlepos(p, size);
	if (p->ispos == 2)
	{
		ft_handleneg(p, size);
	} 
	return (size);
}

int	ft_handleleft(f_list *p, int size)
{
	(p->f_plus) ? size += 1 : 0;
	(p->ispos == 2) ? size += 1 : 0;
	(p->w && p->pr && p->w > p->pr && p->f_zero) ? ft_putnchar(' ', p->w - p->pr) : 0;
	(p->w && !p->pr && !p->f_zero && p->conversion != '%') ? ft_putnchar(' ', p->w - size) : 0;
	(p->w && !p->pr && !p->f_zero && p->conversion == '%') ? ft_putnchar(' ', p->w - size - 1) : 0;
	(p->w && p->pr && !p->f_zero && p->w > p->pr) ? ft_putnchar(' ', p->w - p->pr) : 0;
	return (size);
}




int		ft_checkflag(f_list *p, int arg, int size, int val)
{
	int	temp;
	temp = arg;	
	p->ispos = 1;
	if (arg < 0)
	{
		temp *= -1;
		p->ispos = 2;
	}
	if (!p->f_minus)
	{
		ft_handleright(p, size);
		ft_handledigits(p, temp, val);
	}
	else if (p->f_minus)
	{
		ft_handleright(p, size);
		ft_handledigits(p, temp, val);
		ft_handleleft(p, size);
	}
	return(size);
}



