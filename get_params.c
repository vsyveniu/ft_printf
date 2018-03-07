
#include "includes/ft_printf.h"

int		ft_isflag(char c)
{
	if (c == '#' || c == '+' || c == '-' || c == ' ' || c == '0')
		return (1);
	return (0);
}

int			ft_checkisnorepeat(char cinlist, char c)
{
	if (cinlist == c)
	{
		return (0);
	}
	return (1);
}

f_list		*ft_getflag(char c, f_list *p)
{
	if (c == '#' && (ft_checkisnorepeat(p->f_oct, '#'))) 
		p->f_oct = '#';
	if (c == '+' && (ft_checkisnorepeat(p->f_plus, '+'))) 
		p->f_plus = '+';
	if (c == '-' && (ft_checkisnorepeat(p->f_l, '-'))) 
		p->f_l = '-';
	if (c == ' ' && (ft_checkisnorepeat(p->f_space, ' '))) 
		p->f_space = ' ';
	if (c == '0' && (ft_checkisnorepeat(p->f_space, '0')))
		p->f_zero = '0';
	return (p);
}


int			ft_getwidth(const char *format, int *i)
{
	int	temp;

	temp = 0;
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		temp = (temp * 10) + (format[*i] - 48);
		(*i)++;
	}
	return (temp);
}

int			get_precision(const char *format, int *i)
{
	int	temp;

	temp = 0;
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		temp = (temp * 10) + (format[*i] - 48);
		(*i)++;
	}
	return (temp);
}

