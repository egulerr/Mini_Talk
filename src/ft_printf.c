/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:35:56 by scoskun           #+#    #+#             */
/*   Updated: 2022/02/22 23:30:29 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nbr)
{
	char	a;
	int		len;
	long	nbr2;

	nbr2 = nbr;
	len = 0;
	if (nbr2 < 0)
	{
		nbr2 *= -1;
		write(1, "-", 1);
	}
	if (nbr2 >= 0 && nbr2 <= 9)
	{
		a = nbr2 + 48;
		write(1, &a, 1);
		return (len);
	}
	else
		ft_putnbr(nbr2 / 10);
	ft_putnbr(nbr2 % 10);
	return (len);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == (char *) NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (str)
	{
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	return (i);
}

int	formats(va_list ap, const char *arg)
{
	int	print_len;

	print_len = 0;
	if (*arg == 'c')
		print_len += ft_putchar(va_arg(ap, int));
	else if (*arg == 's')
		print_len += ft_putstr(va_arg(ap, char *));
	else if (*arg == 'd' || *arg == 'i')
		print_len += ft_putnbr(va_arg(ap, int));
	return (print_len);
}

int	ft_printf(const char *args, ...)
{
	va_list	ap;
	int		printlen;
	int		i;

	i = 0;
	printlen = 0;
	va_start(ap, args);
	while (args[i])
	{
		if (args[i] == '%')
		{
			i++;
			if (args[i] == '\0')
				return (0);
			printlen += formats(ap, &args[i]);
		}
		else
			printlen += ft_putchar(args[i]);
		i++;
	}
	va_end(ap);
	return (printlen);
}
