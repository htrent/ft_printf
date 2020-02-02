/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:58:37 by htrent            #+#    #+#             */
/*   Updated: 2020/02/02 12:56:07 by htrent           ###   ########.fr       */
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

# define MAX(a, b) (a > b) ? a : b

typedef	struct		s_printf
{
	va_list			params;
	char			*format;
	int 			flags;
	int		 		width;
	int				precision;
	int 			size;
	int 			count_char;
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
void					ft_putnbr(int n);
int						ft_count_of_digits(int64_t n);
char 					*ft_utoa_base(uint64_t num, int base);
char					*ft_str_to_upper(char *str);

int						put_data(t_printf *data, int *k);
int						manage_var(t_printf *data, int *k);
int 					put_data_ouxX(t_printf *data, int *k);
char					*ft_fillbegin_oxX(t_printf *data, char *str, char *num, int *k);
char					*ft_fillend_oxX(t_printf *data, char *str, char *num, int *k);
int						put_data_zero(t_printf *data, int *k);
int						ft_put_percent(t_printf *data);
int						put_data_percent(t_printf *data, int *k);
void					ft_fillbegin(t_printf *data, int64_t num, char *s, int digits);
void					ft_fillend(t_printf *data, int64_t num, char *s, int digits);
int						put_data_di(t_printf *data, int *k);
int						manage_width(t_printf *data, int *k);
int						manage_precision(t_printf *data, int *k);
int						manage_size(t_printf *data, int *k);
void					solve_flags(t_printf *data, int *k);
void					manage_flags(t_printf *data, int *k);
int64_t					max(int64_t a, int64_t b);
int64_t					ft_pow_10(int n);
int						ft_is_flag(char c);
int						ft_is_size(char c);
#endif
