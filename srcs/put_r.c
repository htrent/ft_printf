/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:22:11 by htrent            #+#    #+#             */
/*   Updated: 2020/02/14 16:34:45 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			count_nonprint(char *s, int *a, int *b)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] >= 0 && s[i] <= 31) || s[i] == 127)
			count++;
		i++;
	}
	*a = 0;
	*b = 0;
	return (count + 2 + i);
}

static void			paste_nonprint(char *s, char c, int *j)
{
	*s = '^';
	if (c == 0)
		*(s + 1) = '@';
	if (c > 0 && c <= 26)
		*(s + 1) = 'A' + c - 1;
	if (c == 27)
		*(s + 1) = '[';
	if (c == 28)
		*(s + 1) = '\\';
	if (c == 29)
		*(s + 1) = ']';
	if (c == 30)
		*(s + 1) = '^';
	if (c == 31)
		*(s + 1) = '_';
	if (c == 127)
		*(s + 1) = '?';
	(*j)++;
}

int					put_data_r(t_printf *data, int *k)
{
	char	*s;
	char	*buf;
	int		i;
	int		j;
	int		count;

	s = (char *)va_arg(data->params, char *);
	count = count_nonprint(s, &i, &j);
	buf = ft_strnew(count);
	while (s[i])
	{
		if ((s[i] >= 0 && s[i] <= 31) || s[i] == 127)
			paste_nonprint(buf + j, s[i], &j);
		else
			buf[j] = s[i];
		j++;
		i++;
	}
	buf[j++] = '^';
	buf[j] = '@';
	data->count_char += ft_strlen(s);
	ft_putstr_buf(buf, data->buf, data);
	(*k)++;
	return (0);
}
