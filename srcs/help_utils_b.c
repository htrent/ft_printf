/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_utils_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:07:45 by htrent            #+#    #+#             */
/*   Updated: 2020/02/09 20:07:45 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_sharp_b(t_printf *data, char *str, int *i)
{
	if ((data->flags >> TO_SHARP) % 2)
	{
		str[(*i)++] = '0';
		str[(*i)++] = 'b';
	}
}
