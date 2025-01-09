/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:51:28 by rceschel          #+#    #+#             */
/*   Updated: 2025/01/09 15:09:21 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_create_buffer(int fd);
char	*ft_create_line(char *temp_line, char *buff, char (*line)[BUFFER_SIZE]);

char	*get_next_line(int fd)
{
	static char	line[BUFFER_SIZE];
	char		*temp_line;
	char		*buff;
	int			r;

	temp_line = malloc(sizeof(char) * BUFFER_SIZE);
	*temp_line = '\0';
	ft_strlcpy(temp_line, line, BUFFER_SIZE);
	buff = ft_create_buffer(fd);
	if (!buff)
		return (NULL);
	while (1)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r < 0)
			return (NULL);
		buff[r] = '\0';
		if (r < BUFFER_SIZE || ft_substrchr(buff, '\n'))
			break ;
		temp_line = ft_create_line(temp_line, buff, &line);
	}
	return (ft_create_line(temp_line, buff, &line));
}

char	*ft_create_line(char *temp_line, char *buff, char (*line)[BUFFER_SIZE])

{
	int		size;
	char	*p;
	char	*new_line;

	size = ft_strlen(temp_line) + 1;
	new_line = malloc(sizeof(char) * (size + BUFFER_SIZE));
	if (!new_line)
		return (NULL);
	ft_strlcpy(new_line, temp_line, size);
	ft_strlcpy(new_line + size - 1, buff, BUFFER_SIZE + 1);
	p = ft_substrchr(new_line, '\n');
	if (p)
	{
		ft_strlcpy(*line, p + 1, ft_strlen(p));
		size = 0;
		while (new_line[size])
			if (new_line[size++] == '\n')
				new_line[size] = '\0';
	}
	return (new_line);
}

char	*ft_create_buffer(int fd)
{
	char	*new;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	return (new);
}

/* int	main(void)
{
	int fd = open("file.txt", O_RDONLY);
	char *str;

	for (int i = 0; i < 2; i++)
	{
		str = get_next_line(fd);
		printf("%s", str);
	}

	close(fd);
} */