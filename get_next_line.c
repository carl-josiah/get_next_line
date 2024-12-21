/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 05:56:08 by ccastro           #+#    #+#             */
/*   Updated: 2024/12/22 01:46:42 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// char *line = NULL;

// modifies the buffer that has a newline.
// BUFFER_SIZE = 5; text.txt = hello\nchumps\0; line = "\nchum" <-- modifies this line
// output: '\n'
char *get_clean_line(char *line)
{
    int     i;
    char    *cleaned_line;

    i = 0;
    while (line[i] != '\0' && line[i] != '\n')
        i++;
    cleaned_line = ft_substr(line, 0, i + 1);
    return (cleaned_line);
}

// takes the chars that remained in the buffer
// after taking everything before and including the '\n'
// BUFFER_SIZE = 5; text.txt = hello\nchumps\0; buf = "\nchum" <-- modifies this line
// output: "chum"
// to start at the line 
char    *get_dirty_line(char *buf)
{
    int     i;
    char    *dirty_line;

    i = 0;
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
	if (!buf)
		return (-1);
	bytes = 1;
	while (bytes != 0 && !ft_strchr(*dirty_line, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		buf[bytes] = '\0';
		temp = *dirty_line;
		*dirty_line = ft_strjoin(*dirty_line, buf);
		free(temp);
	}
	if (bytes < 0)
		return (free(buf), -1);
	return (free(buf), bytes);
}

char	*get_next_line(int fd)
{
	static char	*dirty_line;
	char		*clean_line;
    char        *temp;
	int			bytes;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = read_line(fd, &dirty_line);
	if (bytes <= 0)
	{
		free(dirty_line);
		dirty_line = NULL;
		return (NULL);
	}
	clean_line = get_clean_line(dirty_line);
    temp = dirty_line;
	dirty_line = get_dirty_line(dirty_line);
    free(temp);
	return (clean_line);
}

// int main(void)
// {
//     int fd1 = open("text.txt", O_RDONLY);
//     // int fd2 = open("iloveyouihateyou.txt", O_RDONLY);

//     char    *line;

//     line = NULL;
//     while ((line = get_next_line(fd1)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }
//     free(line);
//     close(fd1);
// }
