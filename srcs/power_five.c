/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 18:00:45 by ffood             #+#    #+#             */
/*   Updated: 2020/02/24 15:25:08 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		pow_five_calc(char *big_five, int power, int j)
{
	int		prev_digit;
	int		digit;

	big_five[NUM_SIZE - 1] = 1;
	while (power > 0)
	{
		j = NUM_SIZE - 1;
		prev_digit = 0;
		while (big_five[j] != -1)
		{
			digit = (big_five[j] * 5) / 10;
			big_five[j] = (big_five[j] * 5) % 10;
			if (prev_digit)
			{
				if (big_five[j] + prev_digit > 9)
					digit += (big_five[j] + prev_digit) / 10;
				big_five[j] = (big_five[j] + prev_digit) % 10;
			}
			prev_digit = digit;
			j--;
		}
		if (prev_digit)
			big_five[j] = prev_digit;
		power--;
	}
}

static void		pow_five_sum(char *big_five, char *big_num, int i, int j)
{
	int flag;
	int prev_flag;

	prev_flag = 0;
	while (big_five[j] != -1)
	{
		if (big_num[i] == -1)
			big_num[i] = 0;
		flag = ((big_num[i] + big_five[j]) > 9) ? 1 : 0;
		big_num[i] = (big_num[i] + big_five[j--]) % 10;
		if (prev_flag)
		{
			flag = (big_num[i] + 1 > 9) ? 1 : flag;
			big_num[i] = (big_num[i] + 1) % 10;
		}
		prev_flag = flag;
		flag = 0;
		i--;
	}
	while (prev_flag)
	{
		prev_flag = (big_num[i] + 1 > 9) ? 1 : 0;
		big_num[i] = (big_num[i] + 1) % 10;
		i--;
	}
}

static int		count_start(char *big_five, char *big_num, int power)
{
	int i;
	int j;

	i = 0;
	while (big_five[i] == -1)
		i++;
	i = NUM_SIZE - i;
	j = -1;
	while (++j < i)
		big_num[j] = (big_num[j] == -1) ? 0 : big_num[j];
	j = NUM_SIZE - 1;
	i = power - 1;
	return (i);
}

void			add_pow_five(char big_num[NUM_SIZE], int power)
{
	char					big_five[NUM_SIZE];
	int						i;
	int						j;

	ft_memset(big_five, -1, NUM_SIZE);
	pow_five_calc(big_five, power, 0);
	i = count_start(big_five, big_num, power);
	j = NUM_SIZE - 1;
	pow_five_sum(big_five, big_num, i, j);
}
