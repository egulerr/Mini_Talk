/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:54:51 by scoskun           #+#    #+#             */
/*   Updated: 2022/03/15 13:20:37 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ctrlc(int sig)
{
	(void)sig;
	ft_printf("\nProgram killed by 'CTRL + C'\n");
	exit (1);
}

void	take_bit(int sig, siginfo_t *info, void *cnt)
{
	static int	g_number;
	static int	g_bit_count;

	(void)cnt;
	(void)info;
	g_number <<= 1;
	if (sig == SIGUSR1)
		g_number |= 1;
	g_bit_count++;
	if (g_bit_count == 8)
	{
		ft_printf("%c", g_number);
		if (g_number == 0)
			ft_printf("\n");
		g_number = 0;
		g_bit_count = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	test;
	int					pid;

	(void)argv;
	(void)argc;
	pid = getpid();
	test.sa_sigaction = take_bit;
	if ((sigaction(SIGUSR1, &test, NULL)) == -1)
		ft_printf("sigaction error");
	if ((sigaction(SIGUSR2, &test, NULL)) == -1)
		ft_printf("sigaction error");
	signal(SIGINT, ctrlc);
	printf("Process ID: %d\n", pid);
	while (1)
		continue ;
}
