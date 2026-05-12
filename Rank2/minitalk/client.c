/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 03:59:58 by tthwe             #+#    #+#             */
/*   Updated: 2026/05/12 21:06:03 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_char(int pid, unsigned char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill (pid, SIGUSR2);
		else
			kill (pid, SIGUSR1);
		usleep(500);
		bit --;
	}
}

int	main(int ac, char *av[])
{
	int		server_pid;
	char	*msg;

	if (ac != 3)
	{
		ft_putstr_fd ("Correct Usage: ./client [PID] [message] \n", 1);
		return (1);
	}
	server_pid = ft_atoi(av[1]);
	if (server_pid <= 0)
	{
		ft_putstr_fd("ERROR: Invalid PID\n", 2);
		return (1);
	}
	msg = av[2];
	while (*msg)
	{
		send_char(server_pid, *msg);
		msg++;
	}
	send_char(server_pid, '\0' );
	return (0);
}
