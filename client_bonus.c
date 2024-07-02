/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:31:23 by scarlucc          #+#    #+#             */
/*   Updated: 2024/05/23 10:56:02 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <signal.h>

void	signal_received(int signal, siginfo_t *info, void *context)
{
	(void) context;
	(void) info;
	if (signal == SIGUSR2)
		ft_printf("I got your message\n\n ---The Server");
}

void	send_char(int pid, char character)
{
	int	bit_count;

	bit_count = 0;
	while (bit_count < 8)
	{
		if (character & (0x01 << bit_count))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pause();
		usleep(1);
		bit_count++;
	}
}

void	check_input(int argc, char **argv)
{
	int	count;

	if (argc != 3)
	{
		ft_printf("Error\n\n");
		ft_printf("call this program with %s <pid> <message>", argv[0]);
		exit(1);
	}
	count = 0;
	while (argv[1][count])
	{
		if (ft_isdigit(argv[1][count]))
			count++;
		else
		{
			ft_printf("Error\n\n");
			ft_printf("call this program with %s <pid> <message>", argv[0]);
			exit(1);
		}
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	int					count;
	char				*message;
	struct sigaction	act;

	check_input(argc, argv);
	pid = ft_atoi(argv[1]);
	act.sa_sigaction = signal_received;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	count = 0;
	message = argv[2];
	while (message[count])
	{
		send_char(pid, message[count]);
		count++;
	}
	send_char(pid, '\0');
	return (0);
}
