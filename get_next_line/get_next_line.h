/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:51:38 by rceschel          #+#    #+#             */
/*   Updated: 2025/01/14 15:42:46 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <fcntl.h>		// O_RDONLY
# include <stdio.h>		// FOPEN_MAX
# include <stdlib.h>	// malloc()
# include <unistd.h>	// read()
# include <stdbool.h>

typedef char t_buffer[BUFFER_SIZE + 1];

char	*get_next_line(int fd);
char	*ft_append_buff(char **line, t_buffer buff);
void	ft_init_line(char **line, t_buffer *start);

/* utils */
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char 	*ft_strchr(const char *s, int chr);
int		ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif