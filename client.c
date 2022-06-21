/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:05:57 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/22 00:45:11 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_send_signal(int pid, char *argv)
{
	int	i;
	int j;

	i = 0;
	while (argv[i])
	{
		j = 7;
		
		while (j >= 0)
		{
			if (argv[i] & 1 << j)
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
			j--;
		}		
		i++;
	}
}

void	ft_send_len(int pid, char *argv)
{
	char *str;
	int	len;
	int i;
	int j;

	i = 10;
	len = ft_strlen(argv);
	str = ft_itoa(len);
//	ft_send_signal(pid, str);

	while (i >= 0)
	{
		j = 7;
		while (j >= 0)
		{
			if (str && *(str+i) && str[i] & 1 << j)
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
			j--;
		}
		i--;
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	pid_t	pid;

	pid = ft_atoi(argv[1]);
ft_printf ("\n IN CLIENT LEN = \n");
	ft_send_len(pid, argv[2]);
ft_printf ("\n IN CLIENT SIGNAL = \n");
	ft_send_signal(pid, argv[2]);
	return (0);
}