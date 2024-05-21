/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:15:56 by ntalmon           #+#    #+#             */
/*   Updated: 2023/10/24 17:28:03 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Integer to ASCII
static int	ft_count_digit(int n)
{
	int		counter;
	int		numb;

	counter = 0;
	numb = n;
	if (n == 0)
		return (1);
	while (numb != 0)
	{
		numb = numb / 10;
		counter++;
	}
	counter = counter + (n <= 0);
	return (counter);
}

static char	*ft_exist(int n)
{
	char	*newstr;
	int		counter;

	counter = ft_count_digit(n);
	newstr = malloc(sizeof(char) * (counter + 1));
	if (newstr == NULL)
		return (NULL);
	return (newstr);
}

char	*ft_itoa(int n)
{
	char	*newstr;
	int		sign;
	int		counter;

	sign = 1;
	counter = ft_count_digit(n);
	if (n < 0)
		sign = sign * -1;
	newstr = ft_exist(n);
	if (newstr == NULL)
		return (NULL);
	newstr[counter] = '\0';
	while (counter - (sign < 0) > 0)
	{
		counter--;
		newstr[counter] = sign * (char)(n % 10) + '0';
		n = n / 10;
	}
	counter--;
	if (sign < 0)
		newstr[counter] = '-';
	return (newstr);
}
