/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:00:25 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/01/10 14:00:34 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef	struct  				p_list
{
	char						f_oct;
	char						f_plus;
	char						f_l;
	char						f_zero;
	char						f_space;
	int							w;
	int			 				pr;
	int							m;
	char						c;
	int							n;
	int 						crutchmark;
	int 						prc;
}								f_list;



void	ft_putnnstr(const char *str, int start);
void	ft_putnnnstr(const char *str, int start, int end);
int		ft_isconv(char c);
int		ft_ismod(char c);
void 	ft_parseprec(const char *f, int *i, f_list *p);
void 	ft_handlepos1(f_list *p, int size);
void	ft_handlepos2(f_list *p, int size);
void	ft_handlepos3(f_list *p, int size);
void	ft_handlepos4(f_list *p, int size);
void	ft_handlepos5(f_list *p, int size);
void	ft_handlepercent(f_list *p, int size);
void	ft_handlerightsideinleft(f_list * p, int size);
void	ft_handlep(f_list *p, int size);
void	ft_handlehash(f_list *p, int size);
int 	ft_dsize(f_list *p, int r, int size);
int 	ft_mainsize(f_list *p, int r, int s);
int 	ft_getpsize(f_list *p, int r, int s);
int 	ft_getstrsize(f_list *p, void *arg, int s);
int		ft_printstrsize(f_list *p, void *arg, int s);
int 	ft_hhbase(signed char arg, int base,  int s, f_list *p);
int 	ft_hbase(unsigned short arg, int base,  int s, f_list *p);
int		ft_intbase(int arg, int base, int s);
int 	ft_expand(f_list *p, void *arg, intmax_t temp, int s);
int 	ft_expand2(f_list *p, intmax_t temp,  void *arg,  int s);
int		ft_unsbase(uintmax_t arg, uintmax_t base, int s);
int	    ft_base(intmax_t arg, intmax_t base, int s);
int		getunsignsize(f_list *p, void *arg, uintmax_t systembase, int s);
int		ft_getsignsize(f_list *p, void *arg, intmax_t systembase, int s);
int 	ft_gethexsize(f_list *p, uintmax_t temp, uintmax_t systembase, int s);
void	ft_putpoint(void *arg, f_list *p);
void	ft_putbinary(int arg);
void	ft_printhash(char c);







void	ft_putstr(char const *s);
char	*ft_strchr(const char *str, int symbol);
int		ft_checkflags(char *str);
int		ft_strcmp(const char *s1, const char *s2);
int				ft_atoi(const char *str);
int			ft_getwidth(const char *format, int *i);
int			get_precision(const char *format, int *index);
int		ft_isdigit(int c);
int		get_mod(const char *format, int *i);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isflag(char c);
int			ft_checkisnorepeat(char cinlist, char c);
void	ft_errorrepeatflag();
char	get_conversion(const char *format, int *i);
void		ft_printchar(f_list *params, unsigned char c, int size);
int		ft_printstr(f_list *params, char *str, int size);

void		ft_handlestr(f_list *p, void *arg, int size);

void		ft_handledigits(f_list *params, void *arg, int val);
void		ft_putnbr(f_list *p, intmax_t n);
void	ft_putunnbr(uintmax_t n);
void		ft_putnchar(char c, int size);
void	ft_printhash(char c);
void	ft_putcratchv2(char c1, char c2, int size);
void	ft_putcratch(char c1, char c2, int size);
void	ft_puthex(char c, f_list *p, uintmax_t arg);
void	ft_putocto(f_list *p, uintmax_t arg);

void	ft_printcocto(f_list *p, void *i, int val);
void	ft_printhex(char c,f_list *p, void *i, int val);
void		ft_printdecimal(f_list *p, void *i, int val);
void		ft_printudecimal(f_list *p, void *i, int val);
void	ft_putcratch(char c1, char c2, int size);
void	ft_putcratchv2(char c1, char c2, int size);
void	ft_tcrutch(char c2, char c3, int size, int size2);
void	ft_dcrutch(char c1, char c2, int size, int size2);
void	ft_printhash(char c);
int		ft_checkmodifiers(f_list *p);
int		ft_deepprint(f_list *p, void *arg, int size);
void	ft_handleleft(f_list *p, int size);
void	ft_handleright(f_list *p, void *arg,  int size);
void	ft_handleneg(f_list *p, int size);
void	ft_handlepos(f_list *p, void *arg, int size);
int		ft_getargsize(f_list *p, void *arg);
int		ft_checkmodifiers(f_list *p);
int		ft_getargsize(f_list *p, void *arg);
int 	ft_getsizehexoctbi(f_list *p, void *arg);
int 	ft_printf(const char *format, ... );
int	    ft_printsize(f_list *p, int size);
int		ft_printstrsize(f_list *p, void *arg, int size);
int		ft_checkispossibletoputthisbitchinchar(const char *format, int i);
int	ft_base(intmax_t arg, intmax_t base, int size);
int	ft_unsbase(uintmax_t arg, uintmax_t base, int size);
int		ft_getintsize(void *arg, int systembase, int size, f_list *p);
int	ft_intbase(int arg, int base, int size);
int		getunsignsize(f_list *p, void *arg, uintmax_t systembase, int size);
f_list		*ft_getflag(char c, f_list *params);

void 	ft_hash(f_list *p, char c, int size);
void	ft_handlehash(f_list *p, int size);
void 	ft_hashv2(f_list *p, char c, int size);
int 	ft_printf(const char *format, ... );
void 	ft_hash(f_list *p, char c, int size);
void 	ft_hashv3(f_list *p,char c,  int size, int size2);
size_t		ft_strlen(const char *str);
void	ft_putchar(char c);
int		ft_parse(const char *format, int *i, va_list args);
void 	ft_postparse(char *format, char *crutch, char *crutchpr, f_list *p);
void	ft_putnstr(char *str, int size);
int		printallshit(f_list *p, va_list args);
void	ft_printlongdecimal(f_list *p, void *i, int val);
void	ft_printnotvalid(void *i, int* index);

int 	ft_hhbase(signed char arg, int base,  int size, f_list *p);
void	ft_puthhocto(f_list *p, unsigned char arg);
void 	ft_hashv4(f_list *p, char c, int size);



#endif