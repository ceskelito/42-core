/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:47:26 by rceschel          #+#    #+#             */
/*   Updated: 2025/01/14 15:42:45 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(fd)
{
	static t_buffer	buff;
	char			*line;
	int				r;

	r = BUFFER_SIZE;
	ft_init_line(&line, &buff);
	if (!line || fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (ft_strchr(line, '\n') || r < BUFFER_SIZE)
			return (line);
		r = read(fd, buff, BUFFER_SIZE);
		if (r < 0)
			return (NULL);
		buff[r] = '\0';
		line = ft_append_buff(&line, buff);
	}
}

void	ft_init_line(char **line, t_buffer *start)
{
	int	i;

	*line = malloc(sizeof(t_buffer));
	if (!(*line))
		return;
	(*line)[0] = '\0';
	ft_strlcpy(*line, *start, BUFFER_SIZE);
	i = 0;
	while(i < BUFFER_SIZE)	
		*start[i++] = '\0';
	*line = ft_append_buff(line, *start);
}

char	*ft_append_buff(char **line, t_buffer buff)
{
	char	*new_line;
	int		i;

	new_line = ft_strjoin(*line, buff);
	if(ft_strchr(new_line, '\n'))
	{
		i = 0;
		while(new_line[i] != '\n')
			i++;
		i++;
		ft_strlcpy(buff, new_line + i, BUFFER_SIZE);
		new_line[i] = '\0';		
	}
	free(*line);
	return (new_line);
}

int	main(void)
{
	int fd = open("file.txt", O_RDONLY);
	char *str;

	int i = 0;
 
	str = get_next_line(fd);
	/*printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str); 
	str = get_next_line(fd);
	printf("%s", str);
	free(str);  */
/* 	while(str)
	{
		
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
		i++;
		
	} */


	close(fd);
}