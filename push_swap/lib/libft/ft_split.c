/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:33:30 by ntalmon           #+#    #+#             */
/*   Updated: 2023/11/28 10:05:15 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_counter(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			counter++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (counter);
}

static size_t	ft_ends_of_subs(char const *s, char c, size_t start)
{
	if (ft_strchr(s + start, c) == NULL)
		return (ft_strlen(&s[start]));
	else
		return (ft_strchr(s + start, c) - &s[start]);
}

static char	**ft_buffer_free(char **buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != NULL)
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	size_t	i;
	size_t	start;

	i = 0;
	start = 0;
	if (s == NULL)
		return (NULL);
	buffer = malloc((ft_word_counter(s, c) + 1) * sizeof(char *));
	if (buffer == NULL)
		return (NULL);
	while (s[start] != '\0')
	{
		while (s[start] == c)
			start++;
		if (s[start] == '\0')
			break ;
		buffer[i] = (ft_substr(s, start, ft_ends_of_subs(s, c, start)));
		if (buffer[i] == NULL)
			return (ft_buffer_free(buffer));
		i++;
		start += ft_ends_of_subs(s, c, start);
	}
	buffer[i] = NULL;
	return (buffer);
}
