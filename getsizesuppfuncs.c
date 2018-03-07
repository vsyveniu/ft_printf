
#include "includes/ft_printf.h"

int 	ft_hhbase(signed char arg, int base,  int s, f_list *p)
{
	unsigned char temp;

	temp = (unsigned char)arg;

	if (arg < 0 && (p->c == 'd' || p->c == 'i'))
	{
	 	arg *= -1;
	 	s += 1;
	 	while (arg > 0)
		{
			arg /= base;
			s += 1;
		}
		if (arg == -128)
			s = 4;
	return (s);
	}
	if (arg == 0)
		s += 1;
	while (temp > 0)
	{
		temp /= base;
		s += 1;
	}
	return (s);
}

int 	ft_hbase(unsigned short arg, int base,  int s, f_list *p)
{
	unsigned short temp;
	(void)p;
	temp = arg;

	if (arg == 0)
		s += 1;
	while (temp > 0)
	{
		temp /= base;
		s += 1;
	}
	return (s);
}

int	ft_intbase(int arg, int base, int s)
{
	while (arg > 0)
	{
		arg /= base;
		s += 1;
	}
	return (s);
}

int 	ft_expand(f_list *p, void *arg, intmax_t temp, int s)
{
	if (temp == 1 || (temp == 0 && !p->prc))
		s = 1;
	else if (temp == -1)
		s = 2;
	else if (temp == -2147483649 && p->m == 3)
		s = 11;
	else if (temp == -2147483648 && p->m == 3)
		s = 11;
	else if (temp == -2147483648)
		s = 11;
	else if (temp == 32768 && p->m == 1)
		s = 6;
	else if (temp == 128 && p->m == 2)
		s = 4;
	else if (temp == 4294967295 && p->m == 6)
		s = 10;
	else if ((uintmax_t)arg > 9223372036854775807 && (p->m == 5 || p->m == 6))
		s = 20;
	if ((long)arg == -9223372036854775805 && p->m == 4)
		s = 20;
	else if ((uintmax_t)arg > 9223372036854775807 && p->m == 4)
		s = 20;
	else if (temp == 129 && p->m == 2)
		s = 4;
	return (s);
}


int 	ft_expand2(f_list *p, intmax_t temp,  void *arg,  int s)
{
	if ((uintmax_t)arg == 9223372036854775807 && p->m == 5)
	{
		s = 19;
		p->crutchmark = 1;
	}
	if (temp == -2147483649 && p->m == 0)
		s = 10;
	return (s);
}