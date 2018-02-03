
#include "ft_printf.h"

int 	ft_getsizehexoctbi(f_list *p, int arg)
{
	int 	i;
	int 	size;
	int 	systembase;
	int		temp;

	i = 1;
	size = 0;
	temp = arg;
	(temp == 0 || temp == 1) ? size += 1 : 0;
	if (temp == 2147483647)
		return (size = 10);
	(p->conversion == 'x' || p->conversion == 'X') ? systembase = 16 : 0;
	(p->conversion == 'o') ? systembase = 8 : 0;
	(p->conversion == 'd') ? systembase = 10 : 0;
	(p->conversion == 'b') ? systembase = 2 : 0;
	//if (p->conversion == 'f')
	//	systembase = ft_getsizetodot(p, arg);
	if (arg < 0)
		temp *= -1;
	if ((arg < 10 && arg >= 0) && p->conversion != 'b')
		systembase++;
	while (i < temp)
	{
		i *= systembase;
		++size;
	}
	//	printf("picha\n");
	return (size);
}

int		ft_getargsize(f_list *p, void *arg)
{
	int		size;

	size = 0;
	if (p->conversion == 's')
		size = ft_strlen(*(char**)arg);
	if (p->conversion == 's' && (char*)arg == NULL)
		size = 6;
	if (p->conversion == 'c' || p->conversion == 'C')
		size = 1;
	if (p->conversion == 'x' || p->conversion == 'X'
		|| p->conversion == 'b' || p-> conversion == 'o'
		|| p->conversion == 'd' || p->conversion == 'i')
	{
			size = ft_getsizehexoctbi(p, (*(int*)arg));
			return (size);
	}
	(p->conversion == '%') ? size = 1 : 0;
	return (size);
}

int		ft_checkmodifiers(f_list *p)
{
	int val;

	val = 0;
	if ( p->justanothershittomanage && ft_strcmp(p->justanothershittomanage, "h") == 0)
		return(val = 1);
	if (p->justanothershittomanage && ft_strcmp(p->justanothershittomanage, "hh") == 0)
		return(val = 2);
	if (p->justanothershittomanage && ft_strcmp(p->justanothershittomanage, "ll") == 0)
		return(val = 3);
	if (p->justanothershittomanage && ft_strcmp(p->justanothershittomanage, "l") == 0)
		return(val = 4);
	if (p->justanothershittomanage && ft_strcmp(p->justanothershittomanage, "j") == 0)
		return(val = 5);
	if (p->justanothershittomanage && ft_strcmp(p->justanothershittomanage, "z") == 0)
		return(val = 6);
	return(val);
}

int		ft_printsize(f_list *p, int size)
{
	(p->conversion == '%') ? size += 1 : 0;
	(p->ispos == 2) ? size += 1 : 0;
//	(p->f_plus && p->ispos == 1 ) ? size += 1 : 0;
	(p->w && p->w > size) ? size = p->w : 0;
	(p->w && p->pr && p->pr > size) ? size = p->pr : 0;
	(p->w && p->pr && p->w > p->pr && p->pr > size) ? size = p->pr : 0;
	(p->w && p->pr && p->w < p->pr && p->pr > size && !p->f_minus) ? size = p->pr + size : 0;
	(p->f_plus && p->ispos == 1 && p->w < p->pr) ? size += 1 : 0;

	//(!p->w && !p->pr) ? 
	return (size);
}

int		ft_printstrsize(f_list *p, int size)
{
	(p->w < p->pr) ? size = p->w : 0;
	(p->w > p->pr) ? size = p->w : 0;
	(!p->w && p->pr && p->pr > size) ? size = p->pr : 0;
	(!p->w && p->pr && p->pr < size) ? printf("fuck\n") : 0;
	(p->w && p->w <= p->pr && p->pr < size) ? size = p->pr : 0;
	(!p->w && p->pr && p->f_minus) ? size = p->pr - size: 0;
	(!p->w && p->pr && !p->f_minus && p->pr > size) ? size = p->pr - size: 0;
	(p->conversion == 'c' || p->conversion == 'C') ? size = 1 : 0;
	return (size);
}
