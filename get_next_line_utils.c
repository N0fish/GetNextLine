/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:42:34 by algultse          #+#    #+#             */
/*   Updated: 2023/11/29 11:05:12 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	len;

	len = 0;
	while (s1[len])
		len++;
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		dst[len] = s1[len];
		len++;
	}
	dst[len] = '\0';
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

void	ft_bzero(void *str, size_t len)
{
	unsigned char	*buf;

	buf = (unsigned char *)str;
	while (len--)
		buf[len] = 0;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_dest;
	char	*p_dest;
	size_t	len;
	
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	s_dest = malloc(sizeof(char) * (len + 1));
	if (!s_dest)
		return (NULL);
	p_dest = s_dest;
	while (*s1)
		*s_dest++ = *s1++;
	while (*s2)
		*s_dest++ = *s2++;
	*s_dest = '\0';
	return (p_dest);
}
