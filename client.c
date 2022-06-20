/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:05:57 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/21 01:06:17 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	(void)argc;
	pid_t	pid;

	pid = atoi(argv[1]);
	if (argv[2][0] == '1')
		kill(pid, SIGUSR1);
	else if (argv[2][0] == '0')
		kill(pid, SIGUSR2);
	return (0);
}