/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:58:37 by htrent            #+#    #+#             */
/*   Updated: 2020/02/01 13:28:58 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_to_upper(char *str)
{
	int i;
	char c;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		c = ft_toupper(str[i]);
		str[i] = c;
		i++;
	}
	return (str);
}
