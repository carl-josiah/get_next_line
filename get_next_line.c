/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 05:56:08 by ccastro           #+#    #+#             */
/*   Updated: 2024/12/19 17:45:01 by ccastro          ###   ########.fr       */
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

char    *get_next_line(int fd)
{
    int             bytes;
    char            *buf;
    char static     *dirty_line;
    char            *clean_line;

    buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (buf == NULL)
        return (NULL);
    if (dirty_line == NULL)
        dirty_line = NULL;
    bytes = 1;
    buf[0] = '\0';
    while (ft_strchr(buf, '\n') == NULL && bytes != 0)
    {
        bytes = read(fd, buf, BUFFER_SIZE);
        buf[bytes] = '\0';
        dirty_line = ft_strjoin(dirty_line, buf);
    }
    if (bytes == 0)
        return (free(buf), free(dirty_line), NULL);
    if (bytes == -1)
        return (free(buf), free(dirty_line), NULL);
    clean_line = get_clean_line(dirty_line);
    dirty_line = get_dirty_line(buf);
    return (free(buf), clean_line);
}

int main(void)
{
    int fd1 = open("text.txt", O_RDONLY);
    
    char *line;
    
    line = get_next_line(fd1);
    free(line);
    // printf("%s", line);
    // line2 = get_next_line(fd2);
    // printf("%s", line2);
    // line = get_next_line(fd1);
    // printf("%s", line);
    // while (line != NULL)
    // {
    //     line = get_next_line(fd1);
    //     printf("%s", line);
    // }
    //     free(line);

    // char *test;

    // test = updated_line("Hell\no");
    // printf("%s", test);
}
