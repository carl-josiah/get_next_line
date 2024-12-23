/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 05:51:38 by ccastro           #+#    #+#             */
/*   Updated: 2024/12/22 15:18:42 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

char    *get_next_line(int fd);
int     ft_strlen(const char *str);
char    *ft_strdup(const char *str);
char    *ft_strjoin(const char *str1, const char *str2);
char	*ft_substr(char const *s, int start, int len);
char    *ft_strchr(const char *str, int c);

#endif