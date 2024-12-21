/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 05:57:05 by ccastro           #+#    #+#             */
/*   Updated: 2024/12/22 01:42:21 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int  ft_strlen(const char *str)
{
    int  i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char    *ft_strdup(const char *str)
{
    int  i;
    char    *ret;

    if (str == NULL)
        return (NULL);
    i = 0;
    ret = malloc(sizeof(char) * (ft_strlen(str) + 1));
    if (ret == NULL)
        return (NULL);
    while (str[i] != '\0')
    {
        ret[i] = str[i];
        i++;
    }
    ret[i] = '\0';
    return (ret);
}

char    *ft_strjoin(const char *str1, const char *str2)
{
    int     i;
    int     j;
    char    *ret;

    if (str1 == NULL && str2 == NULL)
        return (ft_strdup(""));
    if (str1 == NULL)
        return (ft_strdup(str2));
    if (str2 == NULL)
        return (ft_strdup(str1));
    i = 0;
    j = 0;
    ret = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
    if (ret == NULL)
        return (NULL);
    while (str1[i] != '\0')
    {
        ret[i] = str1[i];
        i++;
    }
    while (str2[j] != '\0')
        ret[i++] = str2[j++];
    ret[i] = '\0';
    return (ret);
}

char    *ft_strchr(const char *str, int c)
{
    int     i;
    char    cc;

    i = 0;
    cc = (char) c;
    if (str == NULL)
        return (NULL);
    while (str[i] != '\0')
    {
        if (str[i] == cc)
            return ((char *) &str[i]);
        i++;
    }
    if (str[i] == cc)
        return ((char *) &str[i]);
    return (NULL);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = (ft_strlen(s + start));
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (len--)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

#include <string.h>

// int main(void)
// {
//     char str1[16] = "condition";
//     char str2[16] = "condition";
//     memcpy(str1, str1 + 2, 3);
//     printf("%s\n", str1);
//     memmove(str2, str2 + 2, 3);
//     printf("%s\n", str2);
// }