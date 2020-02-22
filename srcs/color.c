/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:57:02 by htrent            #+#    #+#             */
/*   Updated: 2020/02/11 19:40:21 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_str(char *str1, char *str2, int k)
{
	int i;
	int j;

	i = k;
	j = 0;
	while ((str1[i] || str2[j]) && str1[i] == str2[j])
	{
		j++;
		i++;
	}
	if (str1[i] == '\0' && str2[j] != '\0')
		return (0);
	if (str2[j] == '\0')
		return (1);
	return (0);
}

int		text_colors(char *colors[], t_printf *data, int *k)
{
	int i;

	i = 0;
	while (*colors[i])
	{
		if (check_str(data->format, colors[i], *k))
		{
			ft_putstr_buf(ft_strdup("\033[3"), data->buf, data);
			ft_putchar_buf(i + '0', data->buf, data);
			ft_putchar_buf('m', data->buf, data);
			*k = *k + ft_strlen(colors[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int		bg_colors(char *colors_bg[], t_printf *data, int *k)
{
	int i;

	i = 0;
	while (*colors_bg[i])
	{
		if (check_str(data->format, colors_bg[i], *k))
		{
			ft_putstr_buf(ft_strdup("\033[4"), data->buf, data);
			ft_putchar_buf(i + '0', data->buf, data);
			ft_putchar_buf('m', data->buf, data);
			*k = *k + ft_strlen(colors_bg[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int		attr(char *attribute[], t_printf *data, int *k)
{
	int i;
	int j;

	i = 0;
	while (*attribute[i])
	{
		if (check_str(data->format, attribute[i], *k))
		{
			j = i;
			j = (i >= 3) ? j + 1 : j;
			j = (i >= 5) ? j + 1 : j;
			ft_putstr_buf(ft_strdup("\033["), data->buf, data);
			ft_putchar_buf(j + '0', data->buf, data);
			ft_putchar_buf('m', data->buf, data);
			*k = *k + ft_strlen(attribute[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int		manage_color(t_printf *data, int *k)
{
	static char *colors[] = {"{black}", "{red}", "{green}", "{yellow}",
						"{blue}", "{magenta}", "{cyan}", "{white}", "\0"};
	static char *colors_bg[] = {"{black_bg}", "{red_bg}", "{green_bg}",
							"{yellow_bg}", "{blue_bg}", "{magenta_bg}",
							"{cyan_bg}", "{white_bg}", "\0"};
	static char *attribute[] = {"{eoc}", "{bold}", "{light}", "{underline}",
							"{normal}", "{invert}", "{hidden}", "\0"};

	if (text_colors(colors, data, k) || bg_colors(colors_bg, data, k) ||
		attr(attribute, data, k))
		return (1);
	return (0);
}
