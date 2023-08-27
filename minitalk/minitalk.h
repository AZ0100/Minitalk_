/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: az0100 <az0100@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:53:22 by az0100            #+#    #+#             */
/*   Updated: 2023/08/18 13:55:44 by az0100           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct t_bit
{
	int	b1:1;
	int	b2:1;
	int	b3:1;
	int	b4:1;
	int	b5:1;
	int	b6:1;
	int	b7:1;
	int	b8:1;
}	t_bit;

void	ft_putchar(char a);
void	ft_putstr(char *str);
void	ft_putnbr(int z);
void	sig_handler(int sig);
int	ft_atoi(const char *nptr);
void	char_to_bin(char c, int pid);
void	print_char(int bit, int*z);
void	send_sig(int pid, int val);

#endif
