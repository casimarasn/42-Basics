/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:48:55 by msedeno-          #+#    #+#             */
/*   Updated: 2025/06/07 21:29:25 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_strdup(char *s1);
size_t	ft_strlen(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_reset_line(char *stash);

#endif