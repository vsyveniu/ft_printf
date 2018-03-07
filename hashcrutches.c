
#include "includes/ft_printf.h"


void 	ft_hash(f_list *p, char c, int size)
{
	if ((p->c == 'x' || p->c == 'X') || p->c == 'p')
	{
		ft_printhash(p->c);
		ft_putnchar(c, size);
	}
	else if (p->c == 'o' || p->c == 'O')
	{
		ft_printhash(p->c);
		ft_putnchar(c, size - 1);
	}
}

void 	ft_hashv2(f_list *p, char c, int size)
{
	if ((p->c == 'x' || p->c == 'X') || p->c == 'p')
	{
		ft_putnchar(c, size);
		ft_printhash(p->c);
	}
	else if (p->c == 'o' || p->c == 'O')
	{
		ft_putnchar(c, size + 1);
		ft_printhash(p->c);

	}
}

void 	ft_hashv4(f_list *p, char c, int size)
{
	if ((p->c == 'x' || p->c == 'X') || p->c == 'p')
	{
		ft_printhash(p->c);
		ft_putnchar(c, size);
	}
	else if (p->c == 'o' || p->c == 'O')
	{
		ft_putnchar(c, size);
		ft_printhash(p->c);

	}
}

void 	ft_hashv3(f_list *p, char c,  int size, int size2)
{
	if ((p->c == 'x' || p->c == 'X') || p->c == 'p')
	{
		ft_putnchar(' ', size);
		ft_printhash(p->c);
		ft_putnchar(c, size2);
	}
	else if (p->c == 'o' || p->c == 'O')
	{
		ft_putnchar(' ', size);
		ft_printhash(p->c);
		ft_putnchar(c, size2);
	}

	
}

void 	ft_hashleft(f_list *p, char c, int size)
{
	ft_printhash(p->c);
	ft_putnchar(c, size);
}