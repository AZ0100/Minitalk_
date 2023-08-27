/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: az0100 <az0100@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:53:29 by az0100            #+#    #+#             */
/*   Updated: 2023/08/18 13:49:10 by az0100           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_bit	g_char_bits;

void	print_char(int bit, int*z)
{
	if (*z == 1)
		g_char_bits.b1 = bit;
	else if (*z == 2)
		g_char_bits.b2 = bit;
	else if (*z == 3)
		g_char_bits.b3 = bit;
	else if (*z == 4)
		g_char_bits.b4 = bit;
	else if (*z == 5)
		g_char_bits.b5 = bit;
	else if (*z == 6)
		g_char_bits.b6 = bit;
	else if (*z == 7)
		g_char_bits.b7 = bit;
	else if (*z == 8)
	{
		g_char_bits.b8 = bit;
		write(1, (unsigned char *)& g_char_bits, 1);
		*z = 0;
	}
}

void	sig_handler(int sig)
{
	static int	z;

	if (!z)
		z = 1;
	if (sig == SIGUSR1)
	{
		print_char(0, &z);
		z++;
	}
	else if (sig == SIGUSR2)
	{
		print_char(1, &z);
		z++;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int	pid;

	sa.sa_handler = &sig_handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "PID == ", 7);
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
