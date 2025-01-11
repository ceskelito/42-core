/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:09:15 by rceschel          #+#    #+#             */
/*   Updated: 2025/01/11 19:35:43 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static buffer_t		start;
	buffer_t			buff;
	char				*line;
	int 				r;

	if(start[BUFFER_SIZE + 1] == LAST_CALL)
		return (NULL);
	if(!ft_init_line(&line, start, fd))
		return (NULL);
	while(1)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if(r < 0)
			return (NULL);
		buff[r] = '\0';
		if(r < BUFFER_SIZE || ft_strchr(buff, '\n'))
			break;
		line = ft_append_buff(line, buff, NULL);
	}
	if(r < BUFFER_SIZE)
		start[BUFFER_SIZE + 1] = LAST_CALL;
	return(ft_append_buff(line, buff, &start));
}

bool	ft_init_line(char **line, buffer_t start, int fd)
{
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (false);
	(*line) = malloc(sizeof(buffer_t));
	(*line)[BUFFER_SIZE] = '\0';
	if(!(*line))
		return (false);
	ft_strlcpy(*line, start, BUFFER_SIZE);
	return (true);
}

char	*ft_append_buff(char *line, buffer_t buff, buffer_t *start)

{
	int		size;
	char	*p;
	char	*line_temp;

	size = ft_strlen(line);
	line_temp = malloc((size + BUFFER_SIZE + 1) * sizeof(char));
	ft_strlcpy(line_temp, line, size + BUFFER_SIZE + 1);
	if (!line_temp)
		return (NULL);
	ft_strlcpy(line_temp + size, buff, BUFFER_SIZE + 1);
	p = ft_strchrdup(line_temp, '\n');
	if (p)
	{
		ft_strlcpy(*start, p + 1, BUFFER_SIZE);
		size = 0;
		while (line_temp[size])
			if (line_temp[size++] == '\n')
				line_temp[size] = '\0';
		free(p);
		p = NULL;
	}
	free(line);
	line = NULL;
	return (line_temp);
}

/* int	main(void)
{
	int fd = open("file.txt", O_RDONLY);
	char *str;

	while(str)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}
	
	close(fd);
} */