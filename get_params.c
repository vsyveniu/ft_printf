
#include "ft_printf.h"

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
		//ft_errorrepeatflag();
		return (0);
	}
	return (1);
}

f_list		*ft_getflag(const char *format, f_list *params, int *index)
{
	if (format[*index] == '#' && (ft_checkisnorepeat(params->f_oct, '#'))) 
		params->f_oct = '#';
	if (format[*index] == '#' && (ft_checkisnorepeat(params->f_oct, '#'))) 
		params->f_oct = '#';
	if (format[*index] == '+' && (ft_checkisnorepeat(params->f_plus, '+'))) 
		params->f_plus = '+';
	if (format[*index] == '-' && (ft_checkisnorepeat(params->f_minus, '-'))) 
		params->f_minus = '-';
	if (format[*index] == ' ' && (ft_checkisnorepeat(params->f_space, ' '))) 
		params->f_space = ' ';
	if (format[*index] == '0' && (ft_checkisnorepeat(params->f_space, '0')))
		params->f_zero = '0';
	return (params);
}


int			ft_getwidth(const char *format, int *index)
{
	int	temp;

	if (format[*index] >= '0' && format[*index] <= '9') //maybe need to add check is !str ?
	{
		temp = ft_atoi(&format[*index]);
	}
	else
		temp = 0;
	return (temp);
}

int			get_precision(const char *format, int *index)
{
	int	temp;

	temp = 0;
	if (format[*index] == '.')
	{
		(*index)++;
		if (format[*index] >= '0' && format[*index <= '9'])
		{
			temp = ft_atoi(&format[*index]);
		}
	}
	else
		temp = 0;
	return (temp);
}

