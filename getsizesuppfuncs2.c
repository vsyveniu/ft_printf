
#include "includes/ft_printf.h"


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


int		getunsignsize(f_list *p, void *arg, uintmax_t systembase, int s)
{
	uintmax_t temp;

	temp = (uintmax_t)arg;
	if (p->m == 2  && p->c != 'O' && p->c != 'U')
		return (s = ft_hhbase((signed char)arg, systembase, s, p));
	if (p->m == 1 && p->c != 'U')
		return (s = ft_hbase((unsigned short)arg, systembase, s, p));
	if (p->c == 'x' || p->c == 'X' || p->c == 'p' ||
	 p->c == 'o' || p->c == 'O')
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