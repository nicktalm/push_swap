/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:47:50 by ntalmon           #+#    #+#             */
/*   Updated: 2023/12/04 12:53:06 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// in s nach dem ersten Auftreten von c zu suchen
char	*ft_strchr(const char *s, int c)
{
	int		len;

	len = 0;
	while (s[len] != (char)c)
	{
		if (s[len] == '\0')
			return (0);
		len++;
	}
	return ((char *)s + len);
}
