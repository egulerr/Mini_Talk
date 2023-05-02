/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:57:47 by scoskun           #+#    #+#             */
/*   Updated: 2022/03/15 12:43:16 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

void	take_bit(int sig, siginfo_t *info, void *cnt);
void	send_bits(unsigned char c, pid_t pid);
int		ft_atoi(const char *str);
int		ft_printf(const char *str, ...);
void	ctrlc(int sig);
#endif
