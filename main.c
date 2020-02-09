/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:58:37 by htrent            #+#    #+#             */
/*   Updated: 2020/02/09 21:47:23 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>



/*
0	нормальный режим
1	жирный
4	подчеркнутый
5	мигающий
7	инвертированные цвета
8	невидимый
цвет текста
30	черный
31	красный
32	зеленый
33	желтый
34	синий
35	пурпурный
36	голубой
37	белый
цвет фона
40	черный
41	красный
42	зеленый
43	желтый
44	синий
45	пурпурный
46	голубой
47	белый
 */
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
	char *s;

	s = NULL;

	ll_p = &ll_x;
	i_p = &i_x;
	ll_x = 123123123123123123;
	l_x = 123123123123;
	i_x = 100;
	f_x = 123.123;
	u_x = -42;
	Lf_x = 1.123123123123123123123123123123123123123123;
																							ft_printf("    ft_printf: ");
	ftp = ft_printf("\"\x1b[31mTest\x1b[0m\"");														printf("\nret_ft_printf: %d\n", ftp - 2);printf("       printf: ");
	p   =    printf("\"\x1b[8mTest\x1b[0m\"");														printf("\n   ret_printf: %d\n", p - 2);
	return 0;
}