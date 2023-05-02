/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:53:53 by scoskun           #+#    #+#             */
/*   Updated: 2022/03/15 13:47:03 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	received(int signo)
{
	(void)signo;
	ft_printf("Message received by 'Server' \n");
}

void	send_bits(unsigned char c, pid_t pid)
{
	int	count;

	count = 7;
	while (count >= 0)
	{
		if ((c >> count) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("Error!!");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("Error exit!!");
				exit(1);
			}
		}
		count--;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	pid_t	serverpid;
	char	*data;
	int		i;

	if (ac < 3)
		return (1);
	i = 2;
	serverpid = ft_atoi(av[1]);
	signal(SIGUSR1, received);
	while (i < ac)
	{
		data = av[i];
		while (*data)
			send_bits(*data++, serverpid);
		send_bits(' ', serverpid);
		i++;
	}
	send_bits('\0', serverpid);
	return (0);
}
