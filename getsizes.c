
#include "includes/ft_printf.h"

int		ft_getsignsize(void *arg, long long systembase, int size)
{
	long long temp;


	temp = (long long)arg;
	//temp = -4278;
	//printf("%lld\n", temp);
	if (temp == 1 || temp == 0)
		size = 1;
	else if (temp == -1)
		size = 2;
	else if (temp < 0)
	{
		//printf("picha\n");
		temp *= -1;
		size = ft_base(temp, systembase, size);
		//size++; ////////did nothing?
	}
	else
	{
		size = ft_base(temp, systembase, size);
	}
	return (size);
}


int		ft_getintsize(void *arg, int systembase, int size)
{
	int temp;
	
	temp = (int)arg;
	if (temp == 1 || temp == 0)
		size = 1;
	else if (temp == -2147483648)
		size = 11;
	else if (temp < 0)
	{
		temp *= -1;
		size = ft_intbase(temp, systembase, size);
		//size++; ////////////wait a sec... da fuck?!
	}
	else
	{
		size = ft_intbase(temp, systembase, size);
	}
	return (size);
}

int	ft_intbase(int arg, int base, int size)
{

	//printf("arg --->>> %lld\n", arg);
	while (arg > 0)
	{
		arg /= base;
		size += 1;
	}
	return (size);
}


int 	ft_gethexsize(f_list *p, unsigned long long temp, unsigned long long systembase, int size)
{
	if (temp == 4294967296)
	{
		size = 9;
		if (p->mod == 1 || p->mod == 2 || p->mod == 0)
			size = 1;
		return (size);
	}
	else
		size = ft_unsbase(temp, systembase, size);
	return (size);
}

int		getunsignsize(f_list *p, void *arg, unsigned long long systembase, int size)
{
	unsigned long long temp;
	temp = (unsigned long long)arg;
	if (p->conversion == 'x' || p->conversion == 'X')
		return (size = ft_gethexsize(p,  temp, systembase, size));
	if (temp == 1 || temp == 0)
		size = 1;
	else
		size = ft_unsbase(temp, systembase, size);
	return (size);
}


int		ft_unsbase(unsigned long long int arg, unsigned long long int base, int size)
{
	while (arg > 0)
	{
		arg /= base;
		size += 1;
	}
	return (size);
}

int	ft_base(long long arg, long long base, int size)
{

	//printf("arg --->>> %lld\n", arg);
	while (arg > 0)
	{
		arg /= base;
		size += 1;
	}
	return (size);
}


int 	ft_getsizehexoctbi(f_list *p, void  *arg)
{
	int 			size;
	long long 		systembase;

	size = 0;
	//(p->f_space && p-> ispos == 1) ? size += 1 : 0;
	(p->conversion == 'x' || p->conversion == 'X') ? systembase = 16 : 0;
	(p->conversion == 'o') ? systembase = 8 : 0;
	(p->conversion == 'd' || p->conversion == 'i') ? systembase = 10 : 0;
	(p->conversion == 'u' || p->conversion == 'U') ? systembase = 10 : 0;
	(p->conversion == 'b') ? systembase = 2 : 0;
	if (p->conversion == 'u' || p->conversion == 'U' || p->conversion == 'x' ||
		p-> conversion == 'X')
	{
		size = getunsignsize(p, arg, (unsigned long long)systembase, size);
	}
	else
	{
		if ((int)arg < 0 && p->mod == 0)
		{
			return (size = ft_getintsize(arg, systembase, size));
		}
		else
			size = ft_getsignsize(arg, systembase, size);		
	}
	return (size);
}

int		ft_getargsize(f_list *p, void *arg)
{
	int		size;

	size = 0;
	p->ispos = 1;
	if ((int)arg < 0)
		p->ispos = 2;
	if (p->conversion == 's')
		size = ft_strlen((char*)arg);
	if (p->conversion == 's' && (char*)arg == NULL)
		size = 6;
	if (p->conversion == 'c' || p->conversion == 'C')
		size = 1;
	if (p->conversion == 'x' || p->conversion == 'X'
		|| p->conversion == 'b' || p-> conversion == 'o'
		|| p->conversion == 'd' || p->conversion == 'i'
		|| p->conversion == 'u' || p->conversion == 'U')
	{
			size = ft_getsizehexoctbi(p, arg);
			return (size);
	}
	(p->conversion == '%') ? size = 1 : 0;
	return (size);
}

/*int		ft_checkmodifiers(f_list *p)
{
	int val;

	val = 0;
	if ( p->mod && ft_strcmp(p->mod, "h") == 0)
		return(val = 1);
	if (p->mod && ft_strcmp(p->mod, "hh") == 0)
		return(val = 2);
	if (p->mod && ft_strcmp(p->mod, "ll") == 0)
		return(val = 3);
	if (p->mod && ft_strcmp(p->mod, "l") == 0)
		return(val = 4);
	if (p->mod && ft_strcmp(p->mod, "j") == 0)
		return(val = 5);
	if (p->mod && ft_strcmp(p->mod, "z") == 0)
		return(val = 6);
	return(val);
}*/

int		ft_printsize(f_list *p, void *arg, int size)
{	
	(void)arg;
	//(p->conversion == '%') ? size += 1 : 0;
	//printf("--------->>>>>> %d\n", p->ispos);
	(p->f_space && !p->f_plus && p->ispos == 1) ? size += 1 : 0;
	(p->f_plus && p->ispos == 1) ? size += 1 : 0;
	(p->f_plus && p->ispos == 0) ? size += 1 : 0;
	(p->ispos == 2 && p->conversion != 'x' && p->conversion != 'X') ? size += 1 : 0;
	(p->w > size && !p->f_oct) ? size = p->w : 0;
	(p->pr > size) ? size = p->pr : 0; //this is a shit maybe
	(p->f_oct && p->ispos != 0) ? size += 2 : 0 ;
	(p->w > size && !p->pr) ? size = p->w : 0;
	(p->conversion == '%' && p->f_space) ? size -= 1 : 0;
	((p->conversion == 'u' || p->conversion == 'U') && p->ispos == 2) ? size -= 1 : 0;
	//((p->mod == 3 || p->mod == 4) && p->ispos == 2) ? size -= 1 : 0;
	/*(p->f_oct && p->ispos == 1) ? size += 2 : 0;
	//(p->ispos == 2) ? size += 1 : 0; ///this fucks me
	(p->f_plus && p->ispos == 1 ) ? size += 1 : 0;
	(p->w && p->w > size) ? size = p->w : 0;
	(p->w && p->pr && p->pr > size) ? size = p->pr : 0;
	(p->w && p->pr && p->w > p->pr && p->pr > size) ? size = p->pr : 0;
	(p->w && p->pr && p->w < p->pr && p->pr > size && !p->f_minus) ? size = p->pr + size : 0;
	(p->f_plus && p->ispos == 1 && p->w < p->pr) ? size += 1 : 0;
	(p->f_plus && p->ispos != 1 && p-> ispos != 2) ? size += 1 : 0;
	//(!p->w && !p->pr) ? 
	//(p->f_plus && p->ispos == 2) ? size -= 1 : 0;
	//(p->f_space && !p->f_plus && p->ispos == 1) ? size += 1 : 0; // maybe it's needed for d*/
//	(p->f_plus) ? size += 1 : 0;
	return (size);
}

int		ft_printstrsize(f_list *p, void *arg, int size)
{
	//printf("---------->>>>>>picha\n");
	//(p->w < p->pr) ? size = p->w : 0;
	if (!arg && p->conversion != 'c')
		size = 6;
	(p->w > p->pr) ? size = p->w : 0;
//	(!p->w && p->pr && p->pr > size) ? size = p->pr : 0;
	//(!p->w && p->pr && p->pr < size) ? size = size - p->pr : 0;
	//(p->w && p->w <= p->pr && p->pr < size) ? size = p->pr : 0;
	(!p->w && p->pr && p->pr < size) ? size = size - p->pr : 0;
	//(!p->w && p->pr && !p->f_minus && p->pr > size) ? size = p->pr - size: 0;
	(!p->w && p->pr && p->f_minus && p->pr < size) ? size = size - p->pr: 0;
	return (size);
}
