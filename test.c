/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:51:19 by ccastro           #+#    #+#             */
/*   Updated: 2024/10/28 16:11:34 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

void	putchar_on_file(char c);
void	putstr_on_file(char *s);
void	read_line(int fd);
void	increment(void);
void	decrement(void);

int	main(void)
{
	decrement();
	decrement();
	increment();
	increment();
}

void	putchar_on_file(char c)
{
	int	fd;

	fd = open("text1.txt", O_RDWR);
	if (fd > 0)
		write(fd, &c, 1);
	else
		write(3, "Error\n", 6);
}

void	putstr_on_file(char *s)
{
	int	fd1;
	
	fd1 = open("text1.txt", O_RDWR);
	printf("the fd1: %d\n", fd1);
	if (fd1 > 0)
		while (*s)
			write(fd1, s++, 1);
	else
		write(2, "Error\n", 6);
	// sleep(30);
}

void	read_line(int fd)
{
	char	buf[1024] = "0";
	
	printf("the fd: %d\n", fd);
	read(fd, &buf, 10);
	printf("the line dawg: %s\n", buf);
}

void	increment(void)
{
	static int	count = 0;
	
	count++;
	printf("increment: %d\n", count);
}

void	decrement(void)
{
	static int	count = 0;

	count--;
	printf("decrement: %d\n", count);
}
