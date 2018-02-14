
#include "includes/ft_printf.h"

static int		ft_handlethisbitcheshhandll(char *format, int *i)
{
	int	temp;

	temp = 0;
	if (format[*i] == 'h')
	{
		if (format[*i - 1] == 'h')
		{
			temp = 2;
			(*i)++;
			return (temp);
		}
		temp = 1;	
	}
	if (format[*i] == 'l')
	{
		if (format[*i - 1] == 'l')
		{
			temp = 4;
			(*i)++;
			return (temp);
		}
		temp = 3;
	}
	return(temp);
}


int			get_mod(char *format, int *i) // is it bettter to fill struct with int?
{
	int temp;  //is it may be int?

	temp = 0;
	if (format[*i] == 'h' || format[*i] == 'l')
	{
		temp = ft_handlethisbitcheshhandll(format, i);
		(*i)++;
		return (temp);
	}
	if (format[*i] == 'j')
	{
		temp = 5;
		(*i)++;
		return(temp);
	}
	if (format[*i] == 'z')
	{
		temp = 6;
		(*i)++;
		return (temp);
	}
	temp = 0;
	return (temp);
}

char			get_conversion(char *format, int *i)
{
	char temp;

	if (format[*i] == 's' || format[*i] == 'S' || format[*i] == 'd' 
		|| format[*i] == 'd' || format[*i] == 'D' || format[*i] == 'i'
		|| format[*i] == 'o' || format[*i] == 'O' || format[*i] == 'u'
		|| format[*i] == 'U' || format[*i] == 'x' || format[*i] == 'X'
		|| format[*i] == 'c' || format[*i] == 'C' || format[*i] == 'b'
		|| format[*i] == 'r' || format[*i] == 'k' || format[*i] == 'f'
		|| format[*i] == '%' || format[*i] == 'p')
	{
		temp = format[*i];
	}
	else
		temp = 0;
	return (temp);
}

