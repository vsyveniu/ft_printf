
#include "includes/ft_printf.h"


int		ft_getsignsize(f_list *p, void *arg, intmax_t systembase, int s)
{
	intmax_t temp;

	temp = (intmax_t)arg;
	if (p->m == 2 && p->c != 'D')
		return (s = ft_hhbase((signed char)arg, systembase, s, p));
	else
	{	
		s = ft_base(temp, systembase, s);
		s = ft_expand(p, arg, temp, s);
		s = ft_expand2(p, temp, arg, s);
	

	}
	return (s);
}


int		ft_getintsize(void *arg, int systembase, int s, f_list *p)
{
	int temp;

	temp = (int)arg;
	if (temp == 1 || temp == 0)
		s = 1;
	else if (temp == -2147483648)
	{
		p->crutchmark = 1;
		s = 11;
	}
	else if (temp == -129 && p->m == 2)
	{
		s = 3;
		p->crutchmark = 1;
	}
	else if (p->m == 2)
		return(s = ft_hhbase((signed char)arg, systembase, s, p));
	else if (temp < 0)
	{
		temp *= -1;
		s = ft_intbase(temp, systembase, s);
	}
	else
		s = ft_intbase(temp, systembase, s);
	return (s);
}



int 	ft_gethexsize(f_list *p, uintmax_t temp, uintmax_t systembase, int s)
{
	if (temp == 4294967296)
	{
		s = 9;
		p->crutchmark = 1;
		if (p->m == 1 || p->m == 2 || p->m == 0)
			s = 1;
		return (s);
	}
	if (temp == 0 && !p->prc)
		s = 1;
	if (temp == 0 && p->f_oct && p->prc && (p->c == 'o' || p->c == 'O'))
		s += 1;
	else
		s = ft_unsbase(temp, systembase, s);
	return (s);
}

int		getunsignsize(f_list *p, void *arg, uintmax_t systembase, int s)
{
	uintmax_t temp;

	temp = (uintmax_t)arg;
	if (p->m == 2  && p->c != 'O' && p->c != 'U')
		return (s = ft_hhbase((signed char)arg, systembase, s, p));
	if (p->m == 1 && p->c != 'U')
		return (s = ft_hbase((unsigned short)arg, systembase, s, p));
	if (p->c == 'x' || p->c == 'X' || p->c == 'p' || p->c == 'o' || p->c == 'O')
		return (s = ft_gethexsize(p,  temp, systembase, s));
	if (temp == 0 && p->pr > 0)
		s = 1;
	if (temp == 0 && !p->w && !p->pr && !p->prc)
		s = 1;
	else
	{
		if (temp == 4294967296 && p->m == 0 && p->c == 'u')
			s = 1;
		else if (temp == 4294967296 && p->m == 5)
			s = 10;
		else
			s = ft_unsbase(temp, systembase, s);
	}
	return (s);
}


int		ft_unsbase(uintmax_t arg, uintmax_t base, int s)
{
	while (arg > 0)
	{
		arg /= base;
		s += 1;
	}
	return (s);
}

int	ft_base(intmax_t arg, intmax_t base, int s)
{

	while (arg > 0)
	{
		arg /= base;
		s += 1;
	}
	return (s);
}


int 	ft_getshexoctbi(f_list *p, void  *arg)
{
	int 			s;
	long long 		systembase;

	s = 0;
	(p->c == 'x' || p->c == 'X') ? systembase = 16 : 0;
	(p->c == 'o' || p->c == 'O') ? systembase = 8 : 0;
	(p->c == 'd' || p->c == 'i' || p->c == 'D') ? systembase = 10 : 0;
	(p->c == 'u' || p->c == 'U') ? systembase = 10 : 0;
	(p->c == 'b') ? systembase = 2 : 0;
	(p->c == 'p') ? systembase = 16 : 0;
	if (p->c == 'u' || p->c == 'U' || p->c == 'x' ||
		p->c == 'X' || p->c == 'p' || p->c == 'o' || p->c == 'O')
	{
		s = getunsignsize(p, arg, (unsigned long long)systembase, s);
	}
	else
	{
		if ((int)arg < 0 && (p->m == 0 || p->m == 1 || p->m == 2) && (p->c == 'd' || p->c == 'i'))
			return (s = ft_getintsize(arg, systembase, s, p));
		else
			s = ft_getsignsize(p, arg, systembase, s);		
	}
	return (s);
}


int		ft_getargsize(f_list *p, void *arg)
{
	int		s;

	s = 0;
	p->n = 0;
	if ((int)arg > 0)
		p->n = 1;
	if ((int)arg < 0)
		p->n = 2;
	if (p->c == 's' || p->c == 'S' || p->c == 'c'
		|| p->c == 'C')
		s = ft_getstrsize(p, arg, s);
	if (p->c == 'x' || p->c == 'X' || p->c == 'b' || p->c == 'o'
		|| p->c == 'O'
		|| p->c == 'd' || p->c == 'i'|| p->c == 'u' || p->c == 'U'
		|| p->c == 'p' || p->c == 'D')
	{
			s = ft_getshexoctbi(p, arg);
			return (s);
	}
	(p->c == '%') ? s = 1 : 0;
	return (s);
}

/*int		ft_checkmodifiers(f_list *p)
{
	int val;

	val = 0;
	if ( p->m && ft_strcmp(p->m, "h") == 0)
		return(val = 1);
	if (p->m && ft_strcmp(p->m, "hh") == 0)
		return(val = 2);
	if (p->m && ft_strcmp(p->m, "l") == 0)
		return(val = 3);
	if (p->m && ft_strcmp(p->m, "ll") == 0)
		return(val = 4);
	if (p->m && ft_strcmp(p->m, "j") == 0)
		return(val = 5);
	if (p->m && ft_strcmp(p->m, "z") == 0)
		return(val = 6);
	return(val);
}*/

int		ft_printsize(f_list *p, int s)
{	
	int r;

	r = s;
	r = ft_mainsize(p, r, s);
	(p->f_space && p->n == 1 && !p->f_plus && p->w < s && p->c != '%' &&
	(p->c == 'd' || p->c == 'i')) ? r += 1 : 0;
	(p->f_plus && p->n == 1 && p->f_zero) ? r += 1 : 0;
	r = ft_dsize(p, r, s);
	r = ft_getpsize(p, r, s);
	
	return (r);
}

