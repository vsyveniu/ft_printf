
#include "includes/ft_printf.h"


void	ft_puthex(char conv, unsigned long long int arg)
{
	unsigned long long int i;
	char *base;
	char *str;
	unsigned long long int temp;

	i = 0;
	temp = arg;
	(conv == 'x' || conv == 'p') ? base = "0123456789abcdef" : 0;
	(conv == 'X') ? base = "0123456789ABCDEF" : 0;
	while ((temp /= 16) > 0)
		i++;
	str = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	if (arg == 0)
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


/*void	ft_putpoint(char conv, void *arg)
{

	unsigned long long temp;
	temp = &arg;
	//printf("%p\n", temp);
	unsigned long long int i;
	char *base;
	char *str;
	void *temp;


	temp = &arg;

	i = 0;
	(conv == 'p') ? base = "0123456789abcdef" : 0;
	//(conv == 'p') ? base = "0123456789ABCDEF" : 0;
	while ((temp /= 16) > 0)
		i++;
	str = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	if (arg == 0)
		ft_putchar('0');
	while (temp)
	{
		str[i++] = base[temp % 16];
		temp /= 16;
	}
	str[i] = '\0';
	while(i-- > 0)
		write(1, &str[i], 1);
	free(str);
}*/


void	ft_putocto(int arg)
{
	int i;
	char *base;
	char *str;
	int temp;
	
	base = "012345678";

	i = 0;
	temp = arg;
	while ((temp /= 8) > 0)
		i++;
	str = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
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