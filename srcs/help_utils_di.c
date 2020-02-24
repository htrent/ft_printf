/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_utils_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:38:38 by htrent            #+#    #+#             */
/*   Updated: 2020/02/08 16:59:16 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			edge_di(t_printf *data, int *k)
{
	ft_putstr_buf(ft_strdup("-9223372036854775808"), data->buf, data);
	data->count_char += 20;
	(*k)++;
	return (0);
}

int			first_init_begin(t_printf *data, intmax_t *num, int *i, char *s)
{
	int sign;

	sign = 1;
	if ((data->flags >> TO_SPACE) % 2 && (*num) >= 0 && (*i = 1))
		s[0] = ' ';
	if ((data->flags >> TO_PLUS) % 2 && (*num) >= 0 && (*i = 1))
		s[0] = '+';
	if (*num < 0 && (*i = 1) && ((*num) *= -1))
	{
		sign = -1;
		s[0] = '-';
	}
	return (sign);
}

void		ft_itoa_di(char *s, int digits, intmax_t num, int *i)
{
	while (digits > 0)
	{
		s[(*i)++] = (digits == 19) ? (num / ft_pow_10(digits - 1) + '0')
				: ((num % ft_pow_10(digits)) / ft_pow_10(digits - 1) + '0');
		digits--;
	}
}

void		first_init_end(t_printf *data, intmax_t *num, int *i, char *s)
{
	if ((data->flags >> TO_SPACE) % 2 && *num >= 0)
		s[*i] = ' ';
	if ((data->flags >> TO_PLUS) % 2 && *num >= 0)
		s[*i] = '+';
	if (*num < 0)
		s[*i] = '-';
	if ((data->flags >> TO_PLUS) % 2 ||
	(data->flags >> TO_SPACE) % 2 || (*num < 0))
		(*i)++;
	if (*num < 0)
		*num *= -1;
}
