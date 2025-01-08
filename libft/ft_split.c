/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:33:35 by ablabib           #+#    #+#             */
/*   Updated: 2024/11/03 18:12:46 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stddef.h>
#include <stdlib.h>
#include <stddef.h>

static size_t	_ft_c_ws(char const *str, char c)
{
	size_t	i;
	size_t	w;

	w = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			w++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (w);
}

static void	*_ft_free_words(char **strs, size_t i)
{
	while (i--)
		free(strs[i]);
	free(strs);
	return (NULL);
}

static void	_ft_skip(int not, char const *s, size_t *i, char c)
{
	if (not)
		while (*(s + *i) && *(s + *i) != c)
			(*i)++;
	else
		while (*(s + *i) && *(s + *i) == c)
			(*i)++;
	return ;
}

static char	**_get_splited(char const *s, char c, char **strings)
{
	char	*word;
	char	*start;
	size_t	i;
	size_t	w_i;

	i = 0;
	w_i = 0;
	while (*(s + i))
	{
		_ft_skip(0, s, &i, c);
		if (*(s + i))
		{
			start = (char *)(s + i);
			_ft_skip(1, s, &i, c);
			word = ft_substr(s, start - s, (s + i) - start);
			if (!word)
				return (_ft_free_words(strings, w_i));
			strings[w_i++] = word;
		}
	}
	strings[w_i] = 0;
	return (strings);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;

	if (!s)
		return (NULL);
	strings = (char **)malloc(sizeof(char *) * (_ft_c_ws(s, c) + 1));
	if (!strings)
		return (NULL);
	return (_get_splited(s, c, strings));
}
// static int	count_words(char const *s, char c)
// {
// 	size_t	counter;
// 	size_t	i;
// 	int		flag;

// 	flag = 1;
// 	i = 0;
// 	counter = 0;
// 	while (s[i])
// 	{
// 		if (s[i] != c && flag)
// 		{
// 			counter++;
// 			flag = 0;
// 		}
// 		else if (s[i] == c)
// 			flag = 1;
// 		i++;
// 	}
// 	return (counter);
// }

// static int	free_allocate(char **ptr, int pos)
// {
// 	while (pos--)
// 	{
// 		free(ptr[pos]);
// 	}	
// 	free(ptr);
// 	return (1);
// }

// static int	get_next_word(char **ptr, char *s, char c, int i)
// {
// 	int	len;
// 	int	j;

// 	len = 0;
// 	while (s[len] != c && s[len])
// 		len++;
// 	if (len == 0)
// 		return (0);
// 	ptr[i] = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!ptr[i])
// 		return (-1);
// 	j = 0;
// 	while (j < len)
// 	{
// 		ptr[i][j] = s[j];
// 		j++;
// 	}
// 	ptr[i][j] = '\0';
// 	return (len);
// }

// static int	allocate_words(char **ptr, char *s, char c)
// {
// 	unsigned int	i;
// 	int			result;

// 	i = 0;
// 	while (*s)
// 	{
// 		while (*s == c && *s)
// 			s++;
// 		result = get_next_word(ptr, s, c, i);
// 		if (result == -1)
// 			return (free_allocate(ptr, i));
// 		if (result > 0)
// 		{
// 			i++;
// 			s += result;
// 		}
// 	}
// 	ptr[i] = NULL;
// 	return (0);
// }

// char	**ft_split(char const *s, char c)
// {
// 	size_t	words;
// 	char	**ptr;

// 	if (!s)
// 		return (NULL);
// 	words = count_words(s, c);
// 	ptr = (char **)malloc(sizeof(char *) * (words + 1));
// 	if (!ptr)
// 		return (NULL);
// 	// ptr[words] = NULL;
// 	if (allocate_words(ptr, (char *)s, c))
// 		return (NULL);
// 	return (ptr);
// }