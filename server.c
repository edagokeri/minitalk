/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egokeri <egokeri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:13:54 by egokeri           #+#    #+#             */
/*   Updated: 2023/04/19 14:52:46 by egokeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sender(int sig)
{
	static int	i = 7;
	static char	c = 0;

	c += sig << i;
	if (i == 0)
	{
		i = 7;
		write(1, &c, 1);
		c = 0;
	}
	else
		i--;
}

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		sender(1);
	if (signal == SIGUSR2)
		sender(0);
}

int	main(void)
{
	int	pid;

	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	pid = getpid();
	ft_printf("%d\n", pid);
	while (1)
		pause();
}
