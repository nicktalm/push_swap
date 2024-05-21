/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:34:04 by ntalmon           #+#    #+#             */
/*   Updated: 2023/12/05 16:33:49 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_pf(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr(char *s, int *counter)
{
	size_t	size;

	if (s == NULL)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		*counter = *counter + 6;
		return (0);
	}
	size = ft_strlen_pf(s);
	if (write (1, s, size) == -1)
		return (-1);
	*counter = *counter + size;
	return (0);
}

int	ft_putchar(char c)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	return (0);
}
