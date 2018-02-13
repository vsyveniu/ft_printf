
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
		//ft_errorrepeatflag();
		return (0);
	}
	return (1);
}

f_list		*ft_getflag(char c, f_list *params)
{
	if (c == '#' && (ft_checkisnorepeat(params->f_oct, '#'))) 
		params->f_oct = '#';
	if (c == '+' && (ft_checkisnorepeat(params->f_plus, '+'))) 
		params->f_plus = '+';
	if (c == '-' && (ft_checkisnorepeat(params->f_minus, '-'))) 
		params->f_minus = '-';
	if (c == ' ' && (ft_checkisnorepeat(params->f_space, ' '))) 
		params->f_space = ' ';
	if (c == '0' && (ft_checkisnorepeat(params->f_space, '0')))
		params->f_zero = '0';
	return (params);
}


int			ft_getwidth(char *format, int *i)
{
	int	temp;
	//printf("i-------->>>>>> %d\n", i);
	//while (format[i++] <= '0' && format[i++] >= '9' && format[i++] != '.');
	//printf("i-------->>>>>> %d\n", i);
	//printf("j-------->>>>> %d\n", j);
//	temp = ft_strsub(format, j, i - j);

//	printf("\n|||||||||||||||  %s\n", temp);

	//printf("--------------------------->>>>>>>>>>>>>>>. %d\n", (*(int*)i));
//	printf("f --------------------------->>>>>>>>>>>>>>>. %c\n", format[*i]);

	//temp = 0;
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		temp = (temp * 10) + (format[*i] - 48);
		(*i)++;
	}
	return (temp);
}

int			get_precision(const char *format, int *index)
{
	int	temp;

	if (format[*index] && format[*index] != '.') //maybe need to add check is !str ?
		return (temp = 0); 
	temp = 0;
	(*index) += 1;
	while (format[*index] != '\0' && format[*index] >= '0' && format[*index] <= '9')
	{
		temp = (temp * 10) + (format[*index] - 48);
		(*index)++;
	}
	return (temp);
}

