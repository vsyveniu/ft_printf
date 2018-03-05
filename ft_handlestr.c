
#include "includes/ft_printf.h"

void	ft_printchar(f_list *p, unsigned char c, int size)
{
	(p->w && !p->f_minus && !p->f_zero) ? ft_putcratchv2(' ', c, p->w - size) : 0;
	(p->w && p->f_minus) ? ft_putcratch(c, ' ', p->w - 1) : 0;
	(p->w && p->f_zero) ? ft_putcratch(c, '0', p->w - size) : 0;
	(!p->w) ? ft_putchar(c) : 0;
}


void	ft_putscratch(char c, char *str, int size)
{
	int i;

	i = 0;
	while(i < size)
	{
		write(1, &c, 1);
	i++;
	}
	ft_putstr(str);
}

void	ft_putscratch2(char c, char *str, int size)
{
	int i;

	i = 0;
	ft_putstr(str);
	while(i < size)
	{
		write(1, &c, 1);
	i++;
	}
}

void	ft_putnstr(char *str, int size)
{
	int i;

	i = -1;
	while (++i < size)
		ft_putchar(str[i]);
}

void	ft_putscratchv3(char c, char *str, int size1, int size2)
{
	ft_putnchar(c, size1);
	ft_putnstr(str, size2);
}

void	ft_putscratchv4(char *str, char c, int size1, int size2)
{
	ft_putnstr(str, size1);
	ft_putnchar(c, size2);
}

void	ft_putscratchv5(char c,int size2)
{
	ft_putchar(' ');
	ft_putnchar(c, size2);
}

void	ft_putscrutchvzero(char *str, char c, int size1, int size2)
{
	ft_putnchar(c, size1);
	ft_putnstr(str, size2);
}

int		ft_printstr(f_list *p, char *str, int size)
{
	if (!str)
		ft_putstr("(null)");
	
	(p->w && !p->pr && p->w >= size && !p->f_minus && !p->f_zero) ? ft_putscratch(' ', str, p->w - size) : 0;
	(p->w && !p->pr && p->w < size && !p->f_minus && !p->prcrutch &&!p->f_zero) ? ft_putstr(str) : 0;
	(p->w && !p->pr && p->w < size && !p->f_minus && p->prcrutch &&!p->f_zero) ? ft_putnchar(' ', p->w) : 0;


	(p->w && p->pr && p->w > p->pr && p->pr >= size && !p->f_minus &&!p->f_zero) ? ft_putscratch(' ', str, p->w - size) : 0;
	(p->w && p->pr && p->w < p->pr && p->pr < size && !p->f_minus &&!p->f_zero) ? ft_putnstr(str, p->pr) : 0;
	(p->w && p->pr && p->w > p->pr && p->pr < size && !p->f_minus &&!p->f_zero) ? ft_putscratchv3(' ', str, p->w - p->pr, p->pr) : 0;
	(p->w && p->pr && p->w == p->pr && p->w >= size && !p->f_minus &&!p->f_zero) ? ft_putscratch(' ', str, p->w - size) : 0;
	(p->w && p->pr && p->pr > p->w && p->pr >= size && !p->f_minus &&!p->f_zero) ? ft_putscratch(' ', str, p->w - size) : 0;



	(!p->w && p->pr && p->pr >= size && !p->f_minus) ? ft_putscratch(' ', str, p->w - size) : 0;
	(!p->w && p->pr && p->pr < size && !p->f_minus) ? ft_putnstr(str, p->pr) : 0;





	(p->w && !p->pr && p->w >= size && p->f_zero && !p->f_minus) ? ft_putscratch('0', str, p->w - size) : 0;
	(p->w && p->pr && p->w > p->pr && p->pr >= size && p->w >= size && p->f_zero && !p->f_minus) ? ft_putscratch('0', str, p->w - size) : 0;
	(p->w && p->pr && p->w > p->pr && p->pr < size && p->f_zero && !p->f_minus) ? ft_putscrutchvzero(str,'0' , p->w - p->pr, p->pr) : 0;
	(p->w && p->pr && p->w < p->pr && p->pr > size && p->f_zero && !p->f_minus) ? ft_putscratch('0', str, p->w - size) : 0;
	(p->w && p->pr && p->w == p->pr && p->pr > size && p->f_zero && !p->f_minus) ? ft_putscratch('0', str, p->w - size) : 0;
	(p->w && p->pr && p->w == p->pr && p->pr == size && p->f_zero && !p->f_minus) ? ft_putstr(str) : 0;



	(p->w && !p->pr && p->w >= size && p->f_minus) ? ft_putscratch2(' ', str, p->w - size) : 0;
	(p->w && p->pr && p->w > p->pr  && p->pr <= size && p->f_minus) ? ft_putscratchv4(str, ' ', p->pr, p->w - p->pr) : 0;

	(p->w && p->pr && p->w > p->pr  && p->pr > size && p->f_minus) ? ft_putscratch2( ' ', str , p->w - size) : 0;
	
	(p->w && p->pr && p->w == p->pr  && p->w >= size && p->f_minus) ? ft_putscratch2(' ', str, p->w - size) : 0;
	(p->w && p->pr && p->pr > p->w  && p->pr >= size && p->f_minus) ? ft_putscratch2(' ', str, p->w - size) : 0;
	(!p->w && p->pr && p->pr >= size && p->f_minus) ? ft_putstr(str) : 0;
	(!p->w && p->pr && p->pr < size && p->f_minus) ? ft_putnstr(str, p->pr) : 0;
	(!p->w && !p->pr) ? ft_putstr(str) : 0;





	/*(p->w && p->pr && p->w > p->pr && size >= p->pr && !p->f_minus) ? ft_putscratchv3(' ', str, p->w - p->pr, p->pr) : 0;
	//(p->w && p->pr && p->w > p->pr && p->pr >= size && !p->f_minus) ? ft_putscratch(' ', str, p->w - size) : 0;
	(p->w && p->pr && p->w > p->pr && size == 0 && !p->f_minus) ? ft_putnchar(' ', p->w) : 0;
	(p->w && p->pr && p->w > p->pr && p->pr <= size && p->f_minus) ? ft_putscratchv4(str, ' ', p->pr, p->w - p->pr) : 0;
	(p->w && p->pr && p->w > p->pr && p->pr > size && p->f_minus) ? ft_putscratch2(' ',str,p->w - size) : 0;
	//(p->w && p->pr && p->w > p->pr && p->f_minus) ? ft_putscratchv4(str, ' ', p->pr, p->w - p->pr) : 0;
	(p->w && p->pr && p->w > p->pr && p->f_minus && size == 0) ? ft_putscratchv5(' ', p->w - p->pr + 1) : 0; ///is it needed?

	(p->w && p->pr && p->pr >= p->w && p->pr > size && p->f_minus) ? ft_putscratch2(' ', str, p->w - size) : 0;
	(p->w && p->pr && p->w == p->pr && p->pr > size && !p->f_minus) ? ft_putscratch(' ', str, p->w - size) : 0; 
	(p->w && p->pr && p->pr > p->w && p->pr >= size && !p->f_minus) ? ft_putscratch(' ', str, p->w - size) : 0; 
	//(!p->w && p->pr) ? ft_putstr(str) : 0; ///// dont need it

	(p->w && p->f_zero) ? ft_putscratch('0', str, p->w - size) : 0;
	(p->w && !p->f_minus && !p->pr && !p->f_zero) ? ft_putscratch(' ', str, p->w - size) : 0;
	(p->w && p->f_minus && !p->pr && !p->f_zero) ? ft_putscratch2(' ', str, p->w - size) : 0;
	(p->w && p->w <= p->pr && p->pr < size) ? ft_putnstr(str, p->pr) : 0;
	(p->pr < size && !p->w) ? ft_putnstr(str, p->pr) : 0;
	(!p->w && !p->pr) ? ft_putstr(str) : 0;
	*/
	return (size);
}


void		ft_handlestr(f_list *p, void *arg, int size)
{
	if (!arg)
		if(p->conversion == 's' || p->conversion == 'S')
			ft_putstr("null");
	if (p->conversion == 'c' || p->conversion == 'C')
	{
		ft_printchar(p, (*(unsigned char*)arg), size);
	}
	if (p->conversion == 's' || p->conversion == 'S')
	{
		ft_printstr(p, (*(char**)arg), size);
	}
}