/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:44:47 by gpaeng            #+#    #+#             */
/*   Updated: 2021/01/01 16:43:38 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
size_t		ft_strlen(const char *str);
char		*ft_strndup(const char *str, size_t num);
char		*ft_strjoin(const char *a, const char *b);
char		*ft_strchr(const char *str, int c);
int			get_next_line(int fd, char **line);
int			ft_output(char **arr, char **line, int nr, int fd);
int			ft_cut_save(char **arr, char **line, int fd);

#ifndef FILE_MAX
# define FILE_MAX 256
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

#endif