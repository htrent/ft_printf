/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:58:37 by htrent            #+#    #+#             */
/*   Updated: 2020/02/07 13:43:30 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int main() {
	int i_x;
	long l_x;
	long long ll_x;
	float	f_x;
	long double Lf_x;
	unsigned long u_x;
	int ftp;
	int p;
	long long *ll_p;
	int *i_p;

	ll_p = &ll_x;
	i_p = &i_x;
	ll_x = 123123123123123123;
	l_x = 123123123123;
	i_x = 100;
	f_x = 123.123;
	u_x = -42;
	Lf_x = 1.123123123123123123123123123123123123123123;
																							ft_printf("    ft_printf: ");
	ftp = ft_printf("\"%lf\"", (double)Lf_x);														printf("\nret_ft_printf: %d\n", ftp - 2);printf("       printf: ");
	p   =    printf("\"%.100Lf\"", Lf_x);														printf("\n   ret_printf: %d\n", p - 2);
	return 0;
}