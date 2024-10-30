/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:05:02 by ccastro           #+#    #+#             */
/*   Updated: 2024/10/29 16:16:39 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd) // the main function takes a file descriptor and returns the string or (null)
{
	char		buffer[BUFFER_SIZE];
	char static	saved_data;
	char		*line;
	ssize_t		bytes_read;
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