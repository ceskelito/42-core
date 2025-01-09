/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:51:34 by rceschel          #+#    #+#             */
/*   Updated: 2025/01/09 15:02:40 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substrchr(const char *s, int chr)
{
	char	c;
	int		i;

	i = 0;
	c = (char)chr;
	while (s[i])
	{
		if (s[i] == c)
			return (ft_strdup(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*str;

	str = (char *)malloc(ft_strlen(s) + 1);
	ft_strlcpy(str, (char *)s, ft_strlen(s) + 1);
	return (str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
