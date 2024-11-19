/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:53:26 by ccastro           #+#    #+#             */
/*   Updated: 2024/11/19 18:41:23 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	newline(const char *buffer)
{
	char	*newline;

	newline = ft_strchr(buffer, '\n');
	if (!newline)
		return (-1);
	return (newline - buffer);
}

char	*extract(const char *buffer)
{
	int		i;
	int		nl_pos;
	char	*line;

	i = -1;
	if (!buffer || !*buffer)
		return (NULL);
	nl_pos = newline(buffer);
	if (nl_pos == -1)
	{
		line = (char *) malloc(sizeof(char) * (ft_strlen(buffer) + 1));
		nl_pos = ft_strlen(buffer);
	}
	else
		line = (char *) malloc(sizeof(char) * nl_pos + 1);
	if (!line)
		return (NULL);
	while (++i < nl_pos)
		line[i] = buffer[i];
	line[i] = '\0';
	return (line);
}

char	*remaining(const char *buffer)
{
	int		i;
	int		nl_pos;
	char	*remaining;

	i = 0;
	if (!buffer || !*buffer)
		return (NULL);
	nl_pos = newline(buffer);
	if (nl_pos == -1)
		return (NULL);
	remaining = (char *) malloc(sizeof(char) * (ft_strlen(buffer) - nl_pos));
	if (!remaining)
		return (NULL);
	while (buffer[++nl_pos])
		remaining[i++] = buffer[nl_pos];
	remaining[i] = '\0';
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		temp[BUFFER_SIZE + 1];
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	bytes = 1;
	while ((!buffer || newline(buffer) == -1) && bytes > 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		// printf("TEMP = %s\n", temp);
		if (bytes > 0)
		{
			temp[bytes] = '\0';
			// printf("TEMP before = %s\n\n\n\n", temp);
			buffer = ft_strjoin(buffer, temp);
			// printf("BUFFER = %s\n", buffer);
		}
		if (bytes < 0)
			return (NULL);
	}
	if (!buffer || !*buffer)
		return (NULL);
	//printf("BUFFER = %s\n", buffer);
	line = extract(buffer);
	buffer = remaining(buffer);
	return (line);
}

int	main(void) // free buffer somewhere, fix the indexing
{
	int		fd;
	char	*line;

	fd = open("tests/test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	// ft_strjoin("hello ", "world");
	return 0;
}

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	fd1 = open("tests/test.txt", O_RDONLY);
// 	fd2 = open("tests/test2.txt", O_RDONLY);
// 	fd3 = open("tests/test3.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 7)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd3);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }