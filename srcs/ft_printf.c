/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:53:39 by htrent            #+#    #+#             */
/*   Updated: 2020/02/24 15:31:13 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		*init_data(const char *format)
{
	t_printf	*data;
	int			i;

	i = 0;
	if (!(data = (t_printf *)malloc(sizeof(t_printf))))
		return (NULL);
	data->format = (char *)format;
	data->count_char = 0;
	data->flags = 32;
	data->size = 0;
	data->precision = -1;
	data->width = 0;
	data->count_buf = 0;
	ft_bzero(data->buf, BUFF_SIZE);
	return (data);
}

static void		reinit_data(t_printf *data)
{
	data->flags = 32;
	data->size = 0;
	data->precision = -1;
	data->width = 0;
}

int				put_data(t_printf *data, int *k)
{
	/*
	**printf("\'%c\', %d", data->format[*k], *k);
	**printf("\nflags:%d width:%d precision:%d size:%d char:\"%c\"\n", data->flags, data->width, data->precision, data->size, data->format[*k]);
	*/
	if (data->format[*k] && ft_strchr("csegfFpdiouUxXbBr", data->format[*k]) != NULL)
	{
		if (data->format[*k] == 'd' || data->format[*k] == 'i')
			put_data_di(data, k);
		else if (ft_strchr("ouUxXbB", data->format[*k]) != NULL)
			put_data_ouxb(data, k);
		else if (data->format[*k] == 'p')
			put_data_p(data, k);
		else if (data->format[*k] == 'c')
			put_data_c(data, k);
		else if (data->format[*k] == 's')
			put_data_s(data, k);
		else if (data->format[*k] == 'f')
			put_data_f(data, k);
		else if (data->format[*k] == 'r')
			put_data_r(data, k);
		return (0);
	}
	else if (data->format[*k] && ft_strchr("q \'\"", data->format[*k]) == NULL)
	{
		put_data_exception(data, k);
		return (0);
	}
	return (1);
}

int				manage_var(t_printf *data, int *k) ///add errors if return 1!!!
{
	int	i;

	if (data->format[*k])
	{
		if (!(ft_is_flag(data->format[*k]) == 0 && ft_is_size(data->format[*k]) == 0
		&& ft_isdigit(data->format[*k]) == 0 && ft_strchr("*._'", data->format[*k]) == NULL))
			while (data->format[*k] && ft_strchr("csegfFpdiouUxXbB%", data->format[*k]) == NULL)
			{
				i = 0;
				if (data->format[*k] == '%' && (*k)++)
					return (ft_put_percent(data));
				if (manage_flags(data, k) == 0)
					i = 1;
				if (manage_width(data, k) == 0)
					i = 1;
				if (manage_precision(data, k) == 0)
					i = 1;
				if (manage_size(data, k) == 0)
					i = 1;
				if (ft_is_flag(data->format[*k]) == 0 && ft_is_size(data->format[*k]) == 0 && ft_isdigit(data->format[*k]) == 0
				&& ft_strchr("*.%_'", data->format[*k]) == NULL)
					break ;
				if (i == 0 && data->format[*k])
					(*k)++;
			}
		if (put_data(data, k))
			return (1);
		return (0);
	}
	return (1);
}

int				ft_printf(const char *format, ...)
{
	t_printf	*data;
	int			i;

	if (!(data = init_data(format)))
		return (0);
	i = 0;
	va_start(data->params, format);
	while (data->format[i])
	{
		if (data->format[i] == '%')
		{
			i++;
			reinit_data(data);
			if (data->format[i] == '\0' || manage_var(data, &i))
				break ;
		}
		else if (data->format[i] == '{' && manage_color(data, &i))
			continue;
		else
		{
			data->count_char++;
			ft_putchar_buf(format[i], data->buf, data);
			i++;
		}
	}

	va_end(data->params);
	ft_putstr_pft(data->buf, data);
	i = data->count_char;
	free(data);
	return (i);
}
