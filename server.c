/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:05:56 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/21 01:06:18 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf/ft_printf.h"

void	handler(int signum)
{
	int	nb_bytes;

	nb_bytes = 0;
	if (signum == SIGUSR1)
	{
		ft_printf("a");
	}
	else
		ft_printf("2");
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	struct sigaction	sa;
	pid_t	pid;
	
	sa.sa_handler = handler;
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	while (42)
	{
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		if (sigaction(SIGUSR2, &sa, NULL)== -1)
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		pause();
	}
	return (0);
}