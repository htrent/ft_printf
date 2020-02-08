/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_buf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:54:05 by htrent            #+#    #+#             */
/*   Updated: 2020/02/08 18:00:26 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_buf(char c, char buf[BUFF_SIZE], t_printf *data)
{
	int i;

	i = 0;
	while (i < data->count_buf && i < BUFF_SIZE - 1)
		i++;
	if (i == BUFF_SIZE - 1)
	{
		ft_putstr_pft(buf, data);
		ft_bzero(buf, BUFF_SIZE);
		i = 0;
	}
	data->count_buf++;
	buf[i] = c;
}
