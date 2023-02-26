/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:07:47 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/25 20:55:56 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*jeofree(char *stash, char *temp)
{
	char	*buff;

	buff = ft_strjoin(stash, temp);
	free(stash);
	return (buff);
}

static char	*copy_to_stash(int fd, char *stash)
{
	char	*temp;
	int		read_char;

	if (!stash)
		stash = ft_calloc(1, 1);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_char = 1;
	while (read_char > 0)
	{
		read_char = read(fd, temp, BUFFER_SIZE);
		if (read_char == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[read_char] = 0;
		stash = jeofree(stash, temp);
		if (new_line(temp, '\n'))
			break ;
	}
	free(temp);
	return (stash);
}

static char	*create_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	return (line);
}

static char	*what_next(char *stash)
{
	char	*rest;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	rest = ft_calloc(ft_strlen(stash)- i + 1, sizeof(char));
	i++;
	while (stash[i])
		rest[n++] = stash[i++];
	rest[n] = 0;
	free(stash);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*stash[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stash[FOPEN_MAX] = copy_to_stash(fd, stash[FOPEN_MAX]);
	if (!stash[FOPEN_MAX])
		return (NULL);
	line = create_line(stash[FOPEN_MAX]);
	stash[FOPEN_MAX] = what_next(stash[FOPEN_MAX]);
	return (line);
}

// static int	verify_new_line(char **stack, char **line)
// {
// 	char		*tmp_stack;
// 	char		*strchr_stack;
// 	int			i;

// 	i = 0;
// 	strchr_stack = *stack;
// 	while (strchr_stack[i] != '\n')
// 	{
// 		if (!strchr_stack[i++])
// 			return (0);
// 	}
// 	tmp_stack = &strchr_stack[i];
// 	*tmp_stack = '\0';
// 	*line = *stack;
// 	*stack = ft_strdup(tmp_stack + 1);
// 	return (1);
// }

// static void	add_heap_to_static(char **s, char *buf)
// {
// 	char		*tmp;

// 	tmp = *s;
// 	if (!tmp)
// 		*s = ft_strdup(buf);
// 	else
// 	{
// 		*s = ft_strjoin(tmp, buf);
// 		free(tmp);
// 		tmp = NULL;
// 	}
// }

// static	int	ft_exit(char **line)
// {
// 	*line = NULL;
// 	return (0);
// }

// int	get_next_line(const int fd, char **line)
// {
// 	static char	*s[MAX_FD];
// 	char		heap[BUFF_SIZE + 1];
// 	int			ret;

// 	if (!line || fd < 0 || fd >= MAX_FD || (read(fd, s[fd], 0) < 0))
// 		return (-1);
// 	ret = read(fd, heap, BUFF_SIZE);
// 	while (ret > 0)
// 	{
// 		heap[ret] = '\0';
// 		add_heap_to_static(&s[fd], heap);
// 		if (verify_new_line(&s[fd], line))
// 			return (1);
// 		ret = read(fd, heap, BUFF_SIZE);
// 	}
// 	if (!s[fd] || s[fd][0] == '\0')
// 		return (ft_exit(line));
// 	if (s[fd])
// 		if (verify_new_line(&(s[fd]), line))
// 			return (1);
// 	*line = ft_strdup(s[fd]);
// 	free(s[fd]);
// 	s[fd] = NULL;
// 	return (1);
// }