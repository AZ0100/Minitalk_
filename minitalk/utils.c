/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: az0100 <az0100@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:52:50 by az0100            #+#    #+#             */
/*   Updated: 2023/08/18 13:53:32 by az0100           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	is_negative(int a)
{
	if (a == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	unsigned long long	a;
	int			z;
	int			sign;

	a = 0;
	z = 0;
	sign = 1;
	while ((nptr[z] >= 9 && nptr[z] <= 13) || (nptr[z] == ' '))
	{
		z++;
	}
	if (nptr[z] == '-' || nptr[z] == '+')
	{
		sign = 1 - 2 *(nptr[z++] == '-');
	}
	while (nptr[z] >= '0' && nptr[z] <= '9')
	{
		a = a * 10 + (nptr[z] - '0');
		if (a > 9223372036854775807)
			return (is_negative(sign));
		z++;
	}
	return (a * sign);
}

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_putnbr(int z)
{
	if (z == -2147483648)
		write(1, "-2147483648", 11);
	else if (z < 0)
	{
		ft_putchar ('-');
		ft_putnbr(-z);
	}
	else if (z > 9)
	{
		ft_putnbr(z / 10);
		ft_putnbr(z % 10);
	}
	else if (z >= 0 && z <= 9)
		ft_putchar(z + '0');
}
