
#include "includes/ft_printf.h"


void	ft_handlepercent(f_list *p, int s)
{
	(p->w && !p->f_l && !p->f_zero) ? ft_putnchar(' ', p->w - s) : 0;
	(p->w && p->f_zero && !p->f_l) ? ft_putnchar('0', p->w - s) : 0;
}

void	ft_handlerightsideinleft(f_list * p, int s)
{
	(p->w > p->pr && p->pr >= s && !p->f_plus && p->f_l && p->f_zero) ? 
	ft_putnchar('0',p->pr -s) : 0;
	(p->w && p->pr && p->w > p->pr  && p->w > s && p->pr >= s && 
	p->f_plus && p->f_l) ? ft_putcratch('+','0', p->pr - s) : 0;
	(p->w && p->pr && p->w > p->pr && 
	!p->f_plus) ? ft_putnchar('0', p->pr - s) : 0 ;
	(p->w && p->pr && p->pr > p->w) ? ft_putnchar('0', p->pr - s) : 0;
}

void	ft_handlep(f_list *p, int s)
{
	(!p->w && !p->pr) ? write(1, "0x", 2) : 0;
	(p->w && p->f_zero && !p->f_l) ? 
	ft_hash(p, '0', p->w - s - 2) : 0;
	(p->w && p->pr && p->w > p->pr && p->w >= s && !p->f_l) ? 
	ft_hashv3(p, '0', p->w - s - 2, p->pr - s) : 0;
	(p->w && p->pr && p->w > p->pr && p->w >= s 
	&& p->f_l) ? ft_hash(p, '0', p->pr - s) : 0;
	(p->w && p->pr && p->w < p->pr && p->pr >= s ) ? 
	ft_hash(p, '0', p->pr - s) : 0;
	(!p->w && p->pr && p->pr >= s) ? 
	ft_hash(p, '0', p->pr - s) : 0;
	(p->w && p->pr && p->pr == p->w) ? 
	ft_hash(p, '0', p->pr - s) : 0;
	(p->w && !p->pr && p->w >= s && !p->f_l 
	&& !p->f_zero) ? ft_hashv2(p, ' ', p->w - 2 - s) : 0;
	(p->w && !p->pr && p->w >= s && p->f_l) ? write(1, "0x", 2) : 0;
}

void	ft_handlehash(f_list *p, int s)
{
	((p->c == 'o') || (p->c == 'O')) ? s += 1 : 0;
	(p->w && !p->pr && p->w >= s && !p->f_l && p->c != 'x' &&
	p->c != 'X') ? ft_hashv2(p, ' ', p->w - s - 1) : 0;
	(p->w && !p->pr && p->w >= s && !p->f_l && (p->c == 'x' ||
	p->c == 'X') && !p->f_zero) ? ft_hashv2(p, ' ', p->w - s - 2) : 0;
	(p->w && !p->pr && p->w >= s && p->f_l) ? ft_printhash(p->c) : 0;
	(!p->w && p->pr && p->pr >= s && !p->f_l && p->n != 0) ?
	ft_hashv4(p, '0', p->pr - s) : 0;
	(!p->w && p->pr && p->pr >= s && !p->f_l && p->n == 0) ? 
	ft_putnchar('0', p->pr - 1) : 0;
	(!p->w && p->pr && p->pr >= s && p->f_l) ? ft_hash(p, '0', p->pr - s) : 0;
	(p->w && p->pr && p->w > p->pr && p->w >= s && (p->c == 'x' || 
	p->c == 'X')) ? ft_hashv3(p, '0',p->w - p->pr - 2, p->pr - s) : 0;
	(p->w && p->pr && p->w > p->pr && p->w >= s && (p->c == 'o' || 
	p->c == 'O') && !p->f_l) ? 
	ft_hashv3(p, '0',p->w - p->pr, p->pr - s) : 0;
	(p->w && p->pr && p->w > p->pr && p->w >= s && (p->c == 'o' || 
	p->c == 'O') && p->f_l) ? ft_printhash(p->c) : 0;
	(p->w && p->pr && p->w == p->pr) ? 
	ft_hashv3(p, '0',p->w - p->pr, p->pr - s) : 0;
	(p->w && p->pr && p->pr > p->w && p->pr >= s) ? 
	ft_hashv3(p, '0',p->w - p->pr, p->pr - s) : 0;
	(!p->w && !p->pr && p->n != 0) ? ft_printhash(p->c) : 0;
	(p->w && !p->pr && p->w >= s && p->f_zero && !p->f_l) ? 
	ft_hash(p, '0', p->w - s - 2) : 0;
}