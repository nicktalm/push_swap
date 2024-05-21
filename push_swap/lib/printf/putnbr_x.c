/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:04:50 by ntalmon           #+#    #+#             */
/*   Updated: 2023/10/27 16:35:06 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_bigx_putnbr(unsigned int ch, int *counter)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (ft_putnbr_base(ch, counter, base) == -1)
		return (-1);
	return (0);
}

int	ft_smallx_putnbr(unsigned int ch, int *counter)
{
	char	*base;

	base = "0123456789abcdef";
	if (ft_putnbr_base(ch, counter, base) == -1)
		return (-1);
	return (0);
}

int	ft_putnbr_base(unsigned int ch, int *counter, char *base)
{
	if (ch > 15)
	{
		if (ft_putnbr_base(ch / 16, counter, base) == -1)
			return (-1);
		if (ft_putnbr_base(ch % 16, counter, base) == -1)
			return (-1);
	}
	if (ch < 16)
		if (ft_putchar_nbr(base[ch], counter) == -1)
			return (-1);
	return (0);
}
