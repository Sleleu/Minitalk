/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:05:57 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/22 15:12:08 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_send_signal(int pid, char octet)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
			if (octet & 1 << i)
			{
				ft_printf("1");
				kill(pid, SIGUSR1);
			}
			else
			{
				ft_printf("0");
				kill(pid, SIGUSR2);
			}
			usleep(100);
			i--;
	}		
}

int	main(int argc, char **argv)
{
	(void)argc;
	pid_t	pid;
	int i = 0;

	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		ft_send_signal(pid, argv[2][i]);
		i++;
	}
	return (0);
}