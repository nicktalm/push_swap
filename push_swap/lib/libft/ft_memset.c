/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:41:39 by ntalmon           #+#    #+#             */
/*   Updated: 2023/10/24 17:42:15 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// einen Speicherbereich mit einem bestimmten Wert zu füllen
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	value;

	p = (unsigned char *)b;
	value = (unsigned char) c;
	while (len != 0)
	{
		*p = value;
		len --;
		p ++;
	}
	return (b);
}
