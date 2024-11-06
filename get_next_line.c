/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:05:02 by ccastro           #+#    #+#             */
/*   Updated: 2024/11/06 16:12:18 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_newline(const char *buffer);
char	*extract_line(const char *buffer);
char	*save_remaining(const char *buffer);
char	*get_next_line(int fd);

int	find_newline(const char *buffer)
{
	char	*newline;

	newline = ft_strchr(buffer, '\n');
	if (!newline)
		return (-1);
	return (newline - buffer);
}

char	*extract_line(const char *buffer)
{
	int		i;
	int		newline_pos;
	char	*line;

	i = -1;
	if (!buffer || *buffer == '\0')
		return (NULL);
	newline_pos = find_newline(buffer);
	if (newline_pos == -1)
	{
		line = (char *) malloc(sizeof(char) * (ft_strlen(buffer) + 1));
		if (!line)
			return (NULL);
		while (buffer[++i])
			line[i] = buffer[i];
		line[i] = '\0';
		return (line);
	}
	line = (char *) malloc(sizeof(char) * (newline_pos + 2));
	if (!line)
		return (NULL);
	while (++i <= newline_pos)
		line[i] = buffer[i];
	line[i] = '\0';
	return (line);
}

char	*save_remaining(const char *buffer)
{
	int		i;
	int		newline_pos;
	char	*remaining_data;
	
	i = 0;
	if (!buffer)
		return (NULL);
	newline_pos = find_newline(buffer);
	if (newline_pos == -1)
		return (NULL);
	remaining_data = (char *) malloc(sizeof(char) * (ft_strlen(buffer) - newline_pos));
	if (!remaining_data)
		return (NULL);
	while (buffer[++newline_pos])
		remaining_data[i++] = buffer[newline_pos];
	remaining_data[i] = '\0';
	return (remaining_data);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char	*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read(fd, &buffer, BUFFER_SIZE);
	line = extract_line(buffer);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*buf;

	fd = open("text.txt", O_RDONLY);
	buf = get_next_line(fd);
	printf("%s", buf);
}

/*
	The project will copy a line from a file descriptor.
*/