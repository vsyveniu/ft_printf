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
	char						f_minus;
	char						f_zero;
	char						f_space;
	int							w;
	int			 				pr;
	int							mod;
	char						conversion;
	int							ispos;
	int 						negmark;
}								f_list;




void	ft_putstr(char const *s);
char	*ft_strchr(const char *str, int symbol);
int		ft_checkflags(char *str);
int		ft_strcmp(const char *s1, const char *s2);
int				ft_atoi(const char *str);
int			ft_getwidth(char *format, int *i);
int			get_precision(const char *format, int *index);
int		ft_isdigit(int c);
int		get_mod(char *format, int *i);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isflag(char c);
int			ft_checkisnorepeat(char cinlist, char c);
void	ft_errorrepeatflag();
char	get_conversion(char *format, int *i);
void		ft_printchar(f_list *params, unsigned char c, int size);
int		ft_printstr(f_list *params, char *str, int size);

void		ft_handlestr(f_list *p, void *arg, int size);

void		ft_handledigits(f_list *params, void *arg, int val, int*i);
void		ft_putnbr(intmax_t n);
void	ft_putunnbr(uintmax_t n);
void		ft_putnchar(char c, int size);
void	ft_printhash(char c);
void	ft_putcratchv2(char c1, char c2, int size);
void	ft_putcratch(char c1, char c2, int size);
void	ft_puthex(char c, unsigned long long int arg);
void	ft_putocto(unsigned long long int arg);
void	ft_putbinary(int arg);
void	ft_printbinary(int i, int val);
void	ft_printcocto(void *i, int val);
void	ft_printhex(char c, void *i, int val);
void		ft_printdecimal(void *i, int val);
void		ft_printudecimal(void *i, int val);
void	ft_putcratch(char c1, char c2, int size);
void	ft_putcratchv2(char c1, char c2, int size);
void	ft_puttriplecratch(char c2, char c3, int size, int size2);
void	ft_putdoublecratch(f_list *p, char c2, int size, int size2);
void	ft_printhash(char c);
int		ft_checkmodifiers(f_list *p);
int		ft_checkflag(f_list *p, void *arg, int size, int *i);
int	ft_handleleft(f_list *p,  int size);
int	ft_handleright(f_list *p,  int size);
void	ft_handleneg(f_list *p, int size);
void	ft_handlepos(f_list *p, int size);
int		ft_getargsize(f_list *p, void *arg);
int		ft_checkmodifiers(f_list *p);
int		ft_getargsize(f_list *p, void *arg);
int 	ft_getsizehexoctbi(f_list *p, void *arg);
int 	ft_printf(const char *format, ... );
int	ft_printsize(f_list *p, void *arg, int size);
int		ft_printstrsize(f_list *p, void *arg, int size);
int		ft_checkispossibletoputthisbitchinchar(const char *format, int i);
int	ft_base(intmax_t arg, intmax_t base, int size);
int	ft_unsbase(uintmax_t arg, uintmax_t base, int size);
int		ft_getintsize(void *arg, int systembase, int size, f_list *p);
int	ft_intbase(int arg, int base, int size);
int		getunsignsize(f_list *p, void *arg, uintmax_t systembase, int size);
f_list		*ft_getflag(char c, f_list *params);

void 	ft_crutchforhash(f_list *p, char c, int size);
void	ft_handlehash(f_list *p, int size);
void 	ft_crutchforhashv2(f_list *p, char c, int size);
int 	ft_printf(const char *format, ... );
void 	ft_crutchforhash(f_list *p, char c, int size);
void 	ft_crutchforhashv3(f_list *p, char c, char c2,  int size, int size2);
size_t		ft_strlen(const char *str);
void	ft_putchar(char c);
void	ft_printpointer(void *i);
void	ft_putpoint(void *arg);
int		ft_ismod(char c);
int		ft_isconv(char c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char 	*ft_parsecrutchw(char *temp);
char 	*ft_parsecrutchpr(char *temp);
int		ft_parse(char *format, int *i, va_list args);
void 	ft_postparse(char *format, char *crutch, char *crutchpr, f_list *p);
void	ft_putnstr(char *str, int size);
int		printallshit(f_list *p, va_list args, int *i);
void	ft_printlongdecimal(void *i, int val);
void	ft_printnotvalid(void *i, int* index);


#endif