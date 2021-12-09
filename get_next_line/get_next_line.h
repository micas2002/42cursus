/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:11:10 by mibernar          #+#    #+#             */
/*   Updated: 2021/12/09 13:07:30 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h> 

// PROTOTYPES

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
int		find_new_line_temp(char *buffer);
char	*ft_strdup(const char *s1, char *str);
size_t	ft_strlen(const char *s);

#endif