/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:23:59 by prossi            #+#    #+#             */
/*   Updated: 2023/10/01 18:47:07 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

//#include <stdlib.h> and <unistd.h> for *malloc(), free(), & read()*.

char* ft_substr(char const* s, unsigned int start, size_t len);
int		ft_strlen(const char* str);
char* ft_strchr(const char* s, int i);
char* ft_strdup(const char* s);
char* ft_strjoin(char const* s1, char const* s2);
char* get_next_line(int fd);

#endif
