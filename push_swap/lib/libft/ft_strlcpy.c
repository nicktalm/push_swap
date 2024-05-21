/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:23:26 by ntalmon           #+#    #+#             */
/*   Updated: 2023/10/24 18:49:09 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// (src) in (dest) zu kopieren, size berücksichtigen
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;

	src_len = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src_len < size - 1 && src[src_len] != '\0')
	{
		dest[src_len] = src[src_len];
		src_len++;
	}
	dest[src_len] = '\0';
	while (src[src_len] != '\0')
		src_len++;
	return (src_len);
}
