/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:58:13 by gpaeng            #+#    #+#             */
/*   Updated: 2021/01/01 23:54:19 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
    int		fd;		
    char	*line;
	
	if ((fd = open("./test.txt", O_RDONLY)) == -1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		printf("line >> %s\n", line);
		free(line);
	}
	printf("line >> %s\n", line);
	free(line);
	return (0);
}


// int main()
// {
// 	int fd = open("./test.txt", O_RDONLY);
// 	printf("%d\n",fd);
// 	int fs = open("./test.txt", O_RDONLY);
// 	printf("%d\n",fs);
// 	int fk = open("./test.txt", O_RDONLY);
// 	printf("%d\n",fk);
// 	printf("%d",FILE_MAX);
// }