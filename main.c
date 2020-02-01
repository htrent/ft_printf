/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:58:37 by htrent            #+#    #+#             */
/*   Updated: 2020/02/01 19:39:43 by htrent           ###   ########.fr       */
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
	unsigned u_x;

	ll_x = 9223372036854775807;
	l_x = 123123123123;
	i_x = -42;
	f_x = 123.123;
	u_x = 100;

																		ft_printf("    ft_printf: ");
	ftp = ft_printf("\'%u\'\n", i_x);									printf("ret_ft_printf: %d\n", ftp - 3);    printf("       printf: ");
	p   =    printf("\'%u\'\n", i_x);									printf("   ret_printf: %d\n", p - 3);
	return 0;
}
//3.2d