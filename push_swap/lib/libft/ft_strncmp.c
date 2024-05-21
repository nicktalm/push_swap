/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:45:42 by ntalmon           #+#    #+#             */
/*   Updated: 2023/10/24 18:53:16 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Vergleich von s1 und s2 bis n
int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	size_t	a;

	a = 0;
	while (n > 0 && (s1[a] != '\0' || s2[a] != '\0'))
	{
		if ((unsigned char)s1[a] != (unsigned char)s2[a])
		{
			return ((unsigned char)s1[a] - (unsigned char)s2[a]);
		}
		a++;
		n--;
	}
	return (0);
}
