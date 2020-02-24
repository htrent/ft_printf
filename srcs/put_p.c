/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:54:07 by htrent            #+#    #+#             */
/*   Updated: 2020/02/24 14:33:24 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		add_p(char *str, int *i)
{
	str[(*i)++] = '0';
	str[(*i)++] = 'x';
}

int				init_p(t_printf *data, char *s, int *n, int *digits)
{
	int max;

	*digits = ft_strlen(s);
	*n = (*digits > data->precision) ? (*digits + 2) : (data->precision + 2);
	max = (*n > data->width) ? *n : data->width;
	data->count_char += max;
	return (max);
}

char			*init_data_p(t_printf *data, int *i)
{
	uintmax_t	num;
	char		*s;

	num = (unsigned long long)va_arg(data->params, unsigned long long);
	if (!(s = ft_utoa_base_p(num, 16, data)))
		return (NULL);
	*i = 0;
	return (s);
}

int				put_data_p_no_minus(t_printf *data, int *k)
{
	char	*s;
	char	*str;
	int		i;
	int		n;
	int		digits;

	if (!(s = init_data_p(data, &i)))
		return (1);
	if (!(str = ft_strnew(init_p(data, s, &n, &digits))) &&
	ft_memdel((void **)&s))
		return (1);
	fill_spaces(&(data->width), n, &i, str);
	add_p(str, &i);
	fill_zeros(&(data->precision), digits, &i, str);
	move_str(str, s, &i);
	(*k)++;
	ft_putstr_buf(str, data->buf, data);
	free(s);
	return (0);
}

int				put_data_p(t_printf *data, int *k)
{
	char	*s;
	char	*str;
	int		i;
	int		n;
	int		digits;

	if ((data->flags >> TO_MINUS) % 2 == 0)
		return (put_data_p_no_minus(data, k));
	s = init_data_p(data, &i);
	str = ft_strnew(init_p(data, s, &n, &digits));
	add_p(str, &i);
	move_str(str, s, &i);
	fill_zeros(&(data->precision), digits, &i, str);
	fill_spaces(&(data->width), n, &i, str);
	(*k)++;
	ft_putstr_buf(str, data->buf, data);
	free(s);
	return (0);
}
