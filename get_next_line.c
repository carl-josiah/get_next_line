/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:05:02 by ccastro           #+#    #+#             */
/*   Updated: 2024/10/30 18:42:04 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*connect_line(const char *buffer);
char	*read_line(int fd, const char *buffer);
char	*get_next_line(int fd);

// char	*connect_line(const char *buffer)
// {
	
// }

// char	*read_line(int fd, const char *buffer)
// {	
// 	read(fd, &buffer, BUFFER_SIZE);
// 	return (buffer);
// }

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	int	read_chars;
	
	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	read_chars = 1;
	while (read_chars > 0)
	{
		read_chars = read(fd, &buffer, 1);
		write(1, &buffer, read_chars);
		if (buffer[0] == '\n')
			break ;
	}
	// buffer[read_chars] = '\0';
	return (buffer);
}

int	main(void)
{
	int		fd;
	char	*buf;

	fd = open("text.txt", O_RDONLY);
	buf = get_next_line(fd);
	printf("%s\n", buf);
}

/*
	The project will copy a line from a file descriptor.
*/