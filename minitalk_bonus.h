/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:53:06 by scoskun           #+#    #+#             */
/*   Updated: 2022/03/03 19:13:31 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

void	take_bit(int sig, siginfo_t *info, void *cnt);
void	send_bits(unsigned char c, pid_t pid);
int		ft_atoi(const char *str);
int		ft_printf(const char *s, ...);
void	received(int signo);
void	ctrlc(int sig);
void	kill_checker(pid_t si_pid, int sign);
#endif
