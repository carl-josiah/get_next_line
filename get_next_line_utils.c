/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:53:27 by ccastro           #+#    #+#             */
/*   Updated: 2024/11/19 21:59:20 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;
	char	*s3;

	if (!s1 && !s2)
		return (NULL);
	i = -1 + (!s1);
	j = -1 + (!s2);
	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	s3 = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
	if (!s3)
		return (NULL);
	while (s1 && s1[++i])
		s3[i] = s1[i];
	while (s2 && s2[++j])
		s3[i + j] = s2[j];
	s3[i + j] = '\0';
	// printf("%s\n", s3);
	return (s3);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s || !*s)
		return (NULL);
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if (*s == (char) c)
		return ((char *) s);
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;
	size_t			i;

	pdst = (unsigned char *) dst;
	psrc = (unsigned char *) src;
	i = -1;
	if (pdst == NULL && psrc == NULL)
		return (NULL);
	while (++i < n)
		pdst[i] = psrc[i];
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *) dst;
	s = (char *) src;
	if (d == NULL && s == NULL)
		return (NULL);
	if (dst > src)
	{
		while (len--)
			d[len] = s[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
