
#include "includes/ft_printf.h"

void	ft_putnnstr(const char *str, int start)
{
	while (str[start] != '\0')
	{
		ft_putchar(str[start]);
		start++;
	}
}

void	ft_putnnnstr(const char *str, int start, int end)
{
	while(start < end)
	{
		ft_putchar(str[start]);
		start++;
	}
}

int		ft_isconv(char c)
{
	if (c == 's' || c == 'S' || c == 'd' 
		|| c == 'd' || c == 'D' || c == 'i'
		|| c == 'o' || c == 'O' || c == 'u'
		|| c == 'U' || c == 'x' || c == 'X'
		|| c == 'c' || c == 'C' || c == 'b'
		|| c == 'r' || c == 'k' || c == 'f'
		|| c == '%' || c == 'p'){
		return(1);
	}
	else
		return(0);
}

int		ft_ismod(char c)
{
	if (c == 'h' || c == 'l' || c == 'z'
		|| c == 'j')
	{
		return (1);
	}

	return (0);	
}

void 	ft_parseprec(const char *f, int *i, f_list *p)
{
	p->prc = 1;
	if (f[*i] == '.' && ft_isdigit(f[*i + 1]) == 1)
		{
			(*i)++;
			p->pr = get_precision(f, i);
			while (ft_isdigit(f[*i]) == 1)
				(*i)++;
		}
}
