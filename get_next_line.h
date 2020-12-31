/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:44:47 by gpaeng            #+#    #+#             */
/*   Updated: 2020/12/31 16:13:22 by gpaeng           ###   ########.fr       */
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
# define FILE_MAX 256
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 12
#endif