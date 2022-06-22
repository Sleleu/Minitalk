/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:05:57 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/23 00:04:04 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned int	nb_bytes = 0;

int	ft_atoi(char *str)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

void ft_client_error(int i)
{
	if (i == 1)
		ft_printf(RED"❌ ERROR : Invalid argument ! ❌\n"END);
	else if (i == 2)
		ft_printf(RED"❌ Sigaction Error ! ❌\n"END);
	else if (i == 3)
		ft_printf(RED"❌ ERROR : Bad PID ❌\n"END);
	exit(EXIT_FAILURE);
}

void ft_end_signal(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf(GREEN"⚡ %d bytes "END, nb_bytes);
		ft_printf(YELLOW"successfully sent ! ⚡\n"END);
	}
}

void ft_send_signal(int pid, char octet)
{
	int	i;
	if (pid <= 0)
		ft_client_error(3);
	i = 7;
	while (i >= 0)
	{
			if (octet & 1 << i)
			{
				if (kill(pid, SIGUSR1) != 0)
					ft_client_error(3);
			}
			else
			{
				if (kill(pid, SIGUSR2) != 0)
					ft_client_error(3);
			}
			usleep(100);
			i--;
	}		
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		ft_client_error(1);
	struct sigaction sa;
	sa.sa_handler = ft_end_signal;
	pid_t	pid;
	int i = 0;

	pid = ft_atoi(argv[1]);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_client_error(2);
	while (argv[2][i])
	{
		ft_send_signal(pid, argv[2][i]);
		i++;
		nb_bytes++;
	}
	ft_send_signal(pid, '\0');
	return (0);
}