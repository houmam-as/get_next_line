/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 08:45:55 by hait-sal          #+#    #+#             */
/*   Updated: 2022/12/28 15:40:51 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	if ((char)c == 0)
	{
		return (str + ft_strlen(str));
	}
	while (*str != '\0')
	{
		if ((unsigned char)*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (NULL);
}

int	nl_check(char *s)
{
	int	start;

	start = 0;
	while (1)
	{
		if ((s[start] == '\n') || (s[start] == '\0'))
			return (++start);
		start++;
	}
	return (0);
}

char	*nl_sv(int fd, char *bfr, char *str)
{
	int	rd;

	rd = 1;
	while (rd)
	{
		rd = read(fd, bfr, BUFFER_SIZE);
		if (rd == -1)
		{
			free(bfr);
			free(str);
			str = 0;
			return (0);
		}
		bfr[rd] = '\0';
		str = ft_strjoin(str, bfr);
		if (ft_strchr(bfr, '\n') || rd == 0)
		{
			free(bfr);
			break ;
		}
	}
	return (str);
}

char	*freesd(char **next_line, char **str)
{
	free(*next_line);
	free(*str);
	*str = 0;
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*str;
	char		*save;
	char		*next_line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	str = nl_sv(fd, buffer, str);
	if (!str)
		return (0);
	i = nl_check(str);
	next_line = ft_substr(str, 0, i);
	if (!*next_line)
		return (freesd(&next_line, &str));
	save = ft_substr(str, i, ft_strlen(str) - i);
	free(str);
	str = save;
	return (next_line);
}
