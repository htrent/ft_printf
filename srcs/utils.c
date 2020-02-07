/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:58:37 by htrent            #+#    #+#             */
/*   Updated: 2020/02/07 18:59:02 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fill_zeros(int *a, int b, int *i, char *s)
{
	while (*a > b)
	{
		s[*i] = '0';
		(*a)--;
		(*i)++;
	}
}

intmax_t max(intmax_t a, intmax_t b)
{
	if (a > b)
		return (a);
	return (b);
}

intmax_t	ft_pow_10(int n)
{
	int i;
	int64_t num;

	num = 1;
	i = 0;
	while (i < n)
	{
		num *= 10;
		i++;
	}
	return (num);
}

uintmax_t	ft_pow_10_u(int n)
{
	int i;
	int64_t num;

	num = 1;
	i = 0;
	while (i < n)
	{
		num *= 10;
		i++;
	}
	return (num);
}

int 	ft_is_flag(char c)
{
	if (ft_strchr("#0+- ", c) != NULL && c != '\0')
		return (1);
	return (0);
}

int 	ft_is_size(char c)
{
	if ((c == 'l') || (*(&c + 1) && c == 'l' && *(&c + 1) == 'l') || (c == 'h') || (*(&c + 1) && c == 'h' && *(&c + 1) == 'h') || (c == 'L') || (c == 'j') || (c == 'z'))
		return (1);
	return (0);
}

void	ft_putchar_buf(char c, char buf[BUFF_SIZE])
{
	int i;

	i = 0;
	while (buf[i] != '\0' && i < BUFF_SIZE)
		i++;
	if (i == BUFF_SIZE)
	{
		ft_putstr(buf);
		ft_bzero(buf, BUFF_SIZE);
		i = 0;
	}
	buf[i] = c;
}

void	ft_putstr_buf(char *str, char buf[BUFF_SIZE])
{
	int i;

	i = 0;
	while (buf[i] != '\0' && i < BUFF_SIZE)
		i++;
	while (*str)
	{
		while (i < BUFF_SIZE && *str)
		{
			buf[i] = *str;
			str++;
			i++;
		}
		if (i == BUFF_SIZE)
		{
			ft_putstr(buf);
			ft_bzero(buf, BUFF_SIZE);
			i = 0;
		}
	}
}

