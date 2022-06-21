/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:34:13 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/21 22:39:19 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	_MINITALK_H_
# define _MINITALK_H_

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
#include "ft_printf/ft_printf.h"

/* utils */
void	*ft_memset(void *b, int c, size_t len);
int	ft_atoi(char *str);
char	*ft_itoa(int n);
int	ft_strlen(char *str);

#endif
