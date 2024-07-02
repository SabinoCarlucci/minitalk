/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:31:25 by scarlucc          #+#    #+#             */
/*   Updated: 2024/05/23 11:03:34 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <signal.h>

void	ft_signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit_count;
	static int	char_received;

	(void) context;
	if (signal == SIGUSR1)
		char_received |= (0x01 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		ft_printf("%c", char_received);
		if (char_received == 0)
			ft_printf("\n");
		bit_count = 0;
		char_received = 0;
	}
	usleep(1);
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	act;

	(void) argv;
	if (argc != 1)
	{
		ft_printf("Error: this program requires no parameters");
		exit(1);
	}
	pid = getpid();
	ft_printf("%d", pid);
	ft_printf("\n");
	act.sa_sigaction = ft_signal_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
