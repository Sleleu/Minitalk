/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:05:56 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/21 22:56:29 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signum)
{
	int i = 0;
	
	if (signum == SIGUSR1)
		ft_printf("1");
	else
		ft_printf("0");
	usleep(100);
	i++;
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
		printf ("test");
		pause();
	}
	return (0);
}