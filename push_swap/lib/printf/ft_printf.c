/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:41:42 by ntalmon           #+#    #+#             */
/*   Updated: 2023/11/28 10:36:47 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *print, ...)
{
	va_list	ptr;
	int		i;
	int		c;

	c = 0;
	i = 0;
	va_start(ptr, print);
	while (print[i] != '\0')
	{
		if (print[i] == '%')
		{
			i++;
			if (flag_check(ptr, &c, print[i]) == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(print[i]) == -1)
				return (-1);
			c++;
		}
		i++;
	}
	va_end(ptr);
	return (c);
}

int	flag_check(va_list ptr, int *c, char print)
{
	if (what_to_print1(ptr, c, print) == -1)
		return (-1);
	if (what_to_print2(ptr, c, print) == -1)
		return (-1);
	if (what_to_print3(ptr, c, print) == -1)
		return (-1);
	return (0);
}
