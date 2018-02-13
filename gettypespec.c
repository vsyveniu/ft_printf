
#include "includes/ft_printf.h"

static int		ft_handlethisbitcheshhandll(char *format, int index)
{
	int	temp;

	temp = 0;
	if (format[index] == 'h')
	{
		if (format[index - 1] == 'h')
		{
			temp = 2;
			return (temp);
		}
		temp = 1;	
	}
	if (format[index] == 'l')
	{
		if (format[index - 1] == 'l')
		{
			temp = 4;
			return (temp);
		}
		temp = 3;
	}
	return(temp);
}


int			get_mod(char *format, int index) // is it bettter to fill struct with int?
{
	int temp;  //is it may be int?

	temp = 0;
	if (format[index] == 'h' || format[index] == 'l')
	{
		temp = ft_handlethisbitcheshhandll(format, index);
		return (temp);
	}
	if (format[index] == 'j')
	{
		temp = 5;
		return(temp);
	}
	if (format[index] == 'z')
	{
		temp = 6;
		return (temp);
	}
	temp = 0;
	return (temp);
}

char			get_conversion(char format)
{
	char temp;

	if (format == 's' || format == 'S' || format == 'd' 
		|| format == 'd' || format == 'D' || format == 'i'
		|| format == 'o' || format == 'O' || format == 'u'
		|| format == 'U' || format == 'x' || format == 'X'
		|| format == 'c' || format == 'C' || format == 'b'
		|| format == 'r' || format == 'k' || format == 'f'
		|| format == '%' || format == 'p')
	{
		temp = format;
	}
	else
		temp = 0;
	return (temp);
}

