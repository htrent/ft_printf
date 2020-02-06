/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:53:54 by htrent            #+#    #+#             */
/*   Updated: 2020/02/06 20:04:21 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
//////////////////////
#include <stdio.h> //////DELETE!!!!!!!!!!!
//////////////////////
# define NO_PRECISION -1

# define NO_FLAGS	0  //00000
# define F_SHARP	1  //00001
# define F_ZERO		2  //00010
# define F_MINUS	4  //00100
# define F_PLUS		8  //01000
# define F_SPACE	16 //10000

# define TO_SHARP	0
# define TO_ZERO	1
# define TO_MINUS	2
# define TO_PLUS	3
# define TO_SPACE	4

# define NO_SIZE		0
# define L_SIZE			1
# define H_SIZE			2
# define LL_SIZE		3
# define HH_SIZE		4
# define L_UPPER_SIZE	5
# define J_SIZE			6
# define Z_SIZE			7
# define T_SIZE			8

# define BUFF_SIZE		100

# define NUM_SIZE		4940
# define POW_5_27	7450580596923828125

typedef	struct		s_printf
{
	va_list			params;
	char			*format;
	int 			flags;
	int		 		width;
	int				precision;
	int 			size;
	int 			count_char;
	char			buf[BUFF_SIZE + 1];
}					t_printf;



int						ft_printf(const char *format, ...);
size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *s1);
char					*ft_strchr(const char *s, int c);
int						ft_istrchr(const char *str, int c);
int						ft_atoi(const char *str);
int						ft_isdigit(int c);
int						ft_toupper(int c);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_itoa(int n);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
int						ft_count_of_digits(intmax_t n);
int						ft_count_of_digits_u(uintmax_t n);
char 					*ft_utoa_base(uintmax_t num, int base);
char					*ft_str_to_upper(char *str);
void					ft_bzero(void *s, size_t n);
void					*ft_memset(void *b, int c, size_t len);

void	ft_putstr_buf(char *str, char buf[BUFF_SIZE + 1]);
void	ft_putchar_buf(char c, char buf[BUFF_SIZE + 1]);

t_printf				*init_data(const char *format);
int						put_data(t_printf *data, int *k);
int						manage_var(t_printf *data, int *k);
int 					put_data_ouxX(t_printf *data, int *k);
char					*ft_fillbegin_xX(t_printf *data, char *str, char *num);
char					*ft_fillend_xX(t_printf *data, char *str, char *num);
int						put_data_zero(t_printf *data, int *k);
int						ft_put_percent(t_printf *data);
int						put_data_exception(t_printf *data, int *k);
void					ft_fillbegin(t_printf *data, intmax_t num, char *s, int digits);
void					ft_fillend(t_printf *data, intmax_t num, char *s, int digits);
int						put_data_di(t_printf *data, int *k);
int						manage_width(t_printf *data, int *k);
int						manage_precision(t_printf *data, int *k);
int						manage_size(t_printf *data, int *k);
int 					manage_flags(t_printf *data, int *k);
intmax_t				max(intmax_t a, intmax_t b);
intmax_t				ft_pow_10(int n);
uintmax_t				ft_pow_10_u(int n);
int						ft_is_flag(char c);
int						ft_is_size(char c);
int						put_data_u(t_printf *data, int *k, uintmax_t num);
void					ft_fillbegin_u(t_printf *data, uintmax_t num, char *s, int digits);
void					ft_fillend_u(t_printf *data, intmax_t num, char *s, int digits);
int 					put_data_p(t_printf *data, int *k);
char 					*ft_utoa_base_p(uintmax_t num, int base, t_printf *data);
int 					put_data_o(t_printf *data, int *k, uintmax_t num);
char 					*ft_fillbegin_o(t_printf *data, char *str, char *num);
char 					*ft_fillend_o(t_printf *data, char *str, char *num);
int 					put_data_c(t_printf *data, int *k);
int						put_data_zero_c(t_printf *data, int *k);
int 					put_data_s(t_printf *data, int *k);
int 					put_data_f(t_printf *data, int *k);
int 					put_data_zero_o(t_printf *data, int *k);
int						edge_di(t_printf *data, int *k);
int						first_init_begin(t_printf *data, intmax_t *num, int *i, char *s);
void					ft_itoa_di(char *s, int digits, intmax_t num, int *i);
void					first_init_end(t_printf *data, intmax_t *num, int *i, char *s);
intmax_t				init_size_di(t_printf *data);
void					fill_zeros(int *a, int b, int *i, char *s);
uintmax_t				init_size_ouxX(t_printf *data);
int						parse_args(t_printf *data, int *k, uintmax_t num);
void					check_sharp(t_printf *data, char *str, int *i);
#endif
