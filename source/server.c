/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:25:16 by mamaral-          #+#    #+#             */
/*   Updated: 2023/03/01 16:22:48 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

void	ft_handler(int sig)
{
	static char	c;
	static int	i;

	if (sig == SIGUSR1)
		c += (1 << i);
	i++;
	if (i == 8)
	{
		ft_putchar_fd(c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = &ft_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
	return (0);
}
