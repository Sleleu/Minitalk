/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:05:56 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/22 02:39:56 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signum)
{
	static int i = 0;
	char 	*receive = NULL;
	char	octet[8];

	if (i == 7)
	{
		ft_printf("Octet : %s", octet);
		receive = ft_strjoin(receive, octet);
		ft_printf("receive : %s", receive);
		//ft_bzero(octet, 8);
		i = 0;
	}

	if (signum == SIGUSR1)
			octet[i] = '1';
	else
	{
		octet[i] = '0';
		//usleep(100);
		//i++;
	}
	i++;
	/*else
	{
		if (signum == SIGUSR1)
			ft_printf("1");
		else
			ft_printf("0");
		usleep(100);
	}*/
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