
#include "includes/ft_printf.h"


void	ft_puthex(char conv, f_list *p, uintmax_t arg)
{
	uintmax_t i;
	char *base;
	char *str;
	uintmax_t temp;

	i = 0;
	temp = arg;
	(conv == 'x' || conv == 'p') ? base = "0123456789abcdef" : 0;
	(conv == 'X') ? base = "0123456789ABCDEF" : 0;
	while ((temp /= 16) > 0)
		i++;
	str = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	if ((arg == 0 && p->f_oct) || (arg == 0 && (p->mod == 0 || p->mod == 1 || p->mod == 2)))
		ft_putchar('0');
	while (arg)
	{
		str[i++] = base[arg % 16];
		arg /= 16;
	}
	str[i] = '\0';
	while(i-- > 0)
		write(1, &str[i], 1);
	free(str);
}


void	ft_putpoint(void *arg)
{

	uintmax_t temp;
	uintmax_t temptemp;
	//temp = &arg;
	//printf("%p\n", temp);
	uintmax_t i;
	char *base;
	char *str;
	//void *temp;

	temp = (uintmax_t)arg;
	temptemp = temp;

	i = 0;
	base = "0123456789abcdef";
	while ((temptemp /= 16) > 0)
		i++;
	str = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	if (temp == 0)
		ft_putchar('0');
	while (temp)
	{
		str[i++] = base[temp % 16];
		temp /= 16;
	//printf("\n---->>>>>  %llu\n", temp);
	}
	str[i] = '\0';
	while(i-- > 0)
		write(1, &str[i], 1);
	free(str);
}


void	ft_putocto(unsigned long long int arg)
{
	unsigned long long int i;
	char *base;
	char *str;
	unsigned long long int temp;
	
	base = "012345678";

	i = 0;
	temp = arg;
	while ((temp /= 8) > 0)
		i++;
	str = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	if (arg == 0)
		ft_putchar('0');
	while (arg)
	{
		str[i++] = base[arg % 8];
		arg /= 8;
	}
	while(i-- > 0)
		write(1, &str[i], 1);
	free(str);
}

void	ft_putbinary(int arg)
{
	int i;
	char *base;
	char *str;
	int temp;
	
	base = "01";

	i = 0;
	temp = arg;
	while ((temp /= 2) > 0)
		i++;
	str = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (arg)
	{
		str[i++] = base[arg % 2];
		arg /= 2;
	}
	while(i-- > 0)
		write(1, &str[i], 1);
	free(str);
}