/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 08:46:10 by hait-sal          #+#    #+#             */
/*   Updated: 2022/12/27 17:21:27 by hait-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*destination;
	char	*source;
	size_t	i;
	int		c;
	int		m;

	destination = (char *)dst;
	source = (char *)src;
	i = 0;
	c = (int) i;
	m = (int) n;
	c = 0;
	if (destination == (void *)0 && source == (void *)0)
		return (NULL);
	while (c < m)
	{
		*destination = *source;
		destination++;
		source++;
		c++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*destination;
	char	*source;

	destination = (char *)dst;
	source = (char *)src;
	if (!destination && !source)
		return (NULL);
	if (dst > src)
	{
		while (len)
		{
			len--;
			destination[len] = source[len];
		}
	}
	else
	{
		ft_memcpy(destination, source, len);
		return (destination);
	}
	return (destination);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	slen1;
	size_t	slen2;

	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	p = malloc(slen1 + slen2 + 1);
	if (!p)
		return (NULL);
	ft_memmove(p, s1, slen1);
	ft_memmove(p + slen1, s2, slen2 + 1);
	free((void *)s1);
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*p;
	char		*v;
	long long	y;

	if (start >= ft_strlen(s))
	{
		v = malloc (sizeof(0));
		*v = 0;
		return (v);
	}
	y = len;
	if (len > ft_strlen(s))
		y = ft_strlen(s) - start;
	p = malloc ((y + 1) * sizeof(char));
	if (!p)
		return (NULL);
	ft_memmove(p, s + start, y);
	*(p + y) = 0;
	return (p);
}
