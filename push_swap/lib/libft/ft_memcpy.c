/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:45:30 by ntalmon           #+#    #+#             */
/*   Updated: 2023/10/24 17:40:20 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// dient dazu n Bytes von src in dest zu kopieren
void	*ft_memcpy(void *dest, const void *src, int n)
{
	char		*char_dest;
	const char	*char_src;
	int			i;

	char_dest = (char *) dest;
	char_src = (char *) src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (dest);
}
