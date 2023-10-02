#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif
size_t ft_strlen(const char *s)
{
    int i = -1;
    while (s[++i]);
    return (i);
}

void ft_free(char **str)
{
    int i = 0;
    while (str[i])
    {
        free(str[i]);
        str[i] = NULL;
    }
}

char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            break;
        s++;
    }
    return ((char *)s);
}

char *ft_strdup(const char *s1)
{
    char *str;
    int i = 0;
    int len = ft_strlen(s1);

    str = (char *)malloc(sizeof(char) * (len + 1));
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

char *ft_substr(char *s, unsigned int start, size_t len)
{
    char *str;
    int i = 0;

    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    while (start < len)
        str[i++] = s[start++];
    str[i] = '\0';
    return (str);
}

char *ft_strjoin(const char *s1, const char *s2)
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

char	*ft_split(char	**buffer)
{
	char	*line;
	char	*excess_chars;
	int		i;

	i = 0;
	if (!buffer[0])
		return (NULL);
	while (buffer[0][i] != '\n' && buffer[0][i] != '\0')
		i++;
	line = ft_substr(buffer[0], 0, i + 1);
	excess_chars = ft_substr(buffer[0], i + 1, ft_strlen(buffer[0]));
	ft_free(buffer);
	buffer[0] = ft_strdup(excess_chars);
	ft_free(&excess_chars);
	if (!ft_strchr(line, '\n') && !ft_strlen(line))
		ft_free(&line);
	if (!ft_strchr(line, '\n'))
		ft_free(buffer);
	return (line);
}

// int main()
// {
//     static char *str = "drey\nwesson";
//     // ft_strlen("drey\n");
//     // printf("%s\n", ft_strdup("drey\n"));
//     // printf("%s\n", ft_substr("dreywesson", 0, 4));
//     // printf("%s\n", ft_strjoin("drey", "wesson"));
//     printf("%s\n", ft_split(&str));
//     return (0);
// }

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

char	*get_next_line(int fd)
{
	static char	*line;
	char		*chunk;
	int			size;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	chunk = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	size = read(fd, chunk, BUFFER_SIZE);
	if (size == -1 || !chunk)
		ft_free(&chunk);
	while (size > 0) 
	{
		chunk[size] = '\0';
		ft_concat_chunks(&line, &chunk); 
		if (ft_strchr(line, '\n'))
			break ;
		size = read(fd, chunk, BUFFER_SIZE);
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