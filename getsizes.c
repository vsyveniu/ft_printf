
#include "ft_printf.h"

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
		//size++;
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
	else if (temp == -1)
		size = 1;
	else if (temp == -2147483648)
			size = 10;
	else if (temp < 0)
	{
		temp *= -1;
		size = ft_intbase(temp, systembase, size);
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
		++size;
	}
	return (size);
}
int		getunsignsize(void *arg, unsigned long long systembase, int size, f_list *p)
{
	unsigned long long temp;

	temp = (unsigned long long)arg;
	if (temp == 1 || temp == 0)
		size = 1;
	else if (p->conversion == '%')
		printf("picha\n");
/*	else if (temp == 4294967296 &&  
	{
		size = 1;
	}*/
	else
		size = ft_unsbase(temp, systembase, size);
	return (size);
}


int	ft_unsbase(unsigned long long int arg, unsigned long long int base, int size)
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
		++size;
	}
	return (size);
}


int 	ft_getsizehexoctbi(f_list *p, void  *arg)
{
	int 			size;
	long long 		systembase;

	size = 0;
//	printf("%d\n", p->ispos);
	//(p->f_plus && p->ispos == 1) ? size += 1 : 0;
	
	//(p->f_space && p->ispos == 2) ? size -= 1 : 0;
	(p->conversion == 'x' || p->conversion == 'X') ? systembase = 16 : 0;
	(p->conversion == 'o') ? systembase = 8 : 0;
	(p->conversion == 'd' || p->conversion == 'i') ? systembase = 10 : 0;
	(p->conversion == 'u' || p->conversion == 'U') ? systembase = 10 : 0;
	(p->conversion == 'b') ? systembase = 2 : 0;
	if (p->conversion == 'u' || p->conversion == 'U')
		size = getunsignsize(arg, (unsigned long long)systembase, size, p);
	else
	{
		if ((int)arg < 0 )
			return (size =  ft_getintsize(arg, systembase, size));
		else
			size = ft_getsignsize(arg, systembase, size);		
	}

	//printf("%ld\n", temp); 



	//if (temp > 2147483647)
		//printf("picha\n");
	//printf("->>>>  %d", temp);

	//printf("->>> %d\n",temp );
	//temp = (*(signed long long*)arg);
	//printf("->>> %llu\n", temp );
	//printf("%lld\n", temp);
	
	//if ((signed long long)arg < 0)
	//	temp *= -1;
	//if (((signed long long)arg < 10 && (signed long long)arg >= 0) && p->conversion != 'b')
	//	systembase++;
	//printf("---->>>>>>>>  %lld\n", size);
	return (size);
}

int		ft_getargsize(f_list *p, void *arg)
{
	int		size;

	size = 0;
	p->ispos = 1;
	if (arg < 0)
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
	//(p->conversion == '%') ? size += 1 : 0;
	(p->ispos == 2) ? size += 1 : 0;
	(p->f_plus && p->ispos == 1 ) ? size += 1 : 0;
	(p->w && p->w > size) ? size = p->w : 0;
	(p->w && p->pr && p->pr > size) ? size = p->pr : 0;
	(p->w && p->pr && p->w > p->pr && p->pr > size) ? size = p->pr : 0;
	(p->w && p->pr && p->w < p->pr && p->pr > size && !p->f_minus) ? size = p->pr + size : 0;
	(p->f_plus && p->ispos == 1 && p->w < p->pr) ? size += 1 : 0;
	(p->f_plus && p->ispos != 1 && p-> ispos != 2) ? size += 1 : 0;
	//(!p->w && !p->pr) ? 
	//(p->f_plus && p->ispos == 2) ? size -= 1 : 0;
	//(p->f_space && !p->f_plus && p->ispos == 1) ? size += 1 : 0; // maybe it's needed for d
	return (size);
}

int		ft_printstrsize(f_list *p, int size)
{
	//(p->w < p->pr) ? size = p->w : 0;
	(p->w > p->pr) ? size = p->w : 0;
//	(!p->w && p->pr && p->pr > size) ? size = p->pr : 0;
	//(!p->w && p->pr && p->pr < size) ? size = size - p->pr : 0;
	//(p->w && p->w <= p->pr && p->pr < size) ? size = p->pr : 0;
	(!p->w && p->pr && p->pr < size) ? size = p->pr - size: 0;
	//(!p->w && p->pr && !p->f_minus && p->pr > size) ? size = p->pr - size: 0;
	(!p->w && p->pr && p->f_minus && p->pr < size) ? size = size - p->pr: 0;
	return (size);
}
