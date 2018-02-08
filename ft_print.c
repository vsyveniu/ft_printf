
#include "includes/ft_printf.h"


void	ft_handlepos(f_list *p, int size)
{
	//(p->f_plus) ? size += 1 : 0;
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
	(p->w && !p->pr && p->f_zero && !p->f_minus && p->ispos == 1 && !p->w) ? ft_putnchar('0', p->w - size) : 0;
	(p->w && !p->pr && p->f_zero && !p->f_minus && p->ispos == 1 && p->f_plus) ? ft_putcratch('+','0', p->w - size - 1) : 0;
	(p->w && !p->pr && p->f_zero) ? ft_putnchar('0', p->w - size) : 0;
	(!p->w && p->pr) ? ft_putnchar('0', p->pr - size): 0;	
	(p->w && p->conversion == '%' && !p->f_minus) ? ft_putnchar(' ', p->w - size) : 0;
	(p->w && !p->pr && !p->f_zero && !p->f_minus && p->conversion != '%') ? ft_putnchar(' ', p->w - size) : 0;
	(p->f_plus && !p->f_zero && !p->pr && p->ispos == 1) ? ft_putchar('+') : 0;
	//(p->f_plus) ? printf("picha\n") : 0;
	(p->f_plus && p->ispos != 1 && p->ispos != 2) ? ft_putchar('+') : 0;
}

void	ft_handleneg(f_list *p, int size)
{
	(p->ispos == 2) ? size += 1 : 0;
	(p->w && p->pr && p->w > p->pr && p->f_zero && !p->f_minus) ? ft_puttriplecratch('-', '0', p->w - p->pr - 1, p->pr - size + 1) : 0; 
	(p->w && p->pr && p->w > p->pr && p->f_zero && p->f_minus) ? ft_putcratch('-', '0', p->w - 1 - p->pr)  : 0;
	(p->w && p->pr && p->w > p->pr && !p->f_zero && !p->f_minus) ? ft_puttriplecratch('-', '0', p->pr - size, p->w - p->pr) : 0;
	(p->w && p->pr && p->w > p->pr && !p->f_zero && p->f_minus) ? ft_putcratch('-', '0', p->w - p->pr) : 0;
	(p->w && p->pr && p->w < p->pr) ? ft_putcratch('-','0',p->pr - size + 1) : 0;
	(p->w && !p->pr && p->f_zero) ? ft_putcratch('-','0',p->w - size) : 0;
	(!p->w && p->pr && !p->f_zero && !p->f_minus) ? ft_putcratch('-','0',p->pr - size + 1) : 0;
	(!p->w && p->pr && !p->f_zero &&  p->f_minus) ? ft_putcratch('-','0',p->pr - size + 1) : 0;
	(p->w && !p->pr && !p->f_zero && !p->f_minus) ? ft_putnchar(' ', p->w - size ) : 0;
	(p->w && !p->pr && !p->f_zero) ? ft_putchar('-') : 0;
	//(!p->w && !p->pr) ? ft_putchar('-') : 0;//there is a fucking bug for negative num !!!!!!!!!!!! ---------------->>>>>>>>>>>>>>>>>you must  fucking fix it picha!

}

int	ft_handleright(f_list *p, int size)
{
	//printf("--------------->>>>>>>>>>>. %d\n", p->ispos);	
	if (p->ispos == 2)
	{
		ft_handleneg(p, size);
	}
	ft_handlepos(p, size);
	return (size); ///this is void!!!!!!!!!!
}

int	ft_handleleft(f_list *p, int size)
{
	(p->f_plus) ? size += 1 : 0;
	(p->ispos == 2) ? size += 1 : 0;
	(p->w && p->pr && p->w > p->pr && p->f_zero) ? ft_putnchar(' ', p->w - p->pr) : 0;
	(p->w && !p->pr && !p->f_zero && p->conversion != '%') ? ft_putnchar(' ', p->w - size) : 0;
	(p->w && !p->pr && !p->f_zero && p->conversion == '%') ? ft_putnchar(' ', p->w - size) : 0;
	(p->w && p->pr && !p->f_zero && p->w > p->pr) ? ft_putnchar(' ', p->w - p->pr) : 0;
	return (size); /// this is void!!
}




int		ft_checkflag(f_list *p, void *arg, int size, int val)
{
	long long	temp;
	//printf("fuck\n");
	temp = (long long)arg;
	//printf("fuck\n");
	/*if ((int)arg < 0)
	{
		temp *= -1;
		p->ispos = 2;
	}*/
	if (!p->f_minus)
	{
		ft_handleright(p, size);
		ft_handledigits(p, arg, val);
	}
	else if (p->f_minus)
	{
		ft_handleright(p, size);
		ft_handledigits(p, arg, val);
		ft_handleleft(p, size);
	}
	return(size);
}



