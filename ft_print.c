
#include "includes/ft_printf.h"


void	ft_handlepos(f_list *p, void *arg, int size)
{
	if ((p->w || p->pr) && !p->f_plus && !p->f_zero && !p->f_space) 
		ft_handlepos1(p, size);
	else if ((p->w || p->pr) && p->f_plus && !p->f_zero )
		ft_handlepos2(p, size);
	else if ((p->w || p->pr) && p->f_zero && !p->f_plus &&
	 !p->f_l && !p->f_space)
		ft_handlepos3(p, size);
	else if ((p->w || p->pr) && p->f_zero && p->f_plus && !p->f_space)
		ft_handlepos4(p, size);
	else if ((p->w || p->pr) && p->f_space && !p->f_plus)
		ft_handlepos5(p, size);
	else if (!p->w && !p->pr && p->f_space && !p->f_plus && p->n != 2 &&
	(p->c == 'd' || p->c == 'i'))
		ft_putchar(' ');
	else if(!p->w && !p->pr && p->f_plus && (p->n == 1 || p->n == 0) &&
	(p->c == 'd' || p->c == 'i'))
		ft_putchar('+');
	else if ((uintmax_t)arg > 0 && p->n == 0 && p->m == 5 &&
	(p->c == 'd' || p->c == 'i'))
		ft_putchar('-');
}


void	ft_handleleft(f_list *p, int size)
{
	(p->c == 'p') ? size += 2 : 0;
	(p->n == 2 && (p->c == 'd' || p->c == 'i')) ? size += 1 : 0;
	(p->f_oct && (p->c == 'x' || p->c == 'X')) ? size += 2 : 0;
	(p->f_oct && (p->c == 'o' || p->c == 'O')) ? size += 1 : 0;
	(p->w && !p->pr && !p->f_oct) ? ft_putnchar(' ', p->w - size) : 0;
	(p->w && p->pr && p->w > p->pr && p->pr >= size && !p->f_oct && !p->f_plus 
	&& p->c != 'p') ? ft_putnchar(' ', p->w - p->pr) : 0;
	(p->w && p->pr && p->w > p->pr && p->pr >= size && !p->f_oct && !p->f_plus 
	&& p->c == 'p') ? ft_putnchar(' ', p->w - p->pr - 2) : 0;
	(p->w && p->pr && p->w > p->pr && p->pr >= size && !p->f_oct && p->f_plus)
	? ft_putnchar(' ', p->w - p->pr - 1) : 0;
	(p->w && p->pr && p->w > p->pr && p->pr <= size && !p->f_oct) ? 
	ft_putnchar(' ', p->w - size) : 0;
	(p->w && !p->pr && p->w >= size && p->f_oct) ? 
	ft_putnchar(' ', p->w - size) : 0;
	(p->w && p->pr && p->w > p->pr && p->f_oct) ? 
	ft_putnchar(' ', p->w - size) : 0;
	(p->w && !p->pr && p->w > p->pr && p->f_oct && !p->f_l) ? 
	ft_putnchar(' ', p->w - p->pr - 2) : 0;
}

void	ft_handleneg(f_list *p, int size)
{
	(p->w && !p->pr && p->w >= size && !p->f_zero 
	&& !p->f_l) ? ft_putcratchv2(' ', '-', p->w - size - 1) : 0;
	(p->w && !p->pr && p->w >= size 
	&& !p->f_zero && p->f_l) ? ft_putchar('-'): 0;
	(p->w && !p->pr && p->w >= size && p->f_zero 
	&& !p->f_l) ? ft_putcratch('-', '0', p->w - size - 1) : 0;
	(p->w && !p->pr && p->w >= size 
	&& p->f_zero && p->f_l) ? ft_putchar('-') : 0;
	(p->pr && !p->w && p->pr >= size) ? 
	ft_putcratch('-','0', p->pr - size) : 0;
	(p->w && p->pr && p->w > p->pr && p->pr > size) ? 
	ft_tcrutch('-', '0', p->w - p->pr - 1, p->pr - size) : 0;
	(p->w && p->pr && p->w > p->pr 
	&& p->pr == size) ? ft_putcratchv2(' ', '-', p->w - size - 1) : 0;
	(p->w && p->pr && p->w > p->pr && p->pr < size &&
	!p->f_l) ? ft_putcratchv2(' ', '-', p->w - size - 1) : 0;
	(p->w && p->pr && p->w > p->pr 
	&& p->pr < size && p->f_l) ? ft_putchar('-') : 0;
	(p->w && p->pr && p->pr > p->w) ? 
	ft_putcratch('-','0', p->pr - size) : 0;
	(p->w && p->pr && p->w == p->pr) ? 
	ft_putcratch('-', '0', p->pr - size) : 0;
	(!p->w && p->pr && p->pr < size) ? ft_putchar('-') : 0;
 	(!p->w && !p->pr && !p->crutchmark && p->m != 6 && p->m != 2 
 	&& p->m != 1 && p->c != 'D') ? ft_putchar('-') : 0;
}


void	ft_handleright(f_list *p, void *arg, int size)
{
	if (p->f_oct && (p->c == 'x' || p->c == 'X' ||
	 p->c == 'o' || p->c == 'O'))
	{
		ft_handlehash(p, size);
	}
	else if (p->c == 'p')
		ft_handlep(p, size);
	else if (p->c == '%')
		ft_handlepercent(p, size);
	else if (p->n == 2 && p->c != 'x' && p->c != 'X' &&
	 p->c != 'u' && p->c != 'U' && p->m != 3 && p->m != 4 
	 && p->c != 'o' && p->c != 'O' && p->c != 'p')
	{
		ft_handleneg(p, size);
	}
	else
		ft_handlepos(p, arg, size);
}

int		ft_deepprint(f_list *p, void *arg, int size)
{
	if (p->f_l)
	{
		ft_handleright(p, arg, size);
		ft_handledigits(p, arg, p->m);
		ft_handleleft(p, size);
	}
	else
	{
		ft_handleright(p, arg, size);
		ft_handledigits(p, arg, p->m);
	}
	return(size);
}



