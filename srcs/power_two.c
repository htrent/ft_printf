/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:57:11 by ffood             #+#    #+#             */
/*   Updated: 2020/02/24 14:19:35 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pow_two_under_64(int power, char *big_num)
{
	int						flag;
	int						j;
	unsigned long long int	number;

	j = NUM_SIZE - 1;
	flag = 0;
	number = (unsigned long long)1 << power;
	while (number > 0)
	{
		if (big_num[j] == -1)
			big_num[j] = 0;
		if (flag)
			big_num[j]++;
		flag = ((big_num[j] + (number % 10)) > 9) ? 1 : 0;
		big_num[j] = (big_num[j] + number % 10) % 10;
		number /= 10;
		j--;
	}
	while (flag)
	{
		big_num[j] = (big_num[j] == -1) ? 0 : big_num[j];
		flag = (big_num[j] + 1 > 9) ? 1 : 0;
		big_num[j] = (big_num[j] + 1) % 10;
		j--;
	}
}

static void	array_sum(char *big_two, char *big_num, int j)
{
	int	flag;
	int	prev_flag;

	prev_flag = 0;
	flag = 0;
	while (big_two[j] != -1)
	{
		big_num[j] = (big_num[j] == -1) ? 0 : big_num[j];
		flag = ((big_num[j] + big_two[j]) > 9) ? 1 : flag;
		big_num[j] = (big_num[j] + big_two[j]) % 10;
		flag = ((prev_flag) && (big_num[j] + 1 > 9)) ? 1 : flag;
		big_num[j] = (prev_flag) ? (big_num[j] + 1) % 10 : big_num[j];
		prev_flag = flag;
		flag = 0;
		j--;
	}
	while (prev_flag)
	{
		big_num[j] = (big_num[j] == -1) ? 0 : big_num[j];
		prev_flag = (big_num[j] + 1 > 9) ? 1 : 0;
		big_num[j] = (big_num[j] + 1) % 10;
		j--;
	}
}

static void	array_power(int power, char *big_two, int i)
{
	int	flag;
	int	prev_flag;
	int j;

	while (i < power - 63)
	{
		j = NUM_SIZE - 1;
		prev_flag = 0;
		flag = 0;
		while (big_two[j] != -1)
		{
			if (big_two[j] * 2 > 9)
				flag = 1;
			big_two[j] = (big_two[j] * 2) % 10;
			if (prev_flag)
				big_two[j]++;
			prev_flag = flag;
			flag = 0;
			j--;
		}
		if (prev_flag)
			big_two[j] = 1;
		i++;
	}
}

static void	pow_two_over_64(char *big_num, char *big_two, int power)
{
	int						i;
	int						j;
	unsigned long long int	number;

	i = 0;
	j = NUM_SIZE - 1;
	number = (unsigned long long)1 << 63;
	while (number > 0)
	{
		big_two[j--] = number % 10;
		number = number / 10;
	}
	j = NUM_SIZE - 1;
	array_power(power, big_two, i);
	array_sum(big_two, big_num, j);
}

void		add_pow_two(char big_num[NUM_SIZE], int power)
{
	char	big_two[NUM_SIZE];
	int		i;
	int		j;
	int		flag;
	int		prev_flag;

	j = NUM_SIZE - 1;
	i = 0;
	flag = 0;
	prev_flag = 0;
	ft_memset(big_two, -1, NUM_SIZE);
	if (power < 64)
		pow_two_under_64(power, big_num);
	else
		pow_two_over_64(big_num, big_two, power);
}
