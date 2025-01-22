/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:38:01 by vlow              #+#    #+#             */
/*   Updated: 2024/12/08 14:57:51 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static char	*valid_nl(char **buffer, char **load, char *nl_ptr);
static char	*load_line(int fd, char **buffer);
static char	*set_line(char **buffer, char **load, ssize_t size);
static int	nl_check(char **buffer, char **load);

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*valid;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = ft_strdup("");
		if (!buffer[fd])
			return (NULL);
	}
	valid = NULL;
	if (nl_check(&buffer[fd], &valid))
		return (valid);
	valid = load_line(fd, &buffer[fd]);
	if (!valid)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	return (valid);
}

static char	*load_line(int fd, char **buffer)
{
	char	*load;
	ssize_t	size;

	load = malloc(BUFFER_SIZE + 1);
	if (!load)
		return (NULL);
	while (1)
	{
		size = read(fd, load, BUFFER_SIZE);
		if (size == -1)
		{
			free(load);
			return (NULL);
		}
		load[size] = '\0';
		if (size == 0)
		{
			load = set_line(buffer, &load, size);
			return (load);
		}
		if (nl_check(buffer, &load))
			return (load);
		*buffer = set_line(buffer, &load, 1);
	}
}

static int	nl_check(char **buffer, char **load)
{
	char	*nl_ptr;

	if (!(*load) && *buffer)
	{
		nl_ptr = ft_strchr(*buffer, '\n');
		if (nl_ptr && *nl_ptr == '\n')
		{
			*load = ft_strdup(*buffer);
			free(*buffer);
			*buffer = ft_strdup("");
			nl_ptr = ft_strchr(*load, '\n');
			*load = valid_nl(buffer, load, nl_ptr);
			return (1);
		}
	}
	else if (*buffer && *load)
	{
		nl_ptr = ft_strchr(*load, '\n');
		if (nl_ptr && *nl_ptr == '\n')
		{
			*load = valid_nl(buffer, load, nl_ptr);
			return (1);
		}
	}
	return (0);
}

static char	*valid_nl(char **buffer, char **load, char *nl_ptr)
{
	char	*temp;
	char	*subs;

	subs = malloc((nl_ptr - *load) + 2);
	if (!subs)
		return (NULL);
	ft_strlcpy(subs, *load, (nl_ptr - *load) + 2);
	temp = set_line(buffer, &subs, 1);
	free(subs);
	*buffer = ft_strdup(nl_ptr + 1);
	free(*load);
	return (temp);
}

static char	*set_line(char **buffer, char **load, ssize_t size)
{
	char	*temp;

	if (size == 0)
	{
		if (!buffer || !(*buffer) || !(**buffer))
		{
			free(*load);
			return (NULL);
		}
		free(*load);
		temp = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
		return (temp);
	}
	temp = ft_strjoin(*buffer, *load);
	free(*buffer);
	return (temp);
}
//
// #include <fcntl.h>
// #include <stdio.h>
// int main(void)
// {
// 	int fd = open("alternate_line_nl_with_nl", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	// int fd = -1;
//
//     char *line;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("{%s}", line);
// 		free(line);
// 	}
// 	printf("{EOL: %s}", line);
// 	free(line);
//
// 	// get_next_line(fd);
// 	// get_next_line(fd);
//     close(fd);
// 	return (0);
// }
