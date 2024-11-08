#include "get_next_line.h"

// int	main(void)
// {
// 	int	fd;
// 	int	num_of_read;
// 	char	buf[1024];

// 	fd = open("text.txt", O_RDWR);
// 	num_of_read = read(-2, &buf, 1);
// 	printf("%d\n", num_of_read);
// }

// int	main(void)
// {
// 	int	fd;

// 	fd = open("text.txt", O_RDONLY);
// 	read_line()
// }

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

int	main(void)
{
	int		fd;
	char	buffer[BUFFER_SIZE];

	fd = open("text.txt", O_RDONLY);
	read(fd, &buffer, BUFFER_SIZE);
	printf("extract_line: {%s}", extract_line(buffer));
	printf("save_remaining: {%s}", save_remaining(buffer));
}
