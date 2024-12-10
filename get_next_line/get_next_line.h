/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:35 by mfanelli          #+#    #+#             */
/*   Updated: 2024/12/09 17:29:18 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

size_t	ft_strlen(char *str);
char	*ft_copy(char *bois);
char	*ft_substr(char const *s, unsigned int start, char stop_char);
char	*ft_prep(char *next);
char	*ft_backup(char *next, char *buff);
char	*ft_read(char *next, char *buff, int fd);
char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_calloc(size_t count, size_t size);

#endif
