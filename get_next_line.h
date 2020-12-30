/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:44:47 by gpaeng            #+#    #+#             */
/*   Updated: 2020/12/30 15:54:11 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
int	get_next_line(int fd, char **line);
#endif

#ifndef FILE_MAX
# define FILE_MAX 32
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif