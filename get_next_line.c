/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 05:56:08 by ccastro           #+#    #+#             */
/*   Updated: 2024/12/23 10:57:19 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_clean_line(char *line)
{
    int     i;
    char    *cleaned_line;
    
    i = 0;
	if (line == NULL || *line == '\0')
		return (NULL);
    while (line[i] != '\0' && line[i] != '\n')
        i++;
    cleaned_line = ft_substr(line, 0, i + 1);
    return (cleaned_line);
}

char    *get_dirty_line(char *buf)
{
    int     i;
    char    *dirty_line;

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
	char	*buf;
	int		bytes;
	char	*temp;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
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
	free(buf);
	return (bytes);
}

char	*get_next_line(int fd)
{
	static char	*dirty_line;
    char        *temp;
	char		*clean_line;
	int			bytes;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (dirty_line == NULL)
		dirty_line = NULL;
	bytes = read_line(fd, &dirty_line);
	if (bytes == -1)
		return (free(dirty_line), NULL);
	if (bytes <= 0 && dirty_line == NULL)
		return (free(dirty_line), NULL);
	if (bytes <= 0 && !*dirty_line)
	{
		free(dirty_line);
		dirty_line = NULL;
	}
	clean_line = get_clean_line(dirty_line);
    temp = dirty_line;
	dirty_line = get_dirty_line(dirty_line);
    free(temp);
	return (clean_line);
}

int	main(void)
{
	char	*line = NULL;
	int		fd = open("text.txt", O_RDONLY);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
}