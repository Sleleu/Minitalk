/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:05:56 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/23 00:02:23 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_struct	g_data;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_charjoin(char *s1, char s2)
{
	int		size;
	int		i;
	char	*tab;

	i = 0;
	size = (ft_strlen(s1) + 1);
	tab = malloc(sizeof(char) * (size + 1));
	if (tab == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	if (s2)
		tab[i] = s2;
	tab[size] = '\0';
	free(s1);
	return (tab);
}
void	ft_handler(int signum, siginfo_t *c_pid, void *tmp)
{
	static int i = 0;

	(void)tmp;
	g_data.client_pid = c_pid->si_pid;
	if (signum == SIGUSR1)
	{
		g_data.octet <<= 1;
		g_data.octet |= 1;
	}
	else
		g_data.octet <<= 1;
	i++;
	if (i == 8)
	{
		g_data.message = ft_charjoin(g_data.message, g_data.octet);
		if (!g_data.octet)
		{
			ft_printf("%s\n", g_data.message);
			free(g_data.message);
			g_data.message = NULL;
			kill(g_data.client_pid, SIGUSR1);
			usleep(100);
		}
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t	pid;

	pid = getpid();
	ft_printf(GREEN"🐸 Welcome to minitalk ! 🐸\n"END);
	ft_printf(CYAN"🌈 Current PID of the server : "END);
	ft_printf(YELLOW "%d\n"END, pid);
	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO;
	g_data.message = NULL;
	while (42)
	{
		if (sigaction(SIGUSR1, &sa, NULL) == -1
			|| sigaction(SIGUSR2, &sa, NULL) == -1)
			{
					ft_printf(RED"❌ Sigaction Error !❌\n"END);
					exit(EXIT_FAILURE);
			}
	}
		pause();
	return (0);
}