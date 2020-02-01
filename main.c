/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:58:37 by htrent            #+#    #+#             */
/*   Updated: 2020/02/01 14:07:20 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	int i_x;
	long l_x;
	long long ll_x;
	float	f_x;
	int ftp;
	int p;

	ll_x = 123123123123123123;
	l_x = 123123123123;
	i_x = 15;
	f_x = 123.123;
									ft_printf("    ft_printf: ");

	ftp = ft_printf("\'%#.10X\'\n", i_x);

									printf("ret_ft_printf: %d\n", ftp);
									printf("       printf: ");

	p = printf("\'%8.5X\'\n", i_x);

									printf("   ret_printf: %d\n", p);
	return 0;
}