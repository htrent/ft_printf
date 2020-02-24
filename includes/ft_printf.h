/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:53:54 by htrent            #+#    #+#             */
/*   Updated: 2020/02/24 18:12:27 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# define NO_PRECISION -1

# define NO_FLAGS	0
# define F_SHARP	1
# define F_ZERO		2
# define F_MINUS	4
# define F_PLUS		8
# define F_SPACE	16

# define TO_SHARP	0
# define TO_ZERO	1
# define TO_MINUS	2
# define TO_PLUS	3
# define TO_SPACE	4

# define NO_SIZE		0
# define HH_SIZE		1
# define H_SIZE			2
# define L_SIZE			3
# define LL_SIZE		4
# define L_UPPER_SIZE	5
# define J_SIZE			6
# define Z_SIZE			7
# define T_SIZE			8

# define BUFF_SIZE		1000

# define NUM_SIZE		60000
# define POW_5_27	7450580596923828125

typedef	struct			s_printf
{
	va_list				params;
	char				*format;
	int					flags;
	int					width;
	int					precision;
	int					size;
	int					count_char;
	int					count_buf;
	char				buf[BUFF_SIZE + 1];
	int					len_num1_2;
	int					len_num1;
}						t_printf;

typedef	struct			s_double
{
	unsigned long long	m : 64;
	unsigned long long	e : 15;
	unsigned long long	s : 1;
}						t_double;

union					u_number
{
	t_double			bits;
	long double			num;
};
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
char					*ft_utoa_base(uintmax_t num, int base);
char					*ft_str_to_upper(char *str);
void					ft_bzero(void *s, size_t n);
void					*ft_memset(void *b, int c, size_t len);
int						ft_memdel(void **ap);
void					ft_putstr_buf(char *str, char buf[BUFF_SIZE],
						t_printf *data);
void					ft_putchar_buf(char c, char buf[BUFF_SIZE],
						t_printf *data);
void					ft_putstr_pft(char buf[BUFF_SIZE], t_printf *data);
t_printf				*init_data(const char *format, int *a);
int						put_data(t_printf *data, int *k);
int						manage_var(t_printf *data, int *k);
int						put_data_ouxb(t_printf *data, int *k);
char					*ft_fillbegin_x(t_printf *data, char *str, char *num);
char					*ft_fillend_x(t_printf *data, char *str, char *num);
int						put_data_zero(t_printf *data, int *k);
void					ft_put_percent(t_printf *data);
int						put_data_exception(t_printf *data, int *k);
void					ft_fillbegin(t_printf *data, intmax_t num,
						char *s, int digits);
void					ft_fillend(t_printf *data, intmax_t num,
						char *s, int digits);
int						put_data_di(t_printf *data, int *k);
int						manage_width(t_printf *data, int *k);
int						manage_precision(t_printf *data, int *k);
int						manage_size(t_printf *data, int *k);
int						manage_flags(t_printf *data, int *k);
intmax_t				max(intmax_t a, intmax_t b);
intmax_t				ft_pow_10(int n);
uintmax_t				ft_pow_10_u(int n);
int						ft_is_flag(char c);
int						ft_is_size(char c);
int						put_data_u(t_printf *data, int *k, uintmax_t num);
void					ft_fillbegin_u(t_printf *data, uintmax_t num,
						char *s, int digits);
void					ft_fillend_u(t_printf *data, intmax_t num,
						char *s, int digits);
int						put_data_p(t_printf *data, int *k);
char					*ft_utoa_base_p(uintmax_t num,
						int base, t_printf *data);
int						put_data_o(t_printf *data, int *k, uintmax_t num);
char					*ft_fillbegin_o(t_printf *data, char *str, char *num);
char					*ft_fillend_o(t_printf *data, char *str, char *num);
int						put_data_c(t_printf *data, int *k);
int						put_data_zero_c(t_printf *data, int *k);
int						put_data_s(t_printf *data, int *k);
int						put_data_f(t_printf *data, int *k);
int						put_data_zero_o(t_printf *data, int *k);
int						edge_di(t_printf *data, int *k);
int						first_init_begin(t_printf *data, intmax_t *num,
						int *i, char *s);
void					ft_itoa_di(char *s, int digits, intmax_t num, int *i);
void					first_init_end(t_printf *data, intmax_t *num,
						int *i, char *s);
intmax_t				init_size_di(t_printf *data);
void					fill_zeros(int *a, int b, int *i, char *s);
uintmax_t				init_size_ouxb(t_printf *data);
int						parse_args(t_printf *data, int *k, uintmax_t num);
void					check_sharp(t_printf *data, char *str, int *i);
void					action1_x(t_printf *data, int *prec,
						int *width, int key);
void					action2_x(t_printf *data, int *width, int key);
void					help_x_noprec(t_printf *data);
void					check_sharp(t_printf *data, char *str, int *i);
int						parse_args(t_printf *data, int *k, uintmax_t num);
int						put_data_b(t_printf *data, int *k, uintmax_t num);
char					*ft_fillbegin_b(t_printf *data, char *str, char *num);
char					*ft_fillend_b(t_printf *data, char *str, char *num);
void					check_sharp_b(t_printf *data, char *str, int *i);
int						put_data_s_null(t_printf *data, int *k);
void					help1_s(char *buf, int *prec, int *i, char *s);
void					help2_s(t_printf *data, int n, int *i, char *buf);
void					help3_s(t_printf *data, int n, int *i, char *buf);
int						init_s(t_printf *data, int *prec, int *n, char *s);
void					fill_spaces(int *a, int b, int *i, char *s);
int						init_p(t_printf *data, char *s, int *n, int *i);
int						init_c(t_printf *data, int *i);
int						init_c_zero(t_printf *data, int *i, int *width);
void					help_o_prec(t_printf *data, int *prec, int *width);
void					help_o_no_prec(t_printf *data, int *width);
int						put_data_r(t_printf *data, int *k);
int						manage_color(t_printf *data, int *k);
void					move_str(char *str, char *s, int *i);
void					add_pow_five(char big_num[NUM_SIZE], int power);
void					add_pow_two(char big_num[NUM_SIZE], int power);
void					ft_fill(t_printf *data, char *big_num1,
						char *big_num2, int k);

#endif
