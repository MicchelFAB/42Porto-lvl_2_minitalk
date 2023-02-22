/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:28:42 by mamaral-          #+#    #+#             */
/*   Updated: 2023/02/22 16:08:07 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_char(int pid, char c)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if (c & (1 << j))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		j++;
	}
}

void	ft_send(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_send_char(pid, str[i]);
		i++;
	}
	ft_send_char(pid, '\n');
}

void	server_signal(int ping)
{
	if (ping == SIGUSR1)
		ft_putstr_fd("\n ✅ MESSAGE RECEIVED ✅ \n\n", 1);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_handler = &server_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc != 3)
	{
		ft_putstr_fd("Error: Wrong number of arguments (2 \
		needed)\n Example: '12345' 'Hello :)'\n", 2);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		ft_putstr_fd("Error: Invalid PID\n", 2);
	else
	{
		ft_send(pid, argv[2]);
		ft_putstr_fd("Message sent!\n", 1);
	}
	return (0);
}
