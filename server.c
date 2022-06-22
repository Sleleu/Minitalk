/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:05:56 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/22 15:42:48 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_struct data;

void	ft_handler(int signum)
{
	static int i = 0;
	
		if (signum == SIGUSR2)
		{
			data.octet <<= 1;
			ft_printf("0");
		}
		else
		{
			data.octet <<= 1;
			data.octet |= 1;
			ft_printf("1");
		}
		i++;
		if (i == 8)
		{
			ft_printf("\nOctet : ");
			ft_putchar_fd(data.octet, 1);
			ft_printf("\n");
			i = 0;
		}
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	struct sigaction	sa;
	pid_t	pid;
	
	sa.sa_handler = ft_handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	while (42)
	{
		if (sigaction(SIGUSR1, &sa, NULL) == -1
			|| sigaction(SIGUSR2, &sa, NULL) == -1)
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		pause();
	}
	return (0);
}