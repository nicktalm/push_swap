/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:58:12 by ntalmon           #+#    #+#             */
/*   Updated: 2023/10/24 17:38:49 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// in gegebenen Speicherbereich nach bestimmten Zeichen c zu suchen
void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)s;
	i = 0;
	while (n != 0)
	{
		if (ptr[i] == (char)c)
			return ((void *)ptr + i);
		i++;
		n--;
	}
	return (NULL);
}
