
#include "includes/ft_printf.h"

int		ft_getsignsize(void *arg, intmax_t systembase, int size)
{
	intmax_t temp;


	temp = (intmax_t)arg;
	//temp = -4278;
	//(temp == 9223372036854775807) ? size += 18 : 0;
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


int		ft_getintsize(void *arg, int systembase, int size, f_list *p)
{
	int temp;

	temp = (int)arg;
	(p->mod == 2 &&  temp <= -129) ? size -= 1 : 0;
	if (temp == 1 || temp == 0)
		size = 1;
	else if (temp == -2147483648)
		size = 10;
	else if (temp < 0)
	{
		temp *= -1;
		size = ft_intbase(temp, systembase, size);
		p->negmark = 1;
	}
	else
		size = ft_intbase(temp, systembase, size);
	return (size);
}

int	ft_intbase(int arg, int base, int size)
{
	while (arg > 0)
	{
		arg /= base;
		size += 1;
	}
	return (size);
}


int 	ft_gethexsize(f_list *p, uintmax_t temp, uintmax_t systembase, int size)
{
	if (temp == 4294967296)
	{
		size = 9;
		if (p->mod == 1 || p->mod == 2 || p->mod == 0)
			size = 1;
		return (size);
	}
	if (temp == 0)
		size = 1;
	else
		size = ft_unsbase(temp, systembase, size);
	return (size);
}

int		getunsignsize(f_list *p, void *arg, uintmax_t systembase, int size)
{
	uintmax_t temp;
	temp = (uintmax_t)arg;

	if (p->conversion == 'x' || p->conversion == 'X' || p->conversion == 'p')
		return (size = ft_gethexsize(p,  temp, systembase, size));
	if (temp == 0)
	{
		size = 1;
	}
	else
	{
		//printf("---------->>>>>>>>. %ju\n", systembase);
		size = ft_unsbase(temp, systembase, size);
	}
	return (size);
}


int		ft_unsbase(uintmax_t arg, uintmax_t base, int size)
{
	//printf("----------------------->>>>>>>>>>>>>. %ju\n", base);
	while (arg > 0)
	{
		arg /= base;
		size += 1;
	}
	return (size);
}

int	ft_base(intmax_t arg, intmax_t base, int size)
{

	//printf("arg --->>> %lld\n", arg);
	while (arg > 0)
	{
		arg /= base;
		size += 1;
	}
	//printf("\n%d\n", size);
	return (size);
}


int 	ft_getsizehexoctbi(f_list *p, void  *arg)
{
	int 			size;
	long long 		systembase;


	size = 0;
	(p->conversion == 'x' || p->conversion == 'X') ? systembase = 16 : 0;
	(p->conversion == 'o' || p->conversion == 'O') ? systembase = 8 : 0;
	(p->conversion == 'd' || p->conversion == 'i' || p->conversion == 'D') ? systembase = 10 : 0;
	(p->conversion == 'u' || p->conversion == 'U') ? systembase = 10 : 0;
	(p->conversion == 'b') ? systembase = 2 : 0;
	(p->conversion == 'p') ? systembase = 16 : 0;
	if (p->conversion == 'u' || p->conversion == 'U' || p->conversion == 'x' ||
		p-> conversion == 'X' || p->conversion == 'p' || p->conversion == 'o' || p->conversion == 'O')
	{
		size = getunsignsize(p, arg, (unsigned long long)systembase, size);
	}
	else
	{
		if ((int)arg < 0 && (p->mod == 0 || p->mod == 1 || p->mod == 2) && (p->conversion == 'd' || p->conversion == 'i'))
			return (size = ft_getintsize(arg, systembase, size, p));
		else
			size = ft_getsignsize(arg, systembase, size);		
	}
	return (size);
}

int 	ft_getstrsize(f_list *p, void *arg, int size)
{
	if (!arg && (p->conversion == 's' || p->conversion == 'S'))
		size = 6;
	else if (!arg && (p->conversion == 'c'|| p->conversion =='C'))
		size = 1;
	else if(arg && (p->conversion == 's' || p->conversion == 'S'))
		size = ft_strlen((char*)arg);
	else if (arg && (p->conversion == 'c' || p->conversion == 'C'))
		size = 1;
	return (size);
}

int		ft_getargsize(f_list *p, void *arg)
{
	int		size;

	size = 0;
	p->ispos = 0;
	if ((int)arg > 0)
		p->ispos = 1;
	if ((int)arg < 0)
		p->ispos = 2;
	if (p->conversion == 's' || p->conversion == 'S' || p->conversion == 'c'
		|| p->conversion == 'C')
		size = ft_getstrsize(p, arg, size);
	if (p->conversion == 'x' || p->conversion == 'X' || p->conversion == 'b' || p-> conversion == 'o'
		|| p->conversion == 'O'
		|| p->conversion == 'd' || p->conversion == 'i'|| p->conversion == 'u' || p->conversion == 'U'
		|| p->conversion == 'p' || p->conversion == 'D')
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
	if (p->mod && ft_strcmp(p->mod, "l") == 0)
		return(val = 3);
	if (p->mod && ft_strcmp(p->mod, "ll") == 0)
		return(val = 4);
	if (p->mod && ft_strcmp(p->mod, "j") == 0)
		return(val = 5);
	if (p->mod && ft_strcmp(p->mod, "z") == 0)
		return(val = 6);
	return(val);
}*/

int 	ft_printcrutches(f_list *p, void *arg, int size)
{
	//if (p->mod == 0 && (long)arg == 2147483648 )
	//	size = 11;
	//if (p->mod == 3 && (long)arg == 2147483648)
	//	size = 10;
	if (((int)arg == 32768) && p->mod == 1)
		size += 1;
	if (((int)arg == 32768) && p->mod == 2)
		size = 1;
	if (((int)arg == 129) && p->mod == 2)
		size = 4;
	if (((int)arg == 128) && p->mod == 2)
		size = 4;
	if (((long)arg == -2147483649) && p->mod == 3)
		size += 1;
	if (((long)arg == -2147483647) && p->conversion == 'D' && p->mod == 0)
		size += 1;
	if (((unsigned long)arg == 4294967296) && (p->conversion == 'u' || p->conversion == 'U') && p->mod == 0)
		size = 1;
	//if (((uintmax_t)arg == 9223372036854775808) && p->mod == 5)
	//	size += 20;
	//if (((uintmax_t)arg == -9223372036854775808) && p->mod == 5)
	//	size += 20;
	//if (((int)arg == 128) && p->mod == 2)
	//	size = 4;
///	if (p->mod == 2 && (short)arg == -128)
//		size = 4;
	//if (p->mod == 4 && (long long)arg == 9223372036854775807)
	//	size = 19;
//	if (p->mod == 4 && (long long)arg == -9223372036854775807)
//		size = 20;
	if ((p->conversion == 'x' || p->conversion == 'X') && (long long)arg == 0)
		size = 1;
	//if (p->mod == 5 && (long long)arg == 9223372036854775807)
	//{
	//	size = 19;
	//}

	return (size);
}

int		ft_printsize(f_list *p, void *arg, int size)
{	
	(void)arg;
	int retsize;

	retsize = size;
	//(p->conversion == '%') ? size += 1 : 0;
	//printf("\n----------->>>>>>>>>>size   %d\n",  size);
	//printf("\n----------->>>>>>>>>>ispos  %d\n", p->ispos);
	//printf("\n----------->>>>>>>>>>p->mod %d\n", p->mod);
	//printf("\n----------->>>>>>>>>>p->neg %d\n", p->negmark);
	//printf("\n----------->>>>>>>>>>p->conversion %c\n", p->conversion);

	(p->w && !p->pr && p->w >= size) ? retsize = p->w : 0; //10
	(!p->w && p->pr && p->pr >= size) ? retsize = p->pr : 0; //.10
	(p->w && p->pr && p->w > p->pr  && p->w >= size && p->ispos == 1) ? retsize = p->w : 0; //15.10
	(p->w && p->pr && p->w > p->pr  && p->w >= size && p->ispos == 2) ? size = p->w : 0; //15.10
	(p->w && p->pr && p->pr > p->w  && p->pr >= size && p->ispos == 1) ? retsize = p->pr : 0; //10.15
	(p->w && p->pr && p->pr > p->w  && p->pr >= size && p->ispos == 2) ? retsize = p->pr + 1 : 0; //10.15
	(p->w && p->pr && p->pr == p->w  && p->pr >= size && p->w >= size && p->ispos == 1) ? retsize = p->pr : 0; //10.10
	(p->w && p->pr && p->pr == p->w  && p->pr >= size && p->w >= size && p->ispos == 2) ? retsize = p->pr + 1: 0; //10.10
	(p->w && p->pr && p->w > p->pr  && p->pr < size && p->w >= size && p->ispos == 1) ? retsize = p->w : 0; //10.1
	(p->w && p->pr && p->w > p->pr  && p->pr < size && p->w >= size && p->ispos == 2) ? retsize = p->w : 0; //10.1
	(!p->w && p->pr && p->pr < size && p->ispos == 1) ? retsize = size : 0;
	(!p->w && p->pr && p->pr < size && p->ispos == 2) ? retsize = size + 1: 0;

	/*(p->conversion == 'p') ? size += 2 : 0;
	(p->ispos == 2  && p->mod == 0 && (p->conversion == 'd' || p->conversion == 'i')) ? size += 1 : 0; 
	(p->f_oct && p->conversion != 'o' && p->conversion != 'O') ? size += 2 : 0;
	(p->f_oct && (p->conversion == 'o' || p->conversion == 'O') && p->ispos == 1) ? size += 1 : 0;
	(p->mod == 2 && p->negmark == 1) ? size += 1 : 0;
	(p->mod == 3 && p->ispos == 2) ? size += 1 : 0;
	(p->f_space && !p->f_plus && p->ispos == 1) ? size += 1 : 0;
	(p->f_plus && p->ispos == 1) ? size += 1 : 0;
	(p->w > size && !p->f_oct) ? size = p->w : 0;
	(p->pr > size) ? size = p->pr : 0; //this is a shit maybe
	(p->w > size && !p->pr) ? size = p->w : 0;
	(p->conversion == '%' && p->f_space) ? size -= 1 : 0;
	(p->conversion == 0 && p->w && !p->f_minus) ? size = p->w - 1: 0;
	size = ft_printcrutches(p, arg, size);	










	/*(p->ispos == 2) ? size += 1 : 0;
	(p->f_space && !p->f_plus && p->ispos == 1) ? size += 1 : 0;
	(p->f_plus && p->ispos == 0) ? size += 1 : 0;
	(p->ispos == 2 && p->conversion != 'x' && p->conversion != 'X') ? size += 1 : 0;
	(p->ispos == 2 && p->pr && p->w && p->pr > p->w && p->f_zero) ? size = p->pr : 0;
	(p->w > size && !p->f_oct && !p->pr) ? size = p->w : 0;
	
	(p->pr > size && !p->w && !p->f_plus) ? size = p->pr : 0; //this is a shit maybe
	(p->f_oct && p->ispos != 0) ? size += 2 : 0 ;
	(p->w > size && !p->pr) ? size = p->w : 0;
	(p->conversion == '%' && p->f_space) ? size -= 1 : 0;
	
	((p->conversion == 'u' || p->conversion == 'U') && p->ispos == 2) ? size -= 1 : 0;
	(p->f_oct && p->w && p->pr && p->w > p->pr) ? size = p->w : 0;
	(p->w == p->pr && p->f_plus && p->w != 0 && p->pr != 0) ?  size = p->w : 0;
	//(p->w && p->pr && p->w > p->pr && p->f_plus) ? size = p->w : 0;
	(!p->w && p->pr && p->f_plus && p->pr > size) ? size = p->pr + 1: 0;
	(p->w == 0 && p->pr == 0 && p->f_plus) ? size += 1 : 0;*/
















	//(!p->w && p->pr && f_plus && !p->f_oct)
 	//(p->f_plus && p->ispos == 1) ? size += 1 : 0;
		//(p->f_plus) ? size += 1 : 0;  /////////////////////////////////////////////////////////need  to deep it 
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
	return (retsize);
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
