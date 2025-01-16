/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:52:20 by ablabib           #+#    #+#             */
/*   Updated: 2024/10/27 16:16:50 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stddef.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == src)
		return (NULL);
	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*((unsigned char *)(dest + i)) = *((unsigned char *)(src + i));
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start || len > s_len)
		len = s_len - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s + start, len);
	ptr[len] = '\0';
	if (error_syntax(ptr))
	{
		free(ptr);
		return (NULL);
	}
	else
		return (ptr);
}
