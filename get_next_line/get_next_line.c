/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:47:26 by rceschel          #+#    #+#             */
/*   Updated: 2025/01/15 14:55:32 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(fd)
{
	static t_buffer	buff;
	char			*line;
	int				r;


	ft_init_line(&line, &buff);
	line = ft_append_buff(&line, buff);
	if (!line || fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	r = BUFFER_SIZE;
	while (1)
	{
		if (ft_strchr(line, '\n') || r < BUFFER_SIZE)
			return (line);
		r = read(fd, buff, BUFFER_SIZE);
		if (r <= 0)
			return (NULL);
		buff[r] = '\0';
		line = ft_append_buff(&line, buff);
	}
}

void	ft_init_line(char **line, t_buffer *buff)
{
	int		i;
	char	*tmp;
	
	*line = malloc(sizeof(t_buffer));
	if (!(*line))
		return;
	(*line)[0] = '\0';
	ft_strlcpy(*line, *buff, BUFFER_SIZE);
	i = 0;
	while(i < BUFFER_SIZE)	
		buff[0][i++] = '\0';
}

char	*ft_append_buff(char **line, t_buffer buff)
{
	char	*new_line;
	//char	*tmp;
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