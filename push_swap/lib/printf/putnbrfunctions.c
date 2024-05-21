/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbrfunctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:32:30 by ntalmon           #+#    #+#             */
/*   Updated: 2023/10/27 13:16:22 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_nbr(char c, int *counter)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	(*counter)++;
	return (0);
}

int	ft_putnbr(int n, int *counter)
{
	if (n < 0)
	{
		if (ft_putchar_nbr('-', counter) == -1)
			return (-1);
		if (n == -2147483648)
		{
			if (write(1, "2147483648", 10) == -1)
				return (-1);
			*counter += 10;
			return (0);
		}
		n = -n;
	}
	if (n > 9)
	{
		if (ft_putnbr(n / 10, counter) == -1)
			return (-1);
		n = n % 10;
	}
	if (ft_putchar_nbr(n + 48, counter) == -1)
		return (-1);
	return (0);
}

int	ft_u_putnbr(unsigned int n, int *counter)
{
	if (n > 9)
	{
		if (ft_putnbr(n / 10, counter) == -1)
			return (-1);
		n = n % 10;
	}
	if (ft_putchar_nbr(n + 48, counter) == -1)
		return (-1);
	return (0);
}

int	ft_p_putnbr(unsigned long int ch, int *counter)
{
	char	*base;

	base = "0123456789abcdef";
	if (ch > 15)
	{
		ft_p_putnbr(ch / 16, counter);
		ft_p_putnbr(ch % 16, counter);
	}
	if (ch < 16)
		if (ft_putchar_nbr(base[ch], counter) == -1)
			return (-1);
	return (0);
}
