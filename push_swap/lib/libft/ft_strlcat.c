/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:01:56 by ntalmon           #+#    #+#             */
/*   Updated: 2023/10/24 18:47:55 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// eine Quell-Zeichenkette (src) an das Ende (dest) anzuhängen
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	dest_length;
	unsigned int	src_length;
	unsigned int	s_left;
	unsigned int	a;

	if (size == 0)
		return (ft_strlen(src));
	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	if (size <= dest_length)
	{
		return (size + src_length);
	}
	s_left = size - dest_length - 1;
	a = 0;
	while (a < s_left && src[a] != '\0')
	{
		dest[dest_length + a] = src[a];
		a++;
	}
	dest[dest_length + a] = '\0';
	return (dest_length + src_length);
}
