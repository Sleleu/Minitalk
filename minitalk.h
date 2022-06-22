/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <sleleu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:34:13 by sleleu            #+#    #+#             */
/*   Updated: 2022/06/22 15:40:18 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	_MINITALK_H_
# define _MINITALK_H_

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
#include "ft_printf/ft_printf.h"

typedef struct s_struct
{
	int	byte;
	char	octet;
	char	*message;
}		t_struct;

/* utils */
void	*ft_memset(void *b, int c, size_t len);
int	ft_atoi(char *str);
char	*ft_itoa(int n);
int	ft_strlen(char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char *s1, char *s2);

#endif
