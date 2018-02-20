
#include "includes/ft_printf.h"

void	ft_handleBITCH(f_list *p, int size)
{
	(p->w && !p->f_minus) ? ft_putnchar(' ', p->w - size) : 0;
}

void	ft_handlerightsideinleft(f_list * p, int size)
{
	(p->w > p->pr && p->pr >= size && !p->f_plus && p->f_minus && p->f_zero) ? ft_putnchar('0',p->pr -size) : 0;
	(p->w && p->pr && p->w > p->pr  && p->w > size && p->pr >= size && p->f_plus && p->f_minus) ? ft_putcratch('+','0', p->pr - size) : 0;
	(p->w && p->pr && p->w > p->pr && !p->f_plus) ? ft_putnchar('0', p->pr - size) : 0 ;
	(p->w && p->pr && p->pr > p->w) ? ft_putnchar('0', p->pr - size) : 0;
}


void	ft_handlewpr(f_list *p, int size)
{

}



void	ft_handlepos(f_list *p, int size)
{
	
		//if (p->f_minus)
		//	ft_handlerightsideinleft(p, size);
		//else
		//{
		if ((p->w || p->pr) && !p->f_plus && !p->f_zero && !p->f_space) //// only width and precision
		{
			//printf("bitch\n");
			(p->w && !p->pr && p->w >= size) ? ft_putnchar(' ', p->w - size) : 0; //10
			(p->pr && !p->w && p->pr >= size) ? ft_putnchar('0', p->pr - size) : 0; // .10
			(p->w && p->pr && p->w > p->pr && p->pr > size && !p->f_minus) ? ft_putdoublecratch(' ', '0', p->w - p->pr, p->pr - size) : 0; // 10.8
			(p->w && p->pr && p->w > p->pr && p->pr > size && p->f_minus) ? ft_putnchar('0', p->pr - size) : 0; // 10.8
			(p->w && p->pr && p->w > p->pr && p->pr < size) ? ft_putnchar(' ', p->w - size) : 0; // 10.1 size 2
			(p->w && p->pr && p->pr > p->w && !p->f_oct) ? ft_putnchar('0', p->pr - size) : 0; // 10.15 // 10.15
			(p->w && p->pr && p->w == p->pr && !p->f_oct) ? ft_putnchar('0', p->pr - size) : 0; //15.15
		}
		else if ((p->w || p->pr) && p->f_plus && !p->f_zero)  /// width/precision and plus
		{
			(p->w && !p->pr && p->w >= size && p->f_plus) ? ft_putcratchv2(' ', '+', p->w - size - 1) : 0;  //+10
			(p->pr && !p->w && p->pr >= size && p->f_plus) ? ft_putcratch('+', '0', p->pr - size) : 0;      //+.10
			(p->w && p->pr && p->w > p->pr && p->pr > size) ? ft_puttriplecratch('+', '0',p->w - p->pr - 1, p->pr - size) : 0;  //+10.8
			(p->w && p->pr && p->w > p->pr && p->pr < size) ? ft_putcratchv2(' ', '+', p->w - size - 1) : 0;  //10.1 size 2
			(p->w && p->pr && p->pr > p->w ) ? ft_putcratch('+','0',p->pr - size) : 0;  //+8.10
			(p->w && p->pr && p->w == p->pr ) ? ft_putcratch('+','0',p->pr - size) : 0;  //+10.10
		}
		else if ((p->w || p->pr) && p->f_zero && !p->f_plus)  /// width/precision and zero without plus
		{
			(p->w && !p->pr && p->w >= size && p->f_zero) ? ft_putnchar('0', p->w - size) : 0; //010
			(p->pr && !p->w && p->pr >= size && p->f_zero) ? ft_putnchar('0', p->pr - size) : 0;      //0.10
			(p->w && p->pr && p->w > p->pr && p->pr > size) ? ft_putdoublecratch(' ','0',p->w - p->pr, p->pr - size) : 0;  //010.8
			(p->w && p->pr && p->w > p->pr && p->pr < size && !p->f_minus) ? ft_putnchar(' ', p->w - size) : 0;  //010.1 size 2
			(p->w && p->pr && p->pr > p->w ) ? ft_putnchar('0', p->pr - size) : 0;  //08.10
			(p->w && p->pr && p->w == p->pr ) ? ft_putnchar('0',p->pr - size) : 0;  //010.10
		}
		else if ((p->w || p->pr) && p->f_zero && p->f_plus && !p->f_space)  /// width/precision and zero and plus
		{
			(p->w && !p->pr && p->w >= size) ? ft_putcratch('+','0', p->w - size - 1) : 0; //+010
			(p->pr && !p->w && p->pr >= size) ? ft_putcratch('+', '0', p->pr - size) : 0;      //+0.10
			(p->w && p->pr && p->w > p->pr && p->pr > size) ? ft_puttriplecratch('+','0',p->w - p->pr - 1, p->pr - size) : 0;  //+010.8
			(p->w && p->pr && p->w > p->pr && p->pr < size) ? ft_putcratchv2(' ','+', p->w - size - 1) : 0;  //+010.1 size 2
			(p->w && p->pr && p->pr > p->w ) ? ft_putcratch('+', '0', p->pr - size) : 0;  //+08.10
			(p->w && p->pr && p->w == p->pr ) ? ft_putcratch('+','0',p->pr - size) : 0;  //+010.10
		}
		else if ((p->w || p->pr) && p->f_space && !p->f_plus)  /// width/precision and zero and plus
		{
			//printf("fuck\n");
			(p->w && !p->pr && p->w >= size && !p->f_zero && !p->f_oct) ? ft_putcratch(' ',' ', p->w - size - 1) : 0; // 1Ω
			(p->w && !p->pr && p->w >= size && p->f_zero) ? ft_putcratch(' ','0', p->w - size - 1) : 0; // 010
			(p->pr && !p->w && p->pr >= size) ? ft_putcratch(' ', '0', p->pr - size) : 0;      // 010
			(p->w && p->pr && p->w > p->pr && p->pr > size) ? ft_puttriplecratch(' ','0',p->w - p->pr - 1, p->pr - size) : 0;  //+010.8
			(p->w && p->pr && p->w > p->pr && p->pr < size) ? ft_putcratch(' ',' ', p->w - size - 1) : 0;  //+010.1 size 2
			(p->w && p->pr && p->pr > p->w ) ? ft_putcratch(' ', '0', p->pr - size) : 0;  //+08.10
			(p->w && p->pr && p->w == p->pr ) ? ft_putcratch(' ','0',p->pr - size) : 0;  //+010.10
		}
		else if (!p->w && !p->pr && p->f_space && !p->f_plus)  /// width/precision and zero and plus
		{
			ft_putchar(' ');
		}
		//(p->f_plus) ? size += 1 : 0;
		//printf("-=----------------------------.>>>>>>>>>>>>>>>>>>. picha\n");
			//printf("-------------- %d\n", size);
		/*(p->w && !p->pr && !p->f_zero && p->ispos == 1 && !p->f_minus && p->conversion) ? ft_putnchar(' ', p->w - size) : 0;
		(p->w && p->conversion == 0 && !p->f_minus) ? ft_putnchar(' ', p->w - size - 1) : 0;
		(p->w > size && p->f_plus && !p->pr) ? ft_putcratch('+', '0', p->w - size) : 0;
		

		(p->w > size && p->pr && p->pr > size && !p->f_plus && p->f_minus && p->f_zero) ? ft_putnchar('0', p->w - size) : 0;/////////////------------------
		(p->w > p->pr && p->pr >= size && !p->f_plus && !p->f_minus && p->f_zero) ? ft_putdoublecratch(p, '0',p->w - p->pr, p->pr - size) : 0;
		(p->pr > p->w  && p->w > size && !p->f_plus ) ? ft_putnchar('0', p->pr - size) : 0;
		
		(p->w && p->pr && p->w > p->pr  && p->w > size && p->pr >= size && p->f_plus && !p->f_minus) ? ft_puttriplecratch('+','0',p->w - p->pr - 1, p->pr - size) : 0;///////////
		///////////
		(p->w < p->pr  && p->w > size && !p->f_minus && p->f_plus) ? ft_putcratch('+','0', p->pr - size) : 0;
		(p->f_plus && !p->w) ? ft_putchar('+') : 0;
		//(p->pr > size && !p->f_plus && !p->f_minus) ? ft_putnchar('0', p->pr - size) : 0; /////////this is a place with size bug
		(p->f_space && !p->f_plus && !p->w && !p->pr) ? ft_putchar(' ') : 0;
		//(p->w && p->pr && p->w > p->pr && !p->f_zero) ? ft_putnchar(' ', p->w - size) : 0;
		(!p->w && p->pr && p->pr > size) ? ft_putnchar('0', p->pr - size) : 0;


		(p->f_zero && p->w && !p->pr) ? ft_putnchar('0', p->w - size) : 0;
		(p->w && p->pr && !p->f_plus && !p->f_zero && p->w > p->pr) ? ft_putdoublecratch(p, '0', p->w - size - 1, p->pr - size) : 0; ///   10.5
		(p->w && p->w >= size && !p->pr && !) ? ft_putnchar(' ', p->w - size) : 0; /// 15*/

		//}
}


int	ft_handleleft(f_list *p, int size)
{
	(p->ispos == 2) ? size += 1 : 0;
	(p->f_oct && (p->conversion == 'x' || p->conversion == 'X')) ? size += 2 : 0;
	(p->f_oct && (p->conversion == 'o' || p->conversion == 'O')) ? size += 1 : 0;
	(p->w && !p->pr && !p->f_oct) ? ft_putnchar(' ', p->w - size) : 0;
	(p->w && p->pr && p->w > p->pr && !p->f_oct) ? ft_putnchar(' ', p->w - p->pr - 1) : 0;
	(p->w && !p->pr && p->w >= size && p->f_oct) ? ft_putnchar(' ', p->w - size) : 0;
	(p->w && p->pr && p->w > p->pr && p->f_oct) ? ft_putnchar(' ', p->w - size) : 0;
	//(p->w && !p->pr && p->w > p->pr && p->f_oct) ? ft_putnchar(' ', p->w - p->pr - 2) : 0;


	/*(p->f_plus) ? size += 1 : 0;
	(p->f_oct && (p->conversion == 'o' || p->conversion == 'O')) ? size += 2 : 0;
	(p->ispos == 2) ? size += 1 : 0;
	(p->f_oct && (p->conversion == 'o' || p->conversion == 'O')) ? size -= 1 : 0;
	
	(p->w && p->pr && p->w > p->pr && p->f_zero) ? ft_putnchar(' ', p->w - p->pr - 1) : 0;
	(p->w && !p->pr && !p->f_zero && p->conversion != '%' && p->conversion != 'o' && p->conversion != 'O' && p->conversion) ? ft_putnchar(' ', p->w - size) : 0;
	(p->w && p->conversion == 0) ? ft_putnchar(' ', p->w - size - 1) : 0;
	(p->w && !p->pr && !p->f_zero &&(p->conversion == 'o' || p->conversion == 'O')) ? ft_putnchar(' ', p->w - size) : 0;
	
	(p->w && !p->pr && !p->f_zero && p->conversion == '%') ? ft_putnchar(' ', p->w - size) : 0;
	(p->w && p->pr && !p->f_zero && p->w > p->pr && !p->f_plus) ? ft_putnchar(' ', p->w - p->pr) : 0; //////////////some changes here
	(p->w && p->pr && !p->f_zero && p->w > p->pr && p->f_plus) ? ft_putnchar(' ', p->w - p->pr - 1) : 0; //////////////some changes here
	(p->w && !p->pr && p->f_zero && p->f_oct && p->f_minus) ? ft_putnchar(' ', p->w - size - 2) : 0;
	(p->w && p->f_zero && !p->pr && !p->f_minus) ? ft_putnchar(' ', p->w - size) : 0 ;
	(p->f_zero && p->w && p->ispos == 2) ? ft_putnchar(' ', p->w - size) : 0;
	(p->w && p->f_zero && p->f_minus && p->ispos == 1 && !p->f_oct) ? ft_putnchar(' ', p->w - size) : 0;

	//(p->conversion == 0 && p->w) ? ft_putnchar(' ', p->w - size) : 0;
	(p->f_oct) ? size += 2 : 0;
	if(p->w && !p->pr)
	{
		(p->w && !p->f_plus) ? ft_putnchar(' ', p->w - size) : 0;
		(p->w && p->f_plus) ? ft_putnchar(' ', p->w - size - 1) : 0;
	}
	else if (p->w && p->pr)
	{
		(p->w > p->pr && !p->f_oct && !p->f_plus) ? ft_putnchar(' ', p->w - p->pr) : 0;
		(p->w > p->pr && !p->f_oct && p->f_plus) ? ft_putnchar(' ', p->w - 1 - p->pr) : 0;
		(p->w > p->pr && p->f_oct) ? ft_putnchar(' ', p->w - size) : 0;
	}*/


	return (size); /// this is void!!
}

void	ft_handlehash(f_list *p, int size)
{
	//	printf("---------->>>>>>> %d\n", size);
		//((p->conversion == 'x') || (p->conversion == 'X')) ? size += 2 : 0;
		((p->conversion == 'o') || (p->conversion == 'O')) ? size += 1 : 0;
		(p->w && !p->pr && p->w >= size && !p->f_minus) ? ft_crutchforhashv2(p, ' ', p->w - size) : 0; //10
		(p->w && !p->pr && p->w >= size && p->f_minus) ? ft_printhash(p->conversion) : 0; //10
		(!p->w && p->pr && p->pr >= size && !p->f_minus) ? ft_crutchforhashv2(p, '0', p->pr - size) : 0; //.10
		(!p->w && p->pr && p->pr >= size && p->f_minus) ? ft_crutchforhash(p, '0', p->pr - size) : 0; //.10
		(p->w && p->pr && p->w > p->pr && p->w >= size && (p->conversion == 'x' || p->conversion == 'X')) ? ft_crutchforhashv3(p, '0',p->w - p->pr - 2, p->pr - size) : 0; //15.10
		(p->w && p->pr && p->w > p->pr && p->w >= size && (p->conversion == 'o' || p->conversion == 'O') && !p->f_minus) ? ft_crutchforhashv3(p, '0',p->w - p->pr, p->pr - size) : 0; //15.10
		(p->w && p->pr && p->w > p->pr && p->w >= size && (p->conversion == 'o' || p->conversion == 'O') && p->f_minus) ? ft_printhash(p->conversion) : 0;//15.10
		(p->w && p->pr && p->w == p->pr) ? ft_crutchforhashv3(p, '0',p->w - p->pr, p->pr - size) : 0; //10.10
		(p->w && p->pr && p->pr > p->w && p->pr >= size) ? ft_crutchforhashv3(p, '0',p->w - p->pr, p->pr - size) : 0; //10.15
		/*(!p->w && !p->pr) ? ft_printhash(p->conversion) : 0;
	
		(p->w && p->pr && p->pr > p->w && p->pr >= size) ? ft_crutchforhash(p,'0', p->pr - size) : 0;
	//	(p->w && !p->pr && p->w >= size) ? ft_crutchforhashv2(p, ' ', p->w - size - 2) : 0; //10
		(p->w && p->pr && p->w == p->pr) ? ft_crutchforhash(p, '0', p->pr - size) : 0; //15.15
		(p->w && !p->pr && p->w >= size) ? ft_crutchforhashv2(p, ' ', p->w - size - 2) : 0; //10.5
		(p->w && p->pr && p->w >= size && p->w > p->pr && p->pr >= size) ? ft_crutchforhash(p, '0', p->pr - size) : 0; //10.5
		(!p->w && p->pr && p->pr >= size) ? ft_crutchforhash(p, '0', p->pr - size) : 0;

		(p->f_oct && (p->ispos == 1 || p->ispos == 2)) ? size += 2 : 0;
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
	
		//if (p->f_minus)
		//	ft_handlerightsideinleft(p, size);
		//else
		//{
		if ((p->w || p->pr)) //// only width and precision
		{
			(p->w && !p->pr && p->w >= size ) ? ft_putchar('-') : 0; //10
			(p->pr && !p->w && p->pr >= size) ? ft_putcratch('-','0', p->pr - size) : 0; // .10
			(p->w && p->pr && p->w > p->pr && p->pr > size) ? ft_puttriplecratch('-', '0', p->w - p->pr, p->pr - size) : 0; // 10.8
			(p->w && p->pr && p->w > p->pr && p->pr < size && !p->f_minus) ? ft_putcratchv2(' ', '-', p->w - size - 1) : 0; // 10.1 size 2
			(p->w && p->pr && p->w > p->pr && p->pr < size && p->f_minus) ? ft_putchar('-') : 0; // 10.1 size 2
			(p->w && p->pr && p->pr > p->w) ? ft_putcratch('-','0', p->pr - size) : 0; // 10.15
			(p->w && p->pr && p->w == p->pr) ? ft_putcratch('-', '0', p->pr - size) : 0; //15.15
			(!p->w && p->pr && p->pr < size) ? ft_putchar('-') : 0;
		}
		/*else if ((p->w || p->pr) && p->f_zero)  /// width/precision and plus
		{
			(p->w && !p->pr && p->w >= size) ? ft_putcratch('-', '0', p->w - size - 1) : 0;  //010
			(p->pr && !p->w && p->pr >= size) ? ft_putcratch('-', '0', p->pr - size) : 0;      //0.10
			(p->w && p->pr && p->w > p->pr && p->pr > size) ? ft_puttriplecratch('-', '0',p->w - p->pr - 1, p->pr - size) : 0;  //010.8
			(p->w && p->pr && p->w > p->pr && p->pr < size) ? ft_putcratchv2(' ', '-', p->w - size - 1) : 0;  //010.1 size 2
			(p->w && p->pr && p->pr > p->w ) ? ft_putcratch('-','0',p->pr - size) : 0;  //08.10
			(p->w && p->pr && p->w == p->pr ) ? ft_putcratch('-','0',p->pr - size) : 0;  //010.10
		}*/
		/*else if ((p->w || p->pr) && p->f_zero && !p->f_plus && !p->f_space)  /// width/precision and zero without plus
		{
			(p->w && !p->pr && p->w >= size && p->f_zero) ? ft_putnchar('0', p->w - size) : 0; //010
			(p->pr && !p->w && p->pr >= size && p->f_zero) ? ft_putnchar('0', p->pr - size) : 0;      //0.10
			(p->w && p->pr && p->w > p->pr && p->pr > size) ? ft_putdoublecratch(' ','0',p->w - p->pr, p->pr - size) : 0;  //010.8
			(p->w && p->pr && p->w > p->pr && p->pr < size) ? ft_putnchar(' ', p->w - size) : 0;  //010.1 size 2
			(p->w && p->pr && p->pr > p->w ) ? ft_putnchar('0', p->pr - size) : 0;  //08.10
			(p->w && p->pr && p->w == p->pr ) ? ft_putnchar('0',p->pr - size) : 0;  //010.10
		}*/
		/*else if ((p->w || p->pr) && p->f_zero && p->f_plus && !p->f_space)  /// width/precision and zero and plus
		{
			(p->w && !p->pr && p->w >= size) ? ft_putcratch('+','0', p->w - size - 1) : 0; //+010
			(p->pr && !p->w && p->pr >= size) ? ft_putcratch('+', '0', p->pr - size) : 0;      //+0.10
			(p->w && p->pr && p->w > p->pr && p->pr > size) ? ft_puttriplecratch('+','0',p->w - p->pr - 1, p->pr - size) : 0;  //+010.8
			(p->w && p->pr && p->w > p->pr && p->pr < size) ? ft_putcratchv2(' ','+', p->w - size - 1) : 0;  //+010.1 size 2
			(p->w && p->pr && p->pr > p->w ) ? ft_putcratch('+', '0', p->pr - size) : 0;  //+08.10
			(p->w && p->pr && p->w == p->pr ) ? ft_putcratch('+','0',p->pr - size) : 0;  //+010.10
		}*/
		/*else if ((p->w || p->pr) && p->f_space && !p->f_plus)  /// width/precision and zero and plus
		{
			(p->w && !p->pr && p->w >= size && !p->f_zero) ? ft_putcratch(' ',' ', p->w - size - 1) : 0; // 10
			(p->w && !p->pr && p->w >= size && p->f_zero) ? ft_putcratch(' ','0', p->w - size - 1) : 0; // 010
			(p->pr && !p->w && p->pr >= size) ? ft_putcratch(' ', '0', p->pr - size) : 0;      // 010
			(p->w && p->pr && p->w > p->pr && p->pr > size) ? ft_puttriplecratch(' ','0',p->w - p->pr - 1, p->pr - size) : 0;  //+010.8
			(p->w && p->pr && p->w > p->pr && p->pr < size) ? ft_putcratch(' ',' ', p->w - size - 1) : 0;  //+010.1 size 2
			(p->w && p->pr && p->pr > p->w ) ? ft_putcratch(' ', '0', p->pr - size) : 0;  //+08.10
			(p->w && p->pr && p->w == p->pr ) ? ft_putcratch(' ','0',p->pr - size) : 0;  //+010.10
		}*/
		else if (!p->w && !p->pr)  /// width/precision and zero and plus
		{
			ft_putchar('-');
		}
	//}













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

	(p->negmark == 1 && p->f_zero && !p->w && p->mod == 0 && (p->conversion != 'o' || p->conversion != 'O')) ? ft_putchar('-') : 0;
	(p->negmark == 1 && p->f_minus && p->mod == 0 && (p->conversion != 'o' || p->conversion != 'O')) ? ft_putchar('-') : 0;
	(p->negmark == 1 && !p->f_minus && p->f_plus && !p->f_zero && p->mod == 0) ? ft_putchar('-') : 0;
	(p->negmark == 1 && !p->f_minus && !p->f_plus && !p->f_zero && p->w && !p->pr && p->mod == 0) ? ft_putchar('-') : 0;
	(p->negmark == 1 && !p->f_minus && !p->f_plus && !p->f_zero && !p->w && !p->pr && p->mod == 0) ? ft_putchar('-') : 0;
	(p->mod == 2 && p->negmark == 1 && (p->conversion != 'o' || p->conversion != 'O')) ? ft_putchar('-') : 0;*/

}

int	ft_handleright(f_list *p, int size)
{
	if (p->f_oct && ((p->conversion == 'x' || p->conversion == 'X') || (p->conversion == 'o') || p->conversion == 'O'))
	{
		ft_handlehash(p, size);
	}
	else if (p->conversion == '%')
		ft_handleBITCH(p, size);
	else if (p->ispos == 2 && p->conversion != 'x' && p->conversion != 'X' && p->conversion != 'u' && p->conversion != 'U' && p->mod != 3 && p->mod != 4 && p->conversion != 'o' && p->conversion != 'O')
	{
		ft_handleneg(p, size);
	}
	else
		ft_handlepos(p, size);
	return (size); ///this is void!!!!!!!!!!
}






int		ft_checkflag(f_list *p, void *arg, int size)
{
	if((int)arg < 0)
		p->negmark = 1;

	if (p->f_minus)
	{
		ft_handleright(p, size);
		ft_handledigits(p, arg, p->mod);
		ft_handleleft(p, size);
	}
	else
	{
		ft_handleright(p, size);
		ft_handledigits(p, arg, p->mod);
	}
	return(size);
}



