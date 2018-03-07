
#include "includes/ft_printf.h"


int 	ft_dsize(f_list *p, int r, int size)
{
	(p->f_plus && p->n == 1 && p->w <= size && !p->f_zero && 
	(p->c == 'd' || p->c == 'i')) ? r += 1 : 0;
	(p->n == 2 && (p->c == 'd' || p->c == 'i') && !p->w && !p->f_zero &&
	!p->pr && p->m != 2 && p->m != 3 &&  p->m != 4 && p->m != 5 && p->m != 6
	&& !p->crutchmark) ? r += 1 : 0;
	(p->n == 2 && (p->c == 'd' || p->c == 'i') && !p->w && !p->f_zero &&
	p->pr && p->m != 2 && p->m != 3 &&  p->m != 4 && p->m != 5 && 
	p->m != 6 && !p->crutchmark) ? r += 1 : 0;
	(p->n == 2 && (p->c == 'd' || p->c == 'i') && p->f_zero && !p->w) ? 
	r += 1 : 0;
	(p->n == 2 && (p->c == 'd' || p->c == 'i') && p->w && p->pr &&
	 p->w < p->pr && p->pr > size) ? r += 1 : 0;
	(p->n == 0 && (p->c == 'd' || p->c == 'i') && p->f_plus) ? 
	r += 1 : 0;

	return(r);
}

int 	ft_mainsize(f_list *p, int r, int s)
{
	(p->w && !p->pr && p->w >= s) ? r = p->w: 0;
	(p->w && !p->pr && p->w >= s && p->f_plus) ? r = p->w - 1: 0;
	(p->w && !p->pr && p->w >= s && p->n == 2 ) ? r = p->w: 0;
	(p->w && !p->pr && p->w == s ) ? r = p->w: 0;
	(!p->w && p->pr && p->pr >= s && p->c != '%') ? r = p->pr: 0;
	(p->w && p->pr && p->w > p->pr  && p->w >= s && p->n == 1) ? r = p->w : 0;
	(p->w && p->pr && p->w > p->pr  && p->w >= s && p->n == 2) ? r = p->w : 0;
	(p->w && p->pr && p->pr > p->w  && p->pr >= s && p->n == 1) ? 
	r = p->pr : 0;
	(p->w && p->pr && p->pr > p->w  && p->pr >= s && p->n == 2) ? r = p->pr: 0;
	(p->w && p->pr && p->pr > p->w  && p->pr < s && p->n == 2) ? r = s + 1: 0; 
	(p->w && p->pr && p->pr < p->w  && p->pr < s && p->n == 2) ? r = s + 1: 0;
	(p->w && p->pr && p->pr == p->w  && p->pr >= s && p->w >= s && p->n == 1)
	? r = p->pr : 0;
	(p->w && p->pr && p->pr == p->w  && p->pr >= s && p->w >= s && p->n == 2)
	? r = p->pr + 1: 0;
	(p->w && p->pr && p->w > p->pr  && p->pr < s && p->w >= s && p->n == 1)
	? r = p->w : 0;
	(p->w && p->pr && p->w > p->pr  && p->pr < s && p->w >= s && p->n == 2)
	? r = p->w : 0;
	(!p->w && p->pr && p->pr < s && p->n == 1) ? r = s : 0;
	(!p->w && p->pr && p->pr < s && p->n == 2 && p->c != 'd' &&
	p->c != 'i' && p->c != 'D') ? r = s + 1: 0;

	return (r);
}

int 	ft_getpsize(f_list *p, int r, int s)
{
	(p->f_oct && !p->w && !p->pr && (p->c == 'x' || p->c == 'X')
	 && p->n != 0) ? r += 2 : 0;
	(p->f_oct && !p->w && p->pr && (p->c == 'x' || p->c == 'X')
	 && p->n != 0) ? r += 2 : 0;
	(p->w && p->pr &&  p->w >= s && p->w > p->pr && p->n == 0) ? r = p->w : 0;
	(p->c == 'p' && !p->pr && p->w && p->w <= s) ? r += 2 : 0;
	(p->c == 'p' && p->pr && p->w && p->pr > p->w && p->pr >= s) ? r += 2 : 0;
	(p->c == 'p' && p->pr && p->w && p->pr == p->w && p->pr >= s) ? r += 2 : 0;
	(p->c == 'p' && p->pr && p->w && p->pr == p->w && p->pr < s) ? r += 2 : 0;
	(p->c == 'p' && !p->w && p->pr >= s) ? r += 2 : 0;
	(p->c == 'p' && !p->w && !p->pr && !p->prc) ? r += 2 : 0;
	(p->c == 'p' && p->w == s + 1) ? r += 1 : 0;
	((p->c == 'o' || p->c == 'O') && p->f_oct && !p->w &&
	 !p->pr && p->n != 0) ? r += 1 : 0;

	return (r);
}