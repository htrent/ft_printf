/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:58:37 by htrent            #+#    #+#             */
/*   Updated: 2020/02/24 17:15:21 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

/*
**----СВОЙСТВА----------------ЦВЕТ ТЕКСТА-------------ЦВЕТ ФОНА----
**0	нормальный режим        30	черный              40	черный
**1	жирный                  31	красный             41	красный
**4	подчеркнутый            32	зеленый             42	зеленый
**5	мигающий                33	желтый              43	желтый
**7	инвертированные цвета   34	синий               44	синий
**8	невидимый               35	пурпурный           45	пурпурный
**                            36	голубой             46	голубой
**                            37	белый               47	белый
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
	ftp = ft_printf("{re}%d %d %d{eo}");
														printf("\nret_ft_printf: %d\n", ftp);printf("       printf: ");
	p = printf("%d %d %d");													printf("\n   ret_printf: %d\n", p);
	return 0;
}