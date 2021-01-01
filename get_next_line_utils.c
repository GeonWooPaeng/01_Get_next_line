/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 14:26:58 by gpaeng            #+#    #+#             */
/*   Updated: 2021/01/01 17:01:05 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t idx;

	idx = 0;
	while(*str++)
	{
		idx++;
	}
	return (idx);
}

char	*ft_strndup(const char *str, size_t num)
{
	char	*arr;
	size_t	idx;

	if (!(arr = (char *)malloc(sizeof(char) * (num + 1))))
		return (0);
	idx = 0;
	while (*str && idx < num)
	{
		arr[idx] = *str;
		idx++;
		str++;
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
	while (a[idx] && idx < alen)
	{
		arr[idx] = a[idx];
		idx++;
	}
	idx = 0;
	while (b[idx] && idx < blen)
	{
		arr[idx + alen] = b[idx];
		idx++;
	}
	arr[alen + blen] = '\0';
	return (arr);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return (0);
}
