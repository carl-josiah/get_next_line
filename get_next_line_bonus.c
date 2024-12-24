/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 00:22:41 by ccastro           #+#    #+#             */
/*   Updated: 2024/12/25 03:29:46 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_clean_line(char *line)
{
	int		i;
	char	*cleaned_line;

	i = 0;
	if (line == NULL || *line == '\0')
		return (NULL);
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	cleaned_line = ft_substr(line, 0, i + 1);
	return (cleaned_line);
}

char	*get_dirty_line(char *buf)
{
	int		i;
	char	*dirty_line;

	i = 0;
	if (buf == NULL || *buf == '\0')
		return (NULL);
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	dirty_line = ft_substr(buf, i + 1, ft_strlen(buf));
	return (dirty_line);
}

int	read_line(int fd, char **dirty_line)
{
	int		bytes;
	char	*buf;
	char	*temp;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (-1);
	bytes = 1;
	while (ft_strchr(*dirty_line, '\n') == NULL && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buf), -1);
		if (bytes == 0)
			break ;
		buf[bytes] = '\0';
		temp = *dirty_line;
		*dirty_line = ft_strjoin(*dirty_line, buf);
		free(temp);
	}
	return (free(buf), bytes);
}

char	*get_next_line(int fd)
{
	int				bytes;
	static char		*line[1024];
	char			*clean_line;
	char			*temp;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = read_line(fd, &line[fd]);
	if (bytes <= 0 && line[fd] == NULL)
		return (NULL);
	clean_line = get_clean_line(line[fd]);
	temp = line[fd];
	line[fd] = get_dirty_line(line[fd]);
	return (free(temp), clean_line);
}

// int	main(void)
// {
// 	int fd1 = open("tests/text1.txt", O_RDONLY);
// 	int fd2 = open("tests/text2.txt", O_RDONLY);
// 	int fd3 = open("tests/text3.txt", O_RDONLY);
// 	char *line1 = get_next_line(fd1);
// 	char *line2 = get_next_line(fd2);
// 	char *line3 = get_next_line(fd3);

// 	printf("%s", line1);
// 	free(line1);
// 	while (line1)
// 	{
// 		line1 = get_next_line(fd1);
// 		printf("%s", line1);
// 		free(line1);
// 	}
// 	close(fd1);
// 	printf("\n||||||||||||||||||||||||||||||||||||\n");
// 	printf("%s", line2);
// 	free(line2);
// 	while (line2)
// 	{
// 		line2 = get_next_line(fd2);
// 		printf("%s", line2);
// 		free(line2);
// 	}
// 	close(fd2);
// 	printf("\n||||||||||||||||||||||||||||||||||||\n");
// 	printf("%s", line3);
// 	free(line3);
// 	while (line3)
// 	{
// 		line3 = get_next_line(fd3);
// 		printf("%s", line3);
// 		free(line3);
// 	}
// 	close(fd3);
// }