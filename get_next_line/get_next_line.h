/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:51:38 by rceschel          #+#    #+#             */
/*   Updated: 2025/01/11 19:35:43 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define LAST_CALL 'L'
# include <fcntl.h>		// O_RDONLY
# include <stdio.h>		// FOPEN_MAX
# include <stdlib.h>	// malloc()
# include <unistd.h>	// read()
# include <stdbool.h>

typedef char buffer_t[BUFFER_SIZE + 1 + 2]; // +1 ('\0); +2 (a char after null term. wich set if is last call, and a '\0')

char	*get_next_line(int fd);
bool	ft_init_line(char **line, buffer_t start, int fd);
char	*ft_append_buff(char *line, buffer_t buff, buffer_t *start);

/* utils */
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int chr);
char	*ft_strchrdup(const char *s, int c);
int		ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
#endif