/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschweit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:29:14 by bschweit          #+#    #+#             */
/*   Updated: 2022/07/05 11:21:30 by bschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

void	send_char(char a, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (a & (128 >> i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (i < ft_strlen(argv[2]))
		{
			send_char(argv[2][i], pid);
			i++;
		}
		send_char('\n', pid);
	}
	else
		printf("Usage : ./client [PID] [Chaine de caractere]\n");
	return (0);
}	
