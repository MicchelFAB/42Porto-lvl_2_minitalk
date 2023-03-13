/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:28:42 by mamaral-          #+#    #+#             */
/*   Updated: 2023/03/13 10:48:03 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk_bonus.h"

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
//	ft_send_char(pid, '\0');
}

void	server_signal(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd("\n\t📬 Mensagem Recebida com Sucesso 📬\n\n", 1);
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
		ft_putstr_fd("Erro:Numero de Argumentos Inv\
alido (2 argumentos apenas)\n Exemplo: '12345' \"olá, tudo bem?\"\n", 2);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		ft_putstr_fd("Erro:PID Invalido, tente novamente.\n", 2);
	else
	{
		ft_putstr_fd("\t📨 Mensagem Enviada 📨\n", 1);
		ft_send(pid, argv[2]);
	}
	return (0);
}
