
#include "includes/ft_printf.h"

int 	ft_getstrsize(f_list *p, void *arg, int s)
{
	if (!arg && (p->c == 's' || p->c == 'S'))
		s = 6;
	else if (!arg && (p->c == 'c'|| p->c =='C'))
		s = 1;
	else if(arg && (p->c == 's' || p->c == 'S'))
		s = ft_strlen((char*)arg);
	else if (arg && (p->c == 'c' || p->c == 'C'))
		s = 1;
	return (s);
}

int		ft_printstrsize(f_list *p, void *arg, int s)
{
	int r;

	r = 0;
	if (!arg && (p->c != 'c' || p->c != 'C'))
		r = 6;
	if (!arg && p->prc && p->w && (p->c != 's' || p->c != 'S'))
		r = p->w;
	( p->w && p-> pr && p->w > p->pr) ? r = p->w : 0;
	(!p->w && p->pr && p->pr < s) ? r = p->pr : 0;
	(p->w && p->pr && p->w == p->pr && p->pr > s) ? r = p->w : 0;
	(p->w && p->pr && p->pr > p->w && p->pr >= s) ? r = p->w : 0;
	(p->w && p->pr && p->pr > p->w && p->w < s &&p->pr >= s) ? r = s: 0;
	(p->w && p->pr && p->pr > p->w && p->pr < s) ? r = p->pr : 0;
	(p->w && !p->pr && p->prc) ? r = p->w : 0;
	(p->w && !p->pr && p->w >= s) ? r = p->w : 0;
	(p->w && !p->pr && p->w < s && !p->prc) ? r = s : 0;
	(!p->w && p->pr && p->pr > s) ? r = s : 0;
	(!p->w && p->pr && p->pr == s) ? r = p->pr : 0;
	(!p->w && p->pr && p->pr < s) ? r = p->pr : 0;
	(!p->w && !p->pr) ? r = s : 0;
	(p->w && p->f_zero && p->w > p->pr && p->w > s) ? r = p->w : 0;
	(p->w && p->f_zero && p->w < p->pr && p->pr > s) ? r = p->w : 0;
	(p->w && p->f_zero && p->w < p->pr && p->w < s) ? r = s : 0;
	(p->w && p->f_zero && p->w == p->pr && p->w == s) ? r = s : 0;
	return (r);
}

