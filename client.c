/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:42:06 by scoskun           #+#    #+#             */
/*   Updated: 2022/03/15 13:18:19 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*data;
	int		i;

	if (argc < 3)
		return (1);
	i = 2;
	server_pid = ft_atoi(argv[1]);
	while (i < argc)
	{
		data = argv[i];
		while (*data)
			send_bits(*data++, server_pid);
		send_bits(' ', server_pid);
		i++;
	}
	send_bits('\0', server_pid);
	return (0);
}
