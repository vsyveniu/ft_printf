
#include "includes/ft_printf.h"

static int		ft_handlethisbitcheshhandll(const char *format, int *index, char c)
{
	int	temp;

	temp = 0;
	if (c == 'h')
	{
		if (format[*index + 1] == 'h')
		{
			temp = 2;
			(*index)++;
			return (temp);
		}
		temp = 1;	
	}
	else if (c == 'l')
	{
		if (format[*index + 1] == 'l')
		{
			temp = 4;
			(*index)++;
			return (temp);
		}
		temp = 3;
	}
	return(temp);
}


int			get_mod(const char *format, int *index) // is it bettter to fill struct with int?
{
	int temp;  //is it may be int?

	temp = 0;
	if (format[*index] == 'h' || format[*index] == 'l')
	{
		temp = ft_handlethisbitcheshhandll(format, index, format[*index]);
		(*index)++;
		return (temp);
	}
	if (format[*index] == 'j')
	{
		temp = 5;
		(*index)++;
		return(temp);
	}
	if (format[*index] == 'z')
	{
		temp = 6;
		(*index)++;
		return (temp);
	}
	temp = 0;
	return (temp);
}

char			get_conversion(const char *format, int *index)
{
	char temp;

	if (format[*index] == 's' || format[*index] == 'S' || format[*index] == 'd' 
		|| format[*index] == 'd' || format[*index] == 'D' || format[*index] == 'i'
		|| format[*index] == 'o' || format[*index] == 'O' || format[*index] == 'u'
		|| format[*index] == 'U' || format[*index] == 'x' || format[*index] == 'X'
		|| format[*index] == 'c' || format[*index] == 'C' || format[*index] == 'b'
		|| format[*index] == 'r' || format[*index] == 'k' || format[*index] == 'f'
		|| format[*index] == '%' || format[*index] == 'p')
	{
		temp = format[*index];
		//printf("\nindex in -> %c\n", format[*index]);
		(*index)++;
		//printf("\nindex in -> %c\n", format[*index]);
	}
	else
		temp = 0;
	return (temp);
}

