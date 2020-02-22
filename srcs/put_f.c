/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:04:21 by htrent            #+#    #+#             */
/*   Updated: 2020/02/21 17:57:28 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef	struct	s_double
{
	unsigned long long	m : 64;
	unsigned long long	e : 15;
	unsigned long long	s : 1;
}				t_double;

union	u_number
{
	t_double		bits;
	long double 	num;
};

union code
{
	t_double	p;
	struct{
		unsigned long long a0 : 1;
		unsigned long long a1 : 1;
		unsigned long long  a2 : 1;
		unsigned long long  a3 : 1;
		unsigned long long  a4 : 1;
		unsigned long long  a5 : 1;
		unsigned long long  a6 : 1;
		unsigned long long  a7 : 1;
		unsigned long long  a8 : 1;
		unsigned long long  a9 : 1;
		unsigned long long  a10 : 1;
		unsigned long long  a11 : 1;
		unsigned long long  a12 : 1;
		unsigned long long  a13 : 1;
		unsigned long long  a14 : 1;
		unsigned long long  a15 : 1;
		unsigned long long  a16 : 1;
		unsigned long long  a17 : 1;
		unsigned long long  a18 : 1;
		unsigned long long  a19 : 1;
		unsigned long long  a20 : 1;
		unsigned long long  a21 : 1;
		unsigned long long  a22 : 1;
		unsigned long long  a23 : 1;
		unsigned long long  a24 : 1;
		unsigned long long  a25 : 1;
		unsigned long long  a26 : 1;
		unsigned long long  a27 : 1;
		unsigned long long  a28 : 1;
		unsigned long long  a29 : 1;
		unsigned long long  a30 : 1;
		unsigned long long  a31 : 1;
		unsigned long long  a32 : 1;
		unsigned long long  a33 : 1;
		unsigned long long  a34 : 1;
		unsigned long long  a35 : 1;
		unsigned long long  a36 : 1;
		unsigned long long  a37 : 1;
		unsigned long long  a38 : 1;
		unsigned long long  a39 : 1;
		unsigned long long  a40 : 1;
		unsigned long long  a41 : 1;
		unsigned long long  a42 : 1;
		unsigned long long  a43 : 1;
		unsigned long long  a44 : 1;
		unsigned long long  a45 : 1;
		unsigned long long  a46 : 1;
		unsigned long long  a47 : 1;
		unsigned long long  a48 : 1;
		unsigned long long  a49 : 1;
		unsigned long long  a50 : 1;
		unsigned long long  a51 : 1;
		unsigned long long  a52 : 1;
		unsigned long long  a53 : 1;
		unsigned long long  a54 : 1;
		unsigned long long  a55 : 1;
		unsigned long long  a56 : 1;
		unsigned long long  a57 : 1;
		unsigned long long  a58 : 1;
		unsigned long long  a59 : 1;
		unsigned long long  a60 : 1;
		unsigned long long  a61 : 1;
		unsigned long long  a62 : 1;
		unsigned long long  a63 : 1;
		unsigned long long  a64 : 1;
		unsigned long long  a65 : 1;
		unsigned long long  a66 : 1;
		unsigned long long  a67 : 1;
		unsigned long long  a68 : 1;
		unsigned long long  a69 : 1;
		unsigned long long  a70 : 1;
		unsigned long long  a71 : 1;
		unsigned long long  a72 : 1;
		unsigned long long  a73 : 1;
		unsigned long long  a74 : 1;
		unsigned long long  a75 : 1;
		unsigned long long  a76 : 1;
		unsigned long long  a77 : 1;
		unsigned long long  a78 : 1;
		unsigned long long  a79 : 1;
	} byte;
};

void	print_buf1(char big[NUM_SIZE])
{
	int i;

	i = NUM_SIZE - 1;
	ft_putstr("BUF1:\"");
	while (big[i] != -1)
		i--;
	i++;
	while (i < NUM_SIZE)
		ft_putchar(big[i++] + '0');
	ft_putstr("\"\n");
}

void	print_buf2(char big[NUM_SIZE])
{
	int i;

	i = 0;
	ft_putstr("BUF2:\"");
	while (big[i] != -1)
		ft_putchar(big[i++] + '0');
	ft_putstr("\"\n");
}

void	pow_two_under_64(int power, char *big_num)
{
	int						flag;
	int						j;
	unsigned long long int	number;

	j = NUM_SIZE - 1;
	flag = 0;
	number = (unsigned long long)1 << power;
	while (number > 0)
	{
		if (big_num[j] == -1)
			big_num[j] = 0;
		if (flag)
			big_num[j]++;
		flag = ((big_num[j] + (number % 10)) > 9) ? 1 : 0;
		big_num[j] = (big_num[j] + number % 10) % 10;
		number /= 10;
		j--;
	}
	while (flag)
	{
		big_num[j] = (big_num[j] == -1) ? 0 : big_num[j];
		flag = (big_num[j] + 1 > 9) ? 1 : 0;
		big_num[j] = (big_num[j] + 1) % 10;
		j--;
	}
}

void	array_sum(char *big_two, char *big_num, int j)
{
	int	flag;
	int	prev_flag;

	prev_flag = 0;
	flag = 0;
	while (big_two[j] != -1)
	{
		big_num[j] = (big_num[j] == -1) ? 0 : big_num[j];
		flag = ((big_num[j] + big_two[j]) > 9) ? 1 : flag;
		big_num[j] = (big_num[j] + big_two[j]) % 10;
		flag = ((prev_flag) && (big_num[j] + 1 > 9)) ? 1 : flag;
		big_num[j] = (prev_flag) ? (big_num[j] + 1) % 10 : big_num[j];
		prev_flag = flag;
		flag = 0;
		j--;
	}
	while (prev_flag)
	{
		big_num[j] = (big_num[j] == -1) ? 0 : big_num[j];
		prev_flag = (big_num[j] + 1 > 9) ? 1 : 0;
		big_num[j] = (big_num[j] + 1) % 10;
		j--;
	}
}

void	array_power(int power, char *big_two, int i)
{
	int	flag;
	int	prev_flag;
	int j;
	
	while (i < power - 63) //array power
	{
		j = NUM_SIZE - 1;
		prev_flag = 0;
		flag = 0;
		while (big_two[j] != -1) //array * 2
		{
			if (big_two[j] * 2 > 9)
				flag = 1;
			big_two[j] = (big_two[j] * 2) % 10;
			if (prev_flag)
				big_two[j]++;
			prev_flag = flag;
			flag = 0;
			j--;
		}
		if (prev_flag)
			big_two[j] = 1;
		i++;
	}
}

void pow_two_over_64(char *big_num, char *big_two, int power)
{
	int						i;
	int						j;
	unsigned long long int	number;

	i = 0;
	j = NUM_SIZE - 1;
	number = (unsigned long long)1 << 63;
	while (number > 0) //number to array
	{
		big_two[j--] = number % 10;
		number = number / 10;
	}
	j = NUM_SIZE - 1;
	array_power(power, big_two, i);
	array_sum(big_two, big_num, j);
}

void	add_pow_two(char big_num[NUM_SIZE], int power)
{
	char	big_two[NUM_SIZE];
	int i;
	int j;
	int flag;
	int prev_flag;

	j = NUM_SIZE - 1;
	i = 0;
	flag = 0;
	prev_flag = 0;
	ft_memset(big_two, -1, NUM_SIZE);
	if (power < 64)
		pow_two_under_64(power, big_num);
	else
		pow_two_over_64(big_num, big_two, power);
}

void rounding_off_2(char *big_num1, char *big_num2)
{
	int j;
	int flag;

	flag = 0;
	j = NUM_SIZE - 1;
	big_num2[0] = big_num2[0] % 10;
	if (big_num1[j] + 1 > 9)
			flag = 1;
	big_num1[j] = (big_num1[j] < 0) ? 1 : big_num1[j] + 1;
	//округление в четную сторону при .5 с точностью ноль
	while (flag && j)
	{
		big_num1[j] = big_num1[j] % 10;
		big_num1[j - 1] = (big_num1[j - 1] < 0) ? 1 : big_num1[j - 1] + 1;
		flag = (big_num1[j - 1] > 9) ? 1 : 0;
		j--;
	}
	//big_num1[j] = (big_num1[j] = -1) ? 1 : big_num1[j] + 1;
}

void rounding_off(char *big_num1, char *big_num2, t_printf *data)
{
	int i;
	int flag; 
	
	flag = 0;
	i = data->precision - 1;
	if (big_num2[i + 1] >= 5 && data->precision > 0)
	{
		if (big_num2[i] + 1 > 9)
			flag = 1;
		big_num2[i]++;
	}		
	while (flag && i)
	{
		big_num2[i] = big_num2[i] % 10;
		big_num2[i - 1]++;
		flag = (big_num2[i - 1] > 9) ? 1 : 0;
		i--;
	}
	if (flag || (data->precision == 0 && big_num2[0] >= 5))
		rounding_off_2(big_num1, big_num2);
}

void float_fillbegin(t_printf *data, char *big_num1, char *big_num2, char *s, int len)
{
	int j;
	int i;
	
	i = 0;
	j = NUM_SIZE - 1;
	if (big_num1[0] == 1)
		s[i] = '-';
	else if ((data->flags >> TO_PLUS) % 2)
		s[i] = '+';
	else if ((data->flags >> TO_SPACE) % 2 && big_num1[0] != 1)
		s[i] = ' ';
	i += len;
	while (big_num1[j] != -1 && j >= 0) //целая часть с конца
		s[--len] = big_num1[j--] + '0';
	if (data->precision != 0 || (data->precision == 0 && (data->flags >> TO_SHARP) % 2))
		s[i++] = '.';
	j = 0;
	while (j < data->precision) //дробная часть
	{
		s[i++] = (big_num2[j] == -1) ? '0' : big_num2[j] + '0';
		j++;
	}
	while  (i < data->width)
		s[i++] = ' ';
	ft_putstr_buf(s, data->buf, data);
	free(s);
}

void float_fillend(t_printf *data, char *big_num1, char *big_num2, char *s, int k)
{
	int j;
	int i;

	i = NUM_SIZE - 1;
	j = data->precision - 1;
	while (j >= 0) //дробная часть
	{
		s[--k] = (big_num2[j] == -1) ? '0' : big_num2[j] + '0';
		j--;
	}
	if (data->precision != 0 || (data->precision == 0 && (data->flags >> TO_SHARP) % 2))
		s[--k] = '.';
	while (big_num1[i] != -1 && i >= NUM_SIZE - 10) //целая часть
		s[--k] = big_num1[i--] + '0';
	i = k - 1;
	if ((data->flags >> TO_ZERO) % 2)
		while (k >= 0)
			s[--k] = '0';
	else
		while (k >= 0)
			s[--k] = ' ';
	k = ((data->flags >> TO_ZERO) % 2) ? 0 : i;
	if (big_num1[0] == 1)
		s[k] = '-';
	else if ((data->flags >> TO_PLUS) % 2)
		s[k] = '+';
	else if ((data->flags >> TO_SPACE) % 2 && big_num1[0] != 1)
		s[k] = ' ';
		//printf("\n%d\n", data->precision);
	ft_putstr_buf(s, data->buf, data);
	free(s);
}

void print_f(t_printf *data, char *big_num1, char *big_num2)
{
	int len; //кол-во цифр целой части
	int j;
	int k;
	char *s;

	k = 0;
	j = NUM_SIZE - 1;
	data->precision = (data->precision == -1) ? 6 : data->precision;
	if (big_num1[NUM_SIZE - 1] == -1)
		big_num1[NUM_SIZE - 1]++;
	rounding_off(big_num1, big_num2, data);
	while (big_num1[j] != -1)
		j--;
	len = NUM_SIZE - 1 - j;
	if ((data->flags >> TO_PLUS) % 2 || (data->flags >> TO_SPACE) % 2 || big_num1[0] == 1)
		len++;
	if (data->precision + len + 1 > data->width)
		k = data->precision + len + 1;
	else
		k = data->width;
	k = (data->precision == 0 && (data->flags >> TO_SHARP) % 2 == 0 && data->width == 0) ? k - 1 : k;
	s = ft_strnew(k); // посчитала длину
	if ((data->flags >> TO_MINUS) % 2)
		float_fillbegin(data, big_num1, big_num2, s, len);
	else
		float_fillend(data, big_num1, big_num2, s, k);
	j = 0;
}

int		put_data_f(t_printf *data, int *k)
{
	long double num;
	union u_number number;
	union code c;
	char	big_num1[NUM_SIZE]; //целая часть
	char	big_num2[NUM_SIZE]; //дробная часть
	int i;
	int e;

	ft_memset(big_num1, -1, NUM_SIZE);
	ft_memset(big_num2, -1, NUM_SIZE);

	if (data->size == L_UPPER_SIZE)
		num = (long double)va_arg(data->params, long double);
	else
		num = (double)va_arg(data->params, double);
	number.num = num;
	c.p = number.bits;
	if (number.bits.s == 1)
		big_num1[0] = 1;
	i = 0;
	e = number.bits.e - 16383;
	while (i < 64)
	{
		//printf("e-i: %d, %llu\n", (e - i), (number.bits.m >> (52 - i)) & 1);
		if (e - i < 0)
		{
			if ((number.bits.m >> (63 - i)) & 1)
				add_pow_five(big_num2, -(e - i));
		}
		else if (e - i >= 0)
		{
			if ((number.bits.m >> (63 - i)) & 1)
				add_pow_two(big_num1, e - i);
		}
		i++;
	}
	print_f(data, big_num1, big_num2);
	//free(big_num1);
	//free(big_num2);
	(*k)++;
	return (0);
}
