#include "get_next_line.h"

char	*save_remaining(const char *buffer)
{
	int		i;
	int		newline_pos;
	char	*remaining_data;
	
	i = 0;
	if (!buffer || !*buffer)
		return (NULL);
	newline_pos = find_newline(buffer);
	if (newline_pos == -1)
		return (NULL);
	remaining_data = (char *) malloc(sizeof(char) * (ft_strlen(buffer) - newline_pos));
	if (!remaining_data)
		return (NULL);
	while (buffer[++newline_pos]) // pre-increment to start copying after the newline (\n)
		remaining_data[i++] = buffer[newline_pos];
	remaining_data[i] = '\0';
	return (remaining_data);
}

int	main(void)
{
	printf("%d\n", find_newline("hello\n"));
	printf("%d\n", find_newline2("hello\n"));
}