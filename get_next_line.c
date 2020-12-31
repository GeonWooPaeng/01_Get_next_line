/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:43:48 by gpaeng            #+#    #+#             */
/*   Updated: 2020/12/31 17:27:21 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
size_t		ft_strlen(const char *str)
{
	size_t idx;

	idx = 0;
	while(str[idx])
	{
		idx++;
	}
	return (idx);
}

char	*ft_strndup(char *str, size_t num)
{
	char	*arr;
	size_t	idx;

	if (!(arr = (char *)malloc(sizeof(char) * (num + 1))))
		return (0);
	idx = 0;
	while (str[idx] && idx < num)
	{
		arr[idx] = str[idx];
		idx++;
	}
	arr[idx] = '\0';
	return (arr);
}

char	*ft_strjoin(const char *a, const char *b)
{
	size_t	alen;
	size_t	blen;
	size_t	idx;
	char	*arr;

	alen = ft_strlen(a);
	blen = ft_strlen(b);
	if (!(arr = (char *)malloc(sizeof(char) * (alen + blen + 1))))
		return (0);
	idx = 0;
	while (idx < alen)
	{
		arr[idx] = a[idx];
		idx++;
	}
	idx = 0;
	while (idx < blen)
	{
		arr[idx + alen] = b[idx];
		idx++;
	}
	arr[alen + blen] = '\0';
	return (arr);
}

char	*ft_strchr(const char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return (0);
}

int		ft_cut_save(char **arr, char **line, int fd)
{
	char	*new_lineptr; // '\n' 전 까지의 개수(한 줄)
	char	*narr; //line에 저장할 array 
	
	new_lineptr = ft_strchr(arr[fd], '\n'); // '\n'이 있는 부분 idx 번호
	if (new_lineptr != 0)
	{
		*line = ft_strndup(arr[fd], new_lineptr - arr[fd]);
		narr = ft_strndup(new_lineptr + 1, ft_strlen(new_lineptr) + 1); 
		free(arr[fd]);
		arr[fd] = narr;
		return (1);
	}
	else
	{
		*line = arr[fd];
		arr[fd] = 0;
		return (0);
	}
}

int		ft_output(char **arr, char **line, int nr, int fd)
{
	if (arr[fd] == 0 || nr == 0)
		return (0);
	else
		return (ft_cut_save(arr, line, fd));
}

int		get_next_line(int fd, char **line)
{
	static char *arr[FILE_MAX]; //한 줄 씩 저장하기 위해서만들어 놓은 곳
	char		*backup;// read로 읽어 온것을 저장하는 곳 strdup으로
	char		buf[BUFFER_SIZE + 1]; //read 읽어오는 곳
	ssize_t		nr; //EOF 전까지 BUFFER_SIZE 만큼 읽어오는 개수 

	if(fd < 1 || BUFFER_SIZE < 1 || !line)
		return (-1);
	while ((nr = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		buf[nr] = '\0';
		if (arr[fd] == 0)
			arr[fd] = ft_strndup(buf, nr);
		else
		{
			backup = ft_strjoin(arr[fd], buf);
			free(arr[fd]);
			arr[fd] = backup;
		}
		if (ft_strchr(arr[fd], '\n') || nr == 0)
			break ;
	}
	if (nr < 0)
		return (-1);
	return (ft_output(arr, line, nr, fd));
	// arr[fd]에서 '\n' 전까지 malloc 만들어서 line에 주소 넣어주기 + arr[fd]주소를 '\n'다음으로 만들어 놓기 
}
