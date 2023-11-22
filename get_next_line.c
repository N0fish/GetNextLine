/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:42:24 by algultse          #+#    #+#             */
/*   Updated: 2023/11/22 10:42:32 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*remainder;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = NULL;
	if (*buf)
	{
		
	}
	
	while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0) {
		printf("[%.*s]", (int)bytes_read, buf);
    }
	return ("");
}

void test(int jj)
{
	static int i;
	
	if (!jj) {
		printf("!jj, ");
		i = 0;
	} else {
		printf("i++, ");
		i++;
	}
	printf("i = %d\n", i);
}

#include <fcntl.h>
int	main()
{
// {	char	*str = "hello\n";
	// int	fd = open("./test.txt", O_CREAT | O_RDONLY, 0777);
	// char	buf[100];
	// printf("read [%zd]\n", read(fd, buf, sizeof(buf)));
	// get_next_line(fd);
	test(0);
	test(1);
	test(1);
	test(1);
	return (0);
}
