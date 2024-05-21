/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whattoprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:10:34 by ntalmon           #+#    #+#             */
/*   Updated: 2023/10/27 16:35:06 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	what_to_print1(va_list	ptr, int *counter, char print)
{
	char				*output;
	int					error;

	error = 0;
	if (print == 'c')
	{
		error = ft_putchar((char)va_arg(ptr, int));
		(*counter)++;
	}
	else if (print == 's')
	{
		output = va_arg(ptr, char *);
		error = ft_putstr(output, counter);
	}
	else if (print == '%')
	{
		error = ft_putchar('%');
		(*counter)++;
	}
	return (error);
}

int	what_to_print2(va_list	ptr, int *counter, char print)
{
	int	output;
	int	error;

	error = 0;
	if (print == 'd' || print == 'i')
	{
		output = va_arg(ptr, int);
		error = ft_putnbr(output, counter);
	}
	else if (print == 'x')
	{
		output = va_arg(ptr, unsigned int);
		error = ft_smallx_putnbr(output, counter);
	}
	else if (print == 'X')
	{
		output = va_arg(ptr, unsigned int);
		error = ft_bigx_putnbr(output, counter);
	}
	else if (print == 'u')
	{
		output = va_arg(ptr, unsigned int);
		error = ft_u_putnbr(output, counter);
	}
	return (error);
}

int	what_to_print3(va_list	ptr, int *counter, char print)
{
	unsigned long int	output;
	int					error;

	error = 0;
	if (print == 'p')
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		*counter = *counter + 2;
		output = va_arg(ptr, unsigned long int);
		error = ft_p_putnbr(output, counter);
	}
	return (error);
}
