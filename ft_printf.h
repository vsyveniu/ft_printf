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
	char						*justanothershittomanage;
	char						conversion;
	int							ispos;
}								f_list;



void	ft_putchar(char c);
void	ft_putstr(char const *s);
size_t		ft_strlen(const char *str);
char	*ft_strchr(const char *str, int symbol);
int		ft_checkflags(char *str);
int		ft_strcmp(const char *s1, const char *s2);
int				ft_atoi(const char *str);
f_list		*ft_getflag(const char *format,f_list *params, int *index);
int			ft_getwidth(const char *format, int *index);
int			get_precision(const char *format, int *index);
int		ft_isdigit(int c);
char	*get_justanothershittomanage(const char *format, int *index);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isflag(char c);
int			ft_checkisnorepeat(char cinlist, char c);
void	ft_errorrepeatflag();
char	get_conversion(const char *format, int *index);
void		ft_printchar(f_list *params, unsigned char c, int size);
int		ft_printstr(f_list *params, char *str, int size);
int		ft_handlestr(f_list *params, void *arg, int size);
void		ft_handledigits(f_list *params, void *arg, int val);
void		ft_putnbr(signed long long n);
void	ft_putunnbr(unsigned long long n);
void		ft_putnchar(char c, int size);
void	ft_printhash(char c);
void	ft_putcratchv2(char c1, char c2, int size);
void	ft_putcratch(char c1, char c2, int size);
void	ft_puthex(char conv, int arg);
void	ft_putocto(int arg);
void	ft_putbinary(int arg);
void	ft_printbinary(int i, int val);
void	ft_printcocto(int i, int val);
void	ft_printhex(char c, int i, int val);
void		ft_printdecimal(void *i, int val);
void		ft_printudecimal(void *i, int val);
void	ft_putcratch(char c1, char c2, int size);
void	ft_putcratchv2(char c1, char c2, int size);
void	ft_puttriplecratch(char c2, char c3, int size, int size2);
void	ft_putdoublecratch(f_list *p, char c2, int size, int size2);
void	ft_printhash(char c);
int		ft_checkmodifiers(f_list *p);
int		ft_checkflag(f_list *p, void *arg, int size, int val);
int	ft_handleleft(f_list *p,  int size);
int	ft_handleright(f_list *p,  int size);
void	ft_handleneg(f_list *p, int size);
void	ft_handlepos(f_list *p, int size);
int		ft_getargsize(f_list *p, void *arg);
int		ft_checkmodifiers(f_list *p);
int		ft_getargsize(f_list *p, void *arg);
int 	ft_getsizehexoctbi(f_list *p, void *arg);
int 	ft_printf(const char *format, ... );
int	ft_printsize(f_list *p, int size);
int		ft_printstrsize(f_list *p, int size);
int		ft_checkispossibletoputthisbitchinchar(const char *format, int i);
int	ft_base(long long arg, long long base, int size);
int	ft_unsbase(unsigned long long int arg, unsigned long long int base, int size);
int		ft_getintsize(void *arg, int systembase, int size);
int	ft_intbase(int arg, int base, int size);
int		getunsignsize(void *arg, unsigned long long systembase, int size, f_list *p);



#endif