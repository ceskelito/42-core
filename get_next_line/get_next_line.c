/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:47:26 by rceschel          #+#    #+#             */
/*   Updated: 2025/01/18 20:19:48 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_buffer	buff;
	char			*line;
	int				r;

	ft_init_line(&line, buff);
	r = BUFFER_SIZE;
	while (1)
	{
		if (!line || fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
			break;
		if (ft_strchr(line, '\n') || r < BUFFER_SIZE)
			return (line);
		r = read(fd, buff, BUFFER_SIZE);
		if (r <= 0 && !line[0])
			break;
		buff[r] = '\0';
		line = ft_append_buff(line, buff);
	}
	if (line)
		free(line);
	return (NULL);
}

void	ft_init_line(char **line, t_buffer buff)
{
	*line = malloc(sizeof(t_buffer));
	if (!(*line))
		return;
	**line = '\0';
	ft_strlcpy(*line, buff, BUFFER_SIZE);
	*buff = '\0';
	*line = ft_append_buff(*line, buff);
}

char	*ft_append_buff(char *line, t_buffer buff)
{
	char	*new_line;
	int		i;

	new_line = ft_strjoin(line, buff);
	i = 0;
	*buff = '\0';
	if(ft_strchr(new_line, '\n'))
	{
		i = 0;
		while(new_line[i] != '\n')
			i++;
		i++;
		ft_strlcpy(buff, new_line + i, BUFFER_SIZE);
		new_line[i] = '\0';
	}
	free(line);
	return (new_line);
}