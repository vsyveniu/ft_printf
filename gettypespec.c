
#include "ft_printf.h"

static char		*ft_handlethisbitcheshhandll(const char *format, int *index, char c)
{
	char 	*temp;

	temp = NULL;
	if (c == 'h')
	{
		if (format[*index + 1] == 'h')
		{
			temp = ft_strdup("hh");
			(*index)++;
			return (temp);
		}
		temp = ft_strdup("h");	
	}
	else if (c == 'l')
	{
		if (format[*index + 1] == 'l')
		{
			temp = ft_strdup("ll");
			(*index)++;
			free(temp);
			return (temp);
		}
		temp = ft_strdup("l");
	}
	free(temp);
	return(temp);
}


char			*get_justanothershittomanage(const char *format, int *index) // is it bettter to fill struct with int?
{
	char *temp;  //is it may be int?

	temp = NULL;
	if (format[*index] == 'h' || format[*index] == 'l')
	{
		temp = ft_handlethisbitcheshhandll(format, index, format[*index]);
		(*index)++;
		return (temp);
	}
	if (format[*index] == 'j')
	{
		temp = ft_strdup("j");
		(*index)++;
		return(temp);
	}
	if (format[*index] == 'z')
	{
		temp = ft_strdup("z");
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
		|| format[*index] == '%')
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

