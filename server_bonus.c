/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:37:56 by scoskun           #+#    #+#             */
/*   Updated: 2022/03/15 13:50:50 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	kill_checker(pid_t si_pid, int sign)
{
	if (kill(si_pid, sign) == -1)
		ft_printf("Error!!\n");
}

void	ctrlc(int sig)
{
	(void)sig;
	ft_printf("\nProgram killed by 'SIGINT'");
	exit(1);
}

void	take_bit(int sig, siginfo_t *info, void *cnt)
{
	static int	r_number;
	static int	r_bit_count;

	(void)cnt;
	r_number <<= 1;
	if (sig == SIGUSR1)
		r_number |= 1;
	r_bit_count++;
	if (r_bit_count == 8)
	{
		ft_printf("%c", r_number);
		if (r_number == 0)
		{
			ft_printf("\nMessage came from this PID: %d\n", info->si_pid);
			kill_checker(info->si_pid, SIGUSR1);
		}
		r_number = 0;
		r_bit_count = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	test;
	int					pid;

	(void)argc;
	(void)argv;
	pid = getpid();
	ft_printf("Process ID is: %d\n", pid);
	test.sa_sigaction = take_bit;
	if ((sigaction(SIGUSR1, &test, NULL)) == -1)
		ft_printf("Sigaction error!!");
	if ((sigaction(SIGUSR2, &test, NULL)) == -1)
		ft_printf("Sigaction error!!");
	signal(SIGINT, ctrlc);
	while (1)
		continue ;
}
