#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>

#	ifndef BUFFER_SIZE
# 		define BUFFER_SIZE 42
#	endif

// ft_free
void ft_free(char **str)
{
	int i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
	}
}
// ft_strlen
size_t ft_strlen(const char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}
// ft_strchr
char *ft_strchr(const char *s, int c)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			break ;
		i++;
	}
	return ((char *)&s[i]);
}
// ft_strdup
char *ft_strdup(const char *s1)
{
	int i = 0;
	char *str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
// ft_substr
char *ft_substr(char *s, unsigned int start, size_t len)
{
	int j = 0;
	char *str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while ( s[start] && start < len)
	{
		str[j] = s[start];
		start++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
// ft_strjoin
char *ft_strjoin(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	char *str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
// ft_split
char *ft_split(char **buffer)
{
	char *line;
	char *excess_chars;
	int i = 0;

	while (buffer[0][i] != '\n' && buffer[0][i] != '\0')
		i++;
	line = ft_substr(*buffer, 0, i + 1);
	excess_chars = ft_substr(*buffer, i + 1, ft_strlen(*buffer));
	ft_free(buffer);
	*buffer = ft_strdup(excess_chars);
	ft_free(&excess_chars);
	if (!ft_strchr(line, '\n') && !ft_strlen(line))
	{
		ft_free(&line);
	}
	if (!ft_strchr(line, '\n'))
	{
		ft_free(buffer);
	}
	return (line);
}

void ft_concat(char **line, char **chunk)
{
	char *tmp;
	if (!(*line))
		*line = ft_strjoin("", *chunk);
	else
	{
		tmp = ft_strjoin(*line, *chunk);
		// ft_free(line);
		*line = tmp;
	}
}
// get_next_line
char *get_next_ln(int fd)
{
	char *chunk;
	int buffer_sz;
	static char *line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	chunk = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buffer_sz = read(fd, chunk, BUFFER_SIZE);
	if (!chunk || buffer_sz < 0)
		return (ft_free(&chunk), NULL);
	while (buffer_sz > 0)
	{
		chunk[buffer_sz] = '\0';
		ft_concat(&line, &chunk);
		if (ft_strchr(line, '\n'))
			break;
		buffer_sz = read(fd, chunk, BUFFER_SIZE);
	}
	return (ft_free(&chunk), ft_split(&line));
}
// main

int main(void)
{
	// char *ptr;

	// ptr = "";

	// // printf("%d", (int)ft_strlen(ptr));
	// // printf("%s\n", ft_strchr("drey\nwesson", '\n'));
	// // printf("%s\n", ptr = ft_strdup("dreywesson"));
	// // printf("%s\n", ptr = ft_substr("dreywesson", 0, 4));
	// printf("%s\n", ptr = ft_strjoin("drey", "wesson"));
	// // printf("%d", (int)ft_strlen(ptr));
	int fd;
	int i = 0;
	char *line;

	fd = open("text1", O_RDONLY);
	if (fd < 0)
		printf("Bad read\n");
	while (i < 2)
	{
		line = get_next_ln(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	return (0);
}