/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:48:47 by ntalmon           #+#    #+#             */
/*   Updated: 2023/12/01 16:31:36 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// zwei Zeichenketten (s1 und s2) zu konkatenieren
char	*ft_strjoin(char *s1, char *s2)
{
	char	*con_str;
	int		j;
	int		i;

	j = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	con_str = malloc ((ft_strlen (s1) + ft_strlen (s2) + 1));
	if (con_str == NULL)
		return (NULL);
	while (s1[j] != '\0')
		con_str[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		con_str[i++] = s2[j++];
	con_str[i] = '\0';
	return (con_str);
}
