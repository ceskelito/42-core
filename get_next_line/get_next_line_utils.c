/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:51:34 by rceschel          #+#    #+#             */
/*   Updated: 2025/01/15 14:53:36 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char    *ft_strchr(const char *s, int c)
{
    char    cc;

    cc = (char) c;
    while (*s)
    {
        if (*s == cc)
            return ((char *)s);
        s++;
    }
    if (cc == '\0')
        return ((char *)s);
    return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*str;

	str = (char *)malloc(ft_strlen(s) + 1);
	if(!str)
		return (NULL);
	ft_strlcpy(str, (char *)s, ft_strlen(s) + 1);
	return (str);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return ("");
		//return (malloc(sizeof(char)));
	if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc((len1 + len2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str +  0  , s1, len1 + 1);
	ft_strlcpy(str + len1, s2, len2 + 1);
	return (str);
}
