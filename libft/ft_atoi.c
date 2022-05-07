/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:31:56 by vtheobal          #+#    #+#             */
/*   Updated: 2021/06/02 16:39:48 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_error (unsigned long ret, unsigned long max, int negativ)
{
	if (ret > max && negativ == 1)
		return (-1);
	else if (ret > max && negativ == -1)
		return (0);
	return ((long)ret * negativ);
}

int	ft_atoi (const char *str)
{
	int				i;
	int				negativ;
	unsigned long	ret;
	unsigned long	max;

	i = 0;
	negativ = 1;
	ret = 0;
	max = 9223372036854775807;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') || \
	(str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			negativ = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret *= 10;
		ret += (str[i++] - '0');
	}
	return (ft_error(ret, max, negativ));
}
