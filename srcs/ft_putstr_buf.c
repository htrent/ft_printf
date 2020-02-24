/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:55:17 by htrent            #+#    #+#             */
/*   Updated: 2020/02/24 15:48:38 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_pft(char buf[BUFF_SIZE], t_printf *data)
{
	int i;

	i = 0;
	write(1, buf, data->count_buf);
	data->count_buf = 0;
}

void	ft_putstr_buf(char *str, char buf[BUFF_SIZE], t_printf *data)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < data->count_buf)
		i++;
	while (str[j])
	{
		while (i < BUFF_SIZE && str[j])
		{
			buf[i] = str[j];
			j++;
			i++;
			data->count_buf++;
		}
		if (i == BUFF_SIZE)
		{
			ft_putstr_pft(buf, data);
			ft_bzero(buf, BUFF_SIZE);
			i = 0;
		}
	}
	free(str);
}
