/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:46:09 by mibernar          #+#    #+#             */
/*   Updated: 2022/01/05 16:07:57 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h> 

// PROTOTYPES

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		find_new_line_temp(char *buffer);
char	*ft_strdup(const char *s1, char *str);
int		ft_strchr(char *temp, int c);
size_t	ft_strlen(char *s);

#endif