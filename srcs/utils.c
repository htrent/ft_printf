/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:58:37 by htrent            #+#    #+#             */
/*   Updated: 2020/02/08 15:59:19 by htrent           ###   ########.fr       */
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

void		fill_spaces(int *a, int b, int *i, char *s)
{
	while (*a > b)
	{
		s[(*i)++] = ' ';
		(*a)--;
	}
}

intmax_t	max(intmax_t a, intmax_t b)
{
	if (a > b)
		return (a);
	return (b);
}

int			ft_is_flag(char c)
{
	if (ft_strchr("#0+- ", c) != NULL && c != '\0')
		return (1);
	return (0);
}

int			ft_is_size(char c)
{
	if ((c == 'l') || (c == 'l' && *(&c + 1) == 'l')
	|| (c == 'h') || (c == 'h' && *(&c + 1) == 'h')
	|| (c == 'L') || (c == 'j') || (c == 'z'))
		return (1);
	return (0);
}
