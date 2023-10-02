/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 07:59:31 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/02 13:14:57 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "./get_next_line.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// ***** UTILS ******
void	ft_free(char	**str)
{
	int i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int i)
{
	while (*s)
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (i == '\0')
		return ((char *)s);
	return (0);
}

// ***** HELPER ******
char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * (j + 1));
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (str == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

// ***** MAIN ******
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_split(char	**str)
{
	char	*line;
	char	*excess_chars;
	int		i;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[0][i] != '\n' && str[0][i] != '\0')
		i++;
	line = ft_substr(str[0], 0, i + 1);
	excess_chars = ft_substr(str[0], i + 1, ft_strlen(str[0]));
	ft_free(str);
	str[0] = ft_strdup(excess_chars);
	ft_free(&excess_chars);
	if (!ft_strchr(line, '\n') && !ft_strlen(line))
		ft_free(&line);
	if (!ft_strchr(line, '\n'))
		ft_free(str);
	return (line);
}



void	ft_concat_chunks(char	**line, char	**chunk)
{
	char	*tmp;

	if (!(*line)) 
		*line = ft_strjoin("", *chunk);
	else
	{
		tmp = ft_strjoin(*line, *chunk);
		ft_free(line);
		*line = tmp;
	}
}

// allocate memory for the buffer size
// we need to know the num of char read bcos sometimes chunk may read 
// 	char beyond \n or even not for example EOF
// while u still have char to read continue reading
// null terminate every chunk
// concat remaining char after newline with the new chunk in the buffer
//  use strchr to check if u have \n in the line
char	*get_next_line(int fd)
{
	static char	*line;
	char		*chunk;
	int			chunk_size;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	chunk = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	chunk_size = read(fd, chunk, BUFFER_SIZE);
	if (chunk_size == -1 || !chunk)
		ft_free(&chunk);
	while (chunk_size > 0) 
	{
		chunk[chunk_size] = '\0';
		ft_concat_chunks(&line, &chunk); 
		if (ft_strchr(line, '\n'))
			break ;
		chunk_size = read(fd, chunk, BUFFER_SIZE);
	}
	return (ft_free(&chunk), ft_split(&line));
}

int main()
{
    int fd;
    int i;
    int j;
    char *line;
	
	j = -1;
	i = -1;
	fd = open("text1", O_RDONLY);
	if (fd < 0)
		printf("bad read\n");
	while (++i < 3)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
    return (0);
}