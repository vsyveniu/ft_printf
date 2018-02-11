
#include "includes/ft_printf.h"

void	ft_handleBITCH(f_list *p, int size)
{
	(p->w && !p->f_minus) ? ft_putnchar(' ', p->w - size) : 0;
}


void 	ft_putspacezerocrutch(char c, char c1, int sizec, int sizec1)
{
	ft_putnchar(c, sizec);
	ft_putnchar(c1, sizec1);
}

void 	ft_putspacepluszerocrutch(char c, char c1, int sizec, int sizec1)
{
	ft_putnchar(c, sizec);
	ft_putchar('+');
	ft_putnchar(c1, sizec1);
}


void	ft_handlepos(f_list *p, int size)
{
	if (p->f_oct && ((p->conversion == 'x' || p->conversion == 'X') || (p->conversion == 'o') || p->conversion == 'O'))
		ft_handlehash(p, size);
	else if (p->conversion == '%')
		ft_handleBITCH(p, size);
	else
	{
		//printf("-------------------<?>>>>>>>>>>>>>>picha!!!!!!!!!!!\n");
		/*(p->f_plus) ? size += 1 : 0;
		(p->w && !p->pr && !p->f_zero && p->ispos == 1 && !p->f_minus) ? ft_putnchar(' ', p->w - size) : 0;
		(p->w > size && p->f_plus && !p->pr) ? ft_putcratch('+', '0', p->w - size) : 0;
		(p->w > size && !p->f_plus && !p->f_minus && p->f_zero) ? ft_putnchar('0', p->w - size) : 0;
		(p->w > p->pr && p->pr > size && !p->f_plus) ? ft_putcratch(' ', '0', p->pr - size) : 0;
		(p->pr > p->w  && p->w > size && !p->f_plus ) ? ft_putnchar('0', p->pr - size) : 0;
		
		(p->pr && p->w > p->pr  && p->w > size && p->f_plus ) ? ft_puttriplecratch('+','0',p->w - p->pr - 1, p->pr - size) : 0;///////////
		(p->w < p->pr  && p->w > size && !p->f_minus && p->f_plus) ? ft_putcratch('+','0', p->pr - size) : 0;
		(p->f_plus && !p->w) ? ft_putchar('+') : 0;
		(p->pr > size && !p->f_plus && !p->f_minus) ? ft_putnchar('0', p->pr - size) : 0;
		(p->f_space && !p->f_plus && !p->w && !p->pr) ? ft_putchar(' ') : 0;
		(p->w && p->pr && p->w > p->pr && !p->f_zero) ? ft_putnchar(' ', p->w - size) : 0;*/

		//printf("------------>>>>>>>> size %d\n", size);
		//printf("------------>>>>>>>> pr %d\n", p->pr);
	//	printf("------------>>>>>>>> w %d\n", p->w);
		(p->f_space && !p->f_plus) ? ft_putchar(' ') : 0;
		if (p->w && !p->pr)
		{	(p->f_plus) ? size += 1 : 0;
			(p->f_plus) ? ft_putchar('+') : 0;
			(p->w > size && !p->f_plus) ? ft_putnchar(' ', p->w - size) : 0;
			(p->f_zero) ? ft_putnchar ('0', p->w - size) : 0;
			
		}
		else if (p->w && p->pr)
		{
			//(p->f_plus) ? size += 1 : 0;
			//(p->f_plus) ? ft_putchar('+') : 0;
			(p->pr > p->w && p->pr > size) ? ft_putspacezerocrutch(' ', '0', p->w - p->pr, p->pr - size) : 0;
			(p->w > p->pr && p->w > size && !p->f_plus && !p->f_minus) ? ft_putspacezerocrutch(' ', '0', p->w - p->pr - 1, p->pr - size) : 0;
			(p->w > p->pr && p->w > size && p->f_plus) ? ft_putspacepluszerocrutch(' ', '0', p->w - p->pr - 1, p->pr - size) : 0;
		}
		else if (!p->w && p->pr)
		{
			(p->f_plus) ? ft_putchar('+') : 0;
			(p->pr > size) ? ft_putnchar('0', p->pr - size) : 0;
		}
		//else if (p->w > size && p->f_zero)
		//	ft_putnchar('0', p->w - size);
		//(p->w && !p->pr && !p->f_plus) ? ft_putnchar(' ', p->w - size) : 0;
		//((p->conversion == 'x' || p->conversion == 'X') && p->w > size && !p->pr && !p->f_minus) ? ft_putnchar (' ', p->w - size) : 0; this picha need to bitcha !!!!!!!!!!!!!!!!!!!!!!!!!!!
		//(p->w  > size && !p->f_zero) ? ft_putnchar(' ', p->w - size) : 0; // thi crutch is too hard, maybe there is a more fitable solution???
		/*(p->f_oct && p->ispos == 1) ? size += 2 : 0;
		(p->w && p->pr && p->w < p->pr && p->f_zero && p->f_plus && p->ispos == 1) ? ft_putcratch('+','0',p->pr - size) : 0;
		(p->w && p->pr && p->w > p->pr && !p->f_plus && !p->f_zero && !p->f_minus) ? ft_putdoublecratch(p, '0', p->w - size, p->pr - size) : 0; // need to refactor 
		(p->w && p->pr && p->w > p->pr && p->f_plus && !p->f_zero && p->ispos == 1) ? ft_puttriplecratch('+', '0', p->w - p->pr - 1, p->pr - size + 1) : 0;
		(p->w && p->pr && p->w > p->pr && !p->f_plus && p->f_zero && !p->f_minus) ? ft_putdoublecratch(p, '0', p->w - p->pr, p->pr - size) : 0;
		(p->w && p->pr && p->w > p->pr && p->f_zero && p->f_minus) ? ft_putnchar('0', p->w - p->pr - 1) : 0; 
		(p->w && p->pr && p->w > p->pr && p->f_minus && !p->f_zero) ? ft_putnchar('0', p->w - p->pr) : 0;
		(p->w && p->pr && p->w < p->pr && p->f_zero && !p->f_plus) ? ft_putnchar('0',p->pr - size ) : 0;
		(p->w && p->pr && p->w < p->pr && !p->f_plus && !p->f_zero) ? ft_putnchar('0', p->pr - size) : 0;
		(p->w && p->pr && p->w < p->pr && p->f_plus && !p->f_zero && p->ispos == 1) ? ft_putcratch('+', '0', p->pr - size + 1) : 0;
		(p->w && p->pr && p->w > p->pr && p->f_plus && p->f_zero && !p->f_minus) ? ft_puttriplecratch('+', '0', p->w - p->pr - 1, p->pr - size + 1) : 0; 
		(!p->w && p->pr && p->f_plus) ? ft_putcratch('+','0', p->pr - size): 0;
		(p->w && !p->pr && p->f_zero && !p->f_minus && p->ispos == 1 && !p->f_plus) ? ft_putnchar('0', p->w - size) : 0;
		(p->w && !p->pr && p->f_zero && !p->f_minus && p->ispos == 1 && p->f_plus) ? ft_putcratch('+','0', p->w - size - 1) : 0;
		(!p->w && p->pr) ? ft_putnchar('0', p->pr - size): 0;	
		(p->w && p->conversion == '%' && !p->f_minus) ? ft_putnchar(' ', p->w - size) : 0;
		(p->w && !p->pr && !p->f_zero && !p->f_minus && p->conversion != '%') ? ft_putnchar(' ', p->w - size) : 0;
		(p->f_plus && !p->f_zero && !p->pr && p->ispos == 1) ? ft_putchar('+') : 0;
		(p->f_plus && p->ispos != 1 && p->ispos != 2) ? ft_putchar('+') : 0;
		(p->f_space) ? ft_putchar(' ') : 0;*/
	}
}


int	ft_handleleft(f_list *p, int size)
{
	//printf("------------------->>>>>>>>>>>>>>>>>>>>>>picha\n");
	//(p->f_plus) ? size += 1 : 0;
	/*(p->ispos == 2) ? size += 1 : 0;
	(p->f_oct && (p->conversion == 'o' || p->conversion == 'O')) ? size -= 1 : 0;
	(p->w && p->pr && p->w > p->pr && p->f_zero) ? ft_putnchar(' ', p->w - p->pr - 1) : 0;
	(p->w && !p->pr && !p->f_zero && p->conversion != '%' && p->conversion != 'o' && p->conversion != 'O') ? ft_putnchar(' ', p->w - size) : 0;
	(p->w && !p->pr && (p->conversion == 'o' || p->conversion == 'O')) ? ft_putnchar(' ', p->w - size) : 0;
	(p->w && !p->pr && !p->f_zero && p->conversion == '%') ? ft_putnchar(' ', p->w - size) : 0;
	(p->w && p->pr && !p->f_zero && p->w > p->pr) ? ft_putnchar(' ', p->w - p->pr) : 0;
	(p->w && !p->pr && p->f_zero && p->f_oct && p->f_minus) ? ft_putnchar(' ', p->w - size - 2) : 0;
	(p->w && p->f_zero && !p->pr && !p->f_minus) ? ft_putnchar(' ', p->w - size) : 0 ;*/
	printf("---------------->>>>>>>>?????????>>picha\n");
	if(p->w && !p->pr)
	{
		(p->w) ? ft_putnchar(' ', p->w - size) : 0;
	}


	return (size); /// this is void!!
}

void	ft_handlehash(f_list *p, int size)
{
	//printf("------------->>>>>>>>picha\n");
		//printf("%d\n", p->mod);
	/*	(p->f_oct && p->ispos == 1) ? size += 2 : 0;
		(p->w && !p->pr && p->f_zero && !p->f_oct) ? ft_putnchar('0', p->w - size) : 0;
		(p->w && !p->pr && p->f_zero && !p->f_minus) ? ft_crutchforhash(p, '0', p->w - size) : 0;
		(p->w && !p->pr && p->f_minus && (p->conversion == 'o' || p-> conversion == 'O')) ? ft_crutchforhash(p, '0', p->w - size) : 0;
		(p->w && !p->pr && !p->f_zero && p->ispos != 0 && !p->f_minus) ? ft_crutchforhashv2(p, ' ', p->w - size) : 0;
		(p->w && !p->pr && !p->f_zero && p->ispos == 0) ? ft_putnchar(' ', p->w - size) : 0;//
		(!p->w && !p->pr && !p->f_minus && p->ispos == 1) ? ft_printhash(p->conversion) : 0;
		(p->f_minus && p->f_zero && p->w && p->ispos != 0) ? ft_printhash(p->conversion) : 0;
		(!p->w && !p->pr && p->ispos != 0 && p->mod == 4) ? ft_printhash(p->conversion) : 0;*/

		//(p->f_minus && p->f_zero && p->w) ? ft_printhash(p->conversion) : 0;
}


void	ft_handleneg(f_list *p, int size)
{
	//printf("----------------<>>>>>>>>>>>>>>>>>>>>. picha\n");
	/*(p->ispos == 2) ? size += 1 : 0;
	//(p->ispos == 2) ? ft_putchar('-') : 0;
	//(p->f_zero && p->w && !p->pr) ? ft_putchar('-') : 0;
	(p->w && p->pr && p->w > p->pr && p->f_zero && !p->f_minus) ? ft_puttriplecratch('-', '0', p->w - p->pr - 1, p->pr - size + 1) : 0; 
	(p->w && p->pr && p->w > p->pr && p->f_zero && p->f_minus) ? ft_putcratch('-', '0', p->w - 1 - p->pr)  : 0;
	(p->w && p->pr && p->w > p->pr && !p->f_zero && !p->f_minus) ? ft_puttriplecratch('-', '0', p->pr - size, p->w - p->pr) : 0;
	(p->w && p->pr && p->w > p->pr && !p->f_zero && p->f_minus) ? ft_putcratch('-', '0', p->w - p->pr) : 0;
	(p->w && p->pr && p->w < p->pr) ? ft_putcratch('-','0',p->pr - size + 1) : 0;
	(p->f_zero && p->w && !p->pr && p->conversion != 'x' && p->conversion != 'X' && !p->f_minus) ? ft_putcratch('-','0',p->w - size) : 0;
	//(p->w && !p->pr && (p->conversion == 'x' || p->conversion == 'X')) ? ft_putnchar('0',p->w - size) : 0;
	(!p->w && p->pr && !p->f_zero && !p->f_minus) ? ft_putcratch('-','0',p->pr - size + 1) : 0;
	(!p->w && p->pr && !p->f_zero &&  p->f_minus) ? ft_putcratch('-','0',p->pr - size + 1) : 0;
	(p->w && !p->pr && !p->f_zero && !p->f_minus) ? ft_putnchar(' ', p->w - size ) : 0;
	//(p->ispos == 2 && !p->f_zero) ? ft_putchar('-') : 0;
	(p->ispos == 2 && p->f_zero && !p->w) ? ft_putchar('-') : 0;
	(p->ispos == 2 && p->f_minus) ? ft_putchar('-') : 0;
	(p->ispos == 2 && !p->f_minus && p->f_plus && !p->f_zero) ? ft_putchar('-') : 0;
	(p->ispos == 2 && !p->f_minus && !p->f_plus && !p->f_zero && !p->w && !p->pr) ? ft_putchar('-') : 0;
	(p->ispos == 2 && !p->f_minus && !p->f_plus && !p->f_zero && p->w && !p->pr) ? ft_putchar('-') : 0;*/

	//(!p->w && !p->pr) ? ft_putchar('-') : 0;//there is a fucking bug for negative num !!!!!!!!!!!! ---------------->>>>>>>>>>>>>>>>>you must  fucking fix it picha!*/

}

int	ft_handleright(f_list *p, int size)
{
	//printf("--------------->>>>>>>>>>>. %d\n", p->ispos);	
	if (p->ispos == 2 && p->conversion != 'x' && p->conversion != 'X' && p->conversion != 'u' && p->conversion != 'U' && p->mod != 3 && p->mod != 4)
	{
		ft_handleneg(p, size);
	}
	else
		ft_handlepos(p, size);
	return (size); ///this is void!!!!!!!!!!
}






int		ft_checkflag(f_list *p, void *arg, int size)
{
	long long	temp;
	//printf("fuck\n");
	temp = (long long)arg;
	//printf("fuck\n");
	/*if ((int)arg < 0)
	{
		temp *= -1;
		p->ispos = 2;
	}*/
	if (!p->f_minus)
	{
		ft_handleright(p, size);
		ft_handledigits(p, arg, p->mod);
	}
	else if (p->f_minus)
	{
		//ft_handleright(p, size);
		ft_handledigits(p, arg, p->mod);
		ft_handleleft(p, size);
	}
	return(size);
}



