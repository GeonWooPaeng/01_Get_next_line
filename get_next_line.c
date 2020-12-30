/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:43:48 by gpaeng            #+#    #+#             */
/*   Updated: 2020/12/30 17:21:51 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
ssize_t		ft_strlen(char *str)
{
	ssize_t idx;

	idx = 0;
	while(str[idx])
	{
		idx++;
	}
	return (idx);
}

char	*ft_strdup(char *str)
{
	char	*arr;
	ssize_t	slen;
	ssize_t idx;

	slen = ft_strlen(str);
	if (!(arr = (char *)malloc(sizeof(char) * (slen + 1))))
		return (0);
	idx = 0;
	while (idx < slen)
	{
		arr[idx] = str[idx];
		idx++;
	}
	arr[idx] = '\0';
	return (arr);
}

char	*ft_strjoin(char *a, char *b)
{
	ssize_t alen;
	ssize_t blen;
	ssize_t	idx;
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

int		ft_strchr(char *str, char c)
{
	ssize_t	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == c)
			return (str[idx]);
		idx++;
	}
	return (0);
}

int		ft_output(char **arr, char **line, int nr, int fd)
{
	if (nr < 0)
		return (-1);
	else if (arr[fd] == '\0' && nr == 0)
		return (0);
	// else
	// 	return ();
}

int		get_next_line(int fd, char **line)
{
	static char *arr[FILE_MAX]; //한 줄 씩 저장하기 위해서만들어 놓은 곳
	char		*backup;// read로 읽어 온것을 저장하는 곳 strdup으로
	char		buf[BUFFER_SIZE + 1]; //read 읽어오는 곳
	ssize_t		nr; //EOF 전까지 BUFFER_SIZE 만큼 읽어오는 개수 

	if(fd < 1 || BUFFER_SIZE < 1 || !line)
		return (-1);
	while ((nr = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[nr] = '\0';
		if (arr[fd] == NULL)
			arr[fd] = ft_strdup(buf);
		else
		{
			backup = ft_strjoin(arr[fd], buf);
			free(arr[fd]);
			arr[fd] = backup;
		}
		if (ft_strchr(arr[fd], '\n'))
			break ;
	}
	return (ft_output(arr, line, nr, fd));
	// arr[fd]에서 '\n' 전까지 malloc 만들어서 line에 주소 넣어주기 + arr[fd]주소를 '\n'다음으로 만들어 놓기 
}
