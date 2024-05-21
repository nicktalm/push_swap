/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:16:57 by ntalmon           #+#    #+#             */
/*   Updated: 2023/10/24 18:40:55 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// eine Kopie einer Zeichenkette (String) src zu erstellen
char	*ft_strdup(const char *src)
{
	char	*str_copy;
	int		i;

	i = 0;
	str_copy = (char *)malloc(ft_strlen(src)+ 1);
	if (str_copy == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		str_copy[i] = src[i];
		i++;
	}
	str_copy[i] = '\0';
	return (str_copy);
}
