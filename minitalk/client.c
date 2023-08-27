/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: az0100 <az0100@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:53:07 by az0100            #+#    #+#             */
/*   Updated: 2023/08/16 12:16:41 by az0100           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sig(int pid, int val)
{
	usleep(250);
	if (val)
	{
		kill(pid, SIGUSR2);
		return ;
	}
	kill(pid, SIGUSR1);
}

void	char_to_bin(char c, int pid)
{
	t_bit	bits;

	bits = *(t_bit *)&c;
	send_sig(pid, bits.b1);
	send_sig(pid, bits.b2);
	send_sig(pid, bits.b3);
	send_sig(pid, bits.b4);
	send_sig(pid, bits.b5);
	send_sig(pid, bits.b6);
	send_sig(pid, bits.b7);
	send_sig(pid, bits.b8);
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	z;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid == 0 || pid < 0)
		{
			write(1, "Error: Invalid pid\n", 19);
			return (1);
		}
		z = 0;
		while (argv[2][z])
		{
			char_to_bin(argv[2][z], pid);
			z++;
		}
	}
	else
	{
		write(1, "Usage: ./client PID 'Message'\n", 30);
		return (1);
	}
	return (0);
}
