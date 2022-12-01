/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschweit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:32:51 by bschweit          #+#    #+#             */
/*   Updated: 2022/07/05 11:21:07 by bschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

void	signal_handler(int signum)
{
	static unsigned char	buffer = 0;
	static int				counter = 128;
	static int				i = 8;

	if (signum == SIGUSR1)
	{
		buffer += counter;
		counter = counter / 2;
	}
	else if (signum == SIGUSR2)
		counter = counter / 2;
	i--;
	if (i <= 0 || counter < 1)
	{
		ft_printf("%c", buffer);
		i = 8;
		counter = 128;
		buffer = 0;
	}
}

int	main(void)
{
	ft_printf("PID : %d\n", getpid ());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
