/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:05:11 by ccastro           #+#    #+#             */
/*   Updated: 2024/10/29 16:14:45 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# define BUFFER_SIZE 1024

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);

#endif
