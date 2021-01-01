/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 15:09:17 by gpaeng            #+#    #+#             */
/*   Updated: 2021/01/01 21:42:58 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int ft_make_arr(char **arr, char *buf, ssize_t nr)
{
    char *backup;
    
    buf[nr] = '\0';
    if (*arr == NULL)
    {
        backup = ft_strndup(buf, nr);
		*arr = backup;
    }
    else
    {
        backup = ft_strjoin(*arr, buf);
        free(*arr);
		*arr = backup;
    }
    if (ft_strchr(*arr, '\n'))
        return (1);
    return (0);
}

char *ft_make_line(char **arr, int *check)
{
    char *new_lineptr;
    char *backup;
	char *tmp;

    new_lineptr = ft_strchr(*arr, '\n');
    if (new_lineptr)
    {
        *check = 1;
    	backup = ft_strndup(*arr, new_lineptr - *arr);
        tmp = ft_strndup(new_lineptr + 1, ft_strlen(new_lineptr + 1));
        free(*arr);
		*arr = tmp;
        return (backup);
    }
    else
    {
		*check = 0;
        return (*arr);
    }
}

int	get_next_line(int fd, char **line)
{
   	static char *arr[FILE_MAX]; //한 줄 씩 저장하기 위해서만들어 놓은 곳
	char		buf[BUFFER_SIZE + 1]; //read 읽어오는 곳
	ssize_t		nr; //EOF 전까지 BUFFER_SIZE 만큼 읽어오는 개수 
    int			check;

    if (!line || BUFFER_SIZE < 1 || fd < 0 || fd > FILE_MAX)
        return (-1);
    while ((nr = read(fd, buf, BUFFER_SIZE)) >= 0)
    {
        if (nr < 0)
            return (-1);
        if (ft_make_arr(&arr[fd], buf, nr) || nr == 0)
            break ;
    }
	*line = ft_make_line(&arr[fd], &check);
    if (!check)
    {
        arr[fd] = 0;
        return (0);
    }
    return (1);
}


// int main()
// {
//     int		fd;		
//     char	*line;
	
// 	if ((fd = open("./test.txt", O_RDONLY)) == -1)
// 	{
// 		write(1, "Error\n", 6);
// 		return (0);
// 	}
// 	while (get_next_line2(fd, &line) > 0)
// 	{
// 		printf("line >> %s\n", line);
// 		free(line);
// 	}
// 	printf("line >> %s\n", line);
// 	free(line);
// 	return (0);
// }
